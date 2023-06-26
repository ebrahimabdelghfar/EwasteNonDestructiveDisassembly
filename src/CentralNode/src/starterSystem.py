#!/usr/bin/env python3
import rospy
import roslaunch
import rosnode
from enums.nodes import Nodes

class starterSystem:
    '''
    Objective : this node is repsonsible for starting the Autonmoous system and ensure everything is running
    '''
    def __init__(self) -> None:

        roslaunch.pmon._init_signal_handlers = self.dummy_function
        rospy.init_node(Nodes.HeartBeat.value)
        #initiate the roslaunch api
        self.launch = roslaunch.scriptapi.ROSLaunch()
        self.launch.start()
        #list all the runnung nodes
        self.Sequance = Nodes.StartSequance.value
        self.NodeInfo = Nodes.NodesToBeOperatedInfo.value
    def start(self)->None:
        '''
        Objective : This function is used to start the system
        '''
        for node in self.Sequance:
            if len(self.NodeInfo[node])==3 :
                #if the node does not have any arguments
                Run = roslaunch.core.Node(package=self.NodeInfo[node][0],node_type=self.NodeInfo[node][1],name =self.NodeInfo[node][2],output="screen")
            else:
                #if the node has arguments
                Run = roslaunch.core.Node(package=self.NodeInfo[node][0],node_type=self.NodeInfo[node][1],name =self.NodeInfo[node][2],args=self.NodeInfo[node][3])
            process=self.launch.launch(Run)
            while True:
                '''ensure that the node is running'''
                flag=rosnode.rosnode_ping("/"+node,max_count=2,skip_cache=True)
                if flag:
                    print("Node ["+node+"] is running")
                    break
                rospy.sleep(1)

    def dummy_function(self):
        pass

if __name__ == "__main__":
    start=starterSystem()
    start.start()