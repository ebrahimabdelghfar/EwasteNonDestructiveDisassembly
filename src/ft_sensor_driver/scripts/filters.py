from threading import Thread
from queue import Queue
import rospy
import numpy as np
from geometry_msgs.msg import WrenchStamped, Wrench
from geometry_msgs.msg import PointStamped
from std_msgs.msg import Float64
from scipy.signal import butter, sosfilt, sosfilt_zi, savgol_filter, cheby2
import scipy.linalg as linalg
from collections import deque
from ros_numpy import numpify
import matplotlib.pyplot as plt
from copy import deepcopy
from collections import deque
import pandas as pd
from math import sqrt
from numpy.fft import fft, fftfreq



def fft_func(input_data, sample_rate):
    yf = fft(input_data)
    N = len(yf)
    T = 1.0 / sample_rate
    xf = fftfreq(N, T)[:N//2]
    y = 2.0/N * np.abs(yf[0:N//2])
    return xf, y

def fft_func_2(input_data, sample_rate):
    yf = fft(input_data)
    N = len(yf)
    T = 1.0 / sample_rate
    xf = fftfreq(N, T)[:N//2]
    y = 2.0/N * np.abs(yf[0:N//2])
    return xf, y
    
def anti_diagonal(X):
    """Averages the anti-diagonals of the given elementary matrix, X_i, and returns a time series."""
    # Reverse the column ordering of X_i
    X_rev = X[::-1]
    # Full credit to Mark Tolonen at https://stackoverflow.com/a/6313414 for this one:
    return np.array([X_rev.diagonal(i).mean() for i in range(-X.shape[0]+1, X.shape[1])])

def ssa(data, L, d, approximating_components):
    '''Approximates a given time series using Singular Spectrum Analysis (SSA).
    Keyword arguments:
    data: np.ndarray -- original time series
    L: int -- window length (as defined in the reference paper)
    d: int -- number of factors to use for the series reconstruction
    (as defined in the reference paper)
    approximating_components: Sequence[int] -- indices of the components for
    computing the series approximation'''
    N = data.shape[0]
    K = N - L + 1
    # 1. create the trajectory matrix.
    X = linalg.hankel(data)[:L, :K]
    # We can also set d to be the rank of X
    dr = np.linalg.matrix_rank(X)
    d = dr
    #
    # 2. calculate SVD of S Matrix.
    U, s, VT = linalg.svd(X)
    # 3. calculate the elementary
    X_elem = np.array([s[i] * np.outer(U[:,i], VT[i,:]) for i in range(0,d)] )
    if not np.allclose(X, X_elem.sum(axis=0), atol=1e-3):
        print ("choose bigger d")
    # 3. grouping: here we choose the group to be the first three elementary matrices
    G = np.sum(X_elem[approximating_components, :, :], axis=0)
    # 4. Diagonal averaging
    reconstructed_signal = anti_diagonal(G)
    return reconstructed_signal


def butter_lowpass_filter(data, cutoff, fs, z, order):
    nyq = 0.5 * fs
    normal_cutoff = cutoff / nyq
    # Get the filter coefficients
    sos = butter(order, normal_cutoff, btype='low',
                    analog=False, output='sos')
    if z is None:
        z = sosfilt_zi(sos)
    y, zf = sosfilt(sos, data, zi=z)
    return y, zf

def cheby2_lowpass_filter(data, cutoff, fs, z, order, rs):
    nyq = 0.5 * fs
    normal_cutoff = cutoff / nyq
    # Get the filter coefficients
    sos = cheby2(order, rs, normal_cutoff, btype='low',
                    analog=False, output='sos')
    if z is None:
        z = sosfilt_zi(sos)
    y, zf = sosfilt(sos, data, zi=z)
    return y, zf

def butter_bandstop_filter(data, cutoff_l, cutoff_h, fs, z, order):
    nyq = 0.5 * fs
    cutoff = np.array([cutoff_l, cutoff_h])
    normal_cutoff = cutoff / nyq
    # Get the filter coefficients
    sos = butter(order, normal_cutoff, btype='bandstop',
                    analog=False, output='sos')
    if z is None:
        z = sosfilt_zi(sos)
    y, zf = sosfilt(sos, data, zi=z)
    return y, zf

def butter_bandpass_filter(data, cutoff_l, cutoff_h, fs, z, order):
    nyq = 0.5 * fs
    cutoff = np.array([cutoff_l, cutoff_h])
    normal_cutoff = cutoff / nyq
    # Get the filter coefficients
    sos = butter(order, normal_cutoff, btype='bandpass',
                    analog=False, output='sos')
    if z is None:
        z = sosfilt_zi(sos)
    y, zf = sosfilt(sos, data, zi=z)
    return y, zf

def ewma_filter(q_arr, span):
    ewma = pd.Series.ewm
    df = pd.Series(q_arr)
    fwd = ewma(df,span=span).mean()
    bwd = ewma(df[::-1],span=span).mean()
    filtered = np.vstack(( fwd, bwd[::-1] ))
    filtered = np.mean(filtered, axis=0)
    return filtered[0]


def ewma_vectorized(data, alpha, offset=None, dtype=None, order='C', out=None):
    """
    Calculates the exponential moving average over a vector.
    Will fail for large inputs.
    :param data: Input data
    :param alpha: scalar float in range (0,1)
        The alpha parameter for the moving average.
    :param offset: optional
        The offset for the moving average, scalar. Defaults to data[0].
    :param dtype: optional
        Data type used for calculations. Defaults to float64 unless
        data.dtype is float32, then it will use float32.
    :param order: {'C', 'F', 'A'}, optional
        Order to use when flattening the data. Defaults to 'C'.
    :param out: ndarray, or None, optional
        A location into which the result is stored. If provided, it must have
        the same shape as the input. If not provided or `None`,
        a freshly-allocated array is returned.
    """
    data = np.array(data, copy=False)

    if dtype is None:
        if data.dtype == np.float32:
            dtype = np.float32
        else:
            dtype = np.float64
    else:
        dtype = np.dtype(dtype)

    if data.ndim > 1:
        # flatten input
        data = data.flatten()


    if out is None:
        out = np.empty_like(data, dtype=dtype)
    else:
        assert out.shape == data.shape
        assert out.dtype == dtype

    if data.size < 1:
        # empty input, return empty array
        return out

    if offset is None:
        offset = data[0]

    alpha = np.array(alpha, copy=False).astype(dtype, copy=False)

    # scaling_factors -> 0 as len(data) gets large
    # this leads to divide-by-zeros below
    scaling_factors = np.power(1. - alpha, np.arange(data.size + 1, dtype=dtype),
                               dtype=dtype)
    # create cumulative sum array
    np.multiply(data, (alpha * scaling_factors[-2]) / scaling_factors[:-1],
                dtype=dtype, out=out)
    np.cumsum(out, dtype=dtype, out=out)

    # cumsums / scaling
    out /= scaling_factors[-2::-1]

    if offset != 0:
        offset = np.array(offset, copy=False).astype(dtype, copy=False)
        # add offsets
        out += offset * scaling_factors[1:]

    return out

def numpy_ewma_vectorized_v2(data, window):
    alpha = 2.0/(window + 1)
    alpha_rev = 1-alpha
    n = data.shape[0]

    pows = alpha_rev**(np.arange(n+1))

    scale_arr = 1/pows[:-1]
    offset = data[0]*pows[1:]
    pw0 = alpha*alpha_rev**(n-1)

    mult = data*pw0*scale_arr
    cumsums = mult.cumsum()
    out = offset + cumsums*scale_arr[::-1]
    # mean = np.mean(out)
    return out[-1]

# def window_rms(a, window_size):
    
#   a2 = np.power(a,2)
#   window = np.ones(window_size)/float(window_size)
#   return np.sqrt(np.convolve(a2, window, 'valid'))[-1]

def savgol_filter_rt(data, window_size, order=2, mode='nearest'):
    y = savgol_filter(data, window_size, order, mode=mode)
    return y

