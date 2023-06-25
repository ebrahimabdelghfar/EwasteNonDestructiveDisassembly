#!/usr/bin/env python

import rospy
from sensor_msgs.msg import PointCloud2
import sensor_msgs.point_cloud2 as pc2
import pcl
from octomap_msgs.msg import Octomap
# from octomap_msgs.msg import OctomapStamped
from octomap_msgs.srv import GetOctomap
from std_msgs.msg import Header
from visualization_msgs.msg import MarkerArray
from visualization_msgs.msg import Marker

# Callback function for receiving the point cloud data
def point_cloud_callback(msg):
    # Convert the PointCloud2 message to a pcl PointCloud object
    cloud = pcl.PointCloud()
    points = []
    for p in pc2.read_points(msg, skip_nans=True):
        points.append([p[0], p[1], p[2]])
    cloud.from_list(points)

    # Create an OctoMap object
    tree = pcl.octree.OctreePointCloud()
    tree.setInputCloud(cloud)
    tree.addPointsFromInputCloud()

    # Publish the OctoMap
    octomap_msg = Octomap()
    octomap_msg.header = Header()
    octomap_msg.header.stamp = rospy.Time.now()
    octomap_msg.header.frame_id = 'map'
    octomap_msg.octomap.header = octomap_msg.header
    octomap_msg.octomap.binary = True
    octomap_msg.octomap.id = 1
    octomap_msg.octomap.resolution = 0.1  # Set the desired resolution of the OctoMap

    # Get the OctoMap data as a string and assign it to the OctoMap message
    octomap_msg.octomap.data = tree.getOctomapBinary()

    # Publish the OctoMap
    octomap_pub.publish(octomap_msg)

    # Publish the MarkerArray for visualization in RViz
    marker_array = MarkerArray()
    octomap_marker = Marker()
    octomap_marker.header = octomap_msg.header
    octomap_marker.ns = 'octomap'
    octomap_marker.id = 1
    octomap_marker.type = Marker.CUBE_LIST
    octomap_marker.action = Marker.ADD
    octomap_marker.scale.x = octomap_msg.octomap.resolution
    octomap_marker.scale.y = octomap_msg.octomap.resolution
    octomap_marker.scale.z = octomap_msg.octomap.resolution
    octomap_marker.color.a = 0.8
    octomap_marker.color.r = 0.0
    octomap_marker.color.g = 0.0
    octomap_marker.color.b = 1.0

    # Iterate over the occupied nodes in the OctoMap and add them as markers
    occupied_nodes = tree.getOccupiedVoxelCenters()
    for node in occupied_nodes:
        point = node[0]
        octomap_marker.points.append(Point(point[0], point[1], point[2]))

    marker_array.markers.append(octomap_marker)
    marker_pub.publish(marker_array)
if __name__ == '__main__':
    # Initialize the ROS node
    rospy.init_node('octomap_generator')

    # Create a subscriber to receive the point cloud data
    rospy.Subscriber('/camera/depth/color/points', PointCloud2, point_cloud_callback)

    # Create publishers for the OctoMap and MarkerArray
    octomap_pub = rospy.Publisher('/your_octomap_topic', Octomap, queue_size=1)
    marker_pub = rospy.Publisher('/your_marker_array_topic', MarkerArray, queue_size=1)

    # Spin the ROS node
    rospy.spin()


