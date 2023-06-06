from src.control.src.robot_helper import RobotControl, frames_transformations
import numpy as np
import tf.transformations


def cam_to_world_position(x,y,z,verbose=False):
    framesTransformer= frames_transformations()
    # framesTransformer.put_frame_static_frame('base_link','camera_link',[0.5,0,0.73,0,0,0])
    relative_transformations=framesTransformer.transform(parent_id="base_link",child_frame_id='camera_link')#chid id might be wrong
    # apply transformations and rotations wrt robot
    translation=[relative_transformations.position.x,relative_transformations.position.y,relative_transformations.position.z]
    rotation=[relative_transformations.orientation.x,relative_transformations.orientation.y,relative_transformations.orientation.z,relative_transformations.orientation.w]
    cam_mat=np.array([x,y,z,1])
    print('quanterions are:')
    print(tf.transformations.euler_from_quaternion(rotation))
    homogeneous_matrix=tf.transformations.compose_matrix(translate=translation,angles=tf.transformations.euler_from_quaternion(rotation))
    print('homo mat is ')
    print(homogeneous_matrix)
    worldpose=np.matmul(homogeneous_matrix,cam_mat)
    print('worldpose is::::')
    print(worldpose)
    return worldpose