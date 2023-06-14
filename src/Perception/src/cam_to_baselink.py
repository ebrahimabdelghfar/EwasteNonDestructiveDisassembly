import sys
sys.path.append("../../control/src/")
from robot_helper import RobotControl, frames_transformations
import numpy as np
import tf.transformations


def cam_to_world_position(x,y,z,verbose=False):
    framesTransformer= frames_transformations()
    static_frame=frames_transformations.put_frame_static_frame(parent_frame_name='camera_link',child_frame_name="static")
    relative_transformations=framesTransformer.transform(parent_id="base_link",child_frame_id='static')#chid id might be wrong
    # apply transformations and rotations wrt robot
    translation=relative_transformations[:3]
    
    #translation=[relative_transformations.position.x,relative_transformations.position.y,relative_transformations.position.z]
    #rotation=[relative_transformations.orientation.x,relative_transformations.orientation.y,relative_transformations.orientation.z,relative_transformations.orientation.w]
    rotation=relative_transformations[3:]
    cam_matrix=np.array([x,y,z,1])
    #print('quanterions are:')
    #print(tf.transformations.euler_from_quaternion(rotation))
    homogeneous_matrix=tf.transformations.compose_matrix(translate=translation,angles=rotation)
    #print('homo mat is ')
    print(homogeneous_matrix)
    worldpose=np.matmul(homogeneous_matrix,cam_matrix)
    #print('worldpose is::::')
    #print(worldpose)
    return worldpose