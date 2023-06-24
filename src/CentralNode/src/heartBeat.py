#!/usr/bin/env python3
import rospy
import roslaunch
import rosnode
from enums.nodes import Nodes
class HeartBeat:
    '''
    Objective : This class is used to check if the robot is running or not
                If the robot is not running and in automatic Mode then it will start the robot
    -------------------------------------
    Attributes: None
    '''
    def __init__(self,heartRate) -> None:
        '''
        @param heartRate : the interval at which the heartbeat should be checked
        @type heartRate : int (seconds)
        '''

        '''the following line disable rossignal handler so we can launch form callback'''
        roslaunch.pmon._init_signal_handlers = self.dummy_function
        '''end'''
        rospy.init_node(Nodes.HeartBeat.value)
        #initiate the roslaunch api
        self.launch = roslaunch.scriptapi.ROSLaunch()
        self.launch.start()
        #end
        self.HeartRate = heartRate
        #interval checker for the all nodes 
        rospy.Timer(rospy.Duration(self.HeartRate), self.NodesHeartBeat)
        #list all the runnung nodes
        self.NodesExist = Nodes.NodesToBeOperated.value
        self.NodeInfo = Nodes.NodesToBeOperatedInfo.value
        pass

    def NodesHeartBeat(self,event)->None:
        Operated , _ = rosnode.rosnode_ping_all()
        #remove the '/' from the node name
        for node in Operated:
            Operated[Operated.index(node)] = node.replace("/","")
        #see the which nodes are not running
        not_running = list(set(self.NodesExist).difference(Operated))
        print("Nodes that are running {} ,are not running {}".format(Operated,not_running))
        #start the nodes that are not running by looping through the list
        for node in not_running:
            if len(self.NodeInfo[node])==3 :
                #if the node does not have any arguments
                Run = roslaunch.core.Node(package=self.NodeInfo[node][0],node_type=self.NodeInfo[node][1],name =self.NodeInfo[node][2])
            else:
                #if the node has arguments
                rospy.set_param(self.NodeInfo[node][3],self.NodeInfo[node][4])
                rospy.set_param(self.NodeInfo[node][5],self.NodeInfo[node][6])
                Run = roslaunch.core.Node(package=self.NodeInfo[node][0],node_type=self.NodeInfo[node][1],name =self.NodeInfo[node][2])
            process=self.launch.launch(Run)
            while True:
                '''ensure that the node is running'''
                flag=rosnode.rosnode_ping("/"+node,max_count=2,skip_cache=True)
                if flag:
                    print("Node "+node+" is running")
                    break
                rospy.sleep(0.5)
    def dummy_function(self)->None: 
        '''
        Objective : This is a dummy function to disable the rossignal handler
        '''
        pass
HeartBeat=HeartBeat(heartRate = 2)#heartRate in seconds
rospy.spin()  #keeps the node alive