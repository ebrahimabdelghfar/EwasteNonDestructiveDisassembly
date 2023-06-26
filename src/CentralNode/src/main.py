#!/usr/bin/env python3
import rospy
from enums.nodes import Nodes
from enums.response_status import Response
from CentralNode.srv import *
from enums.nodes import Nodes
from enums.topics import Topics
from enums.services import Services
from std_msgs.msg import Int32, Bool
from CentralNode.msg import node_response as NodeResponse
from storage.db import RobotDatabase
import storage.storage_keys as StorageKeys
from enums.operations import OPERATIONS, getChangeToolIndices
from handlers.success_handler import handleSuccess
from handlers.in_progress_handler import handleInProgress
import json

class CentralNode:
    def __init__(self):
        self.subscribers = {}
        self.publishers = {}
        self.services = {}
        self.currentNode = 0
        self.objectExists = False
        self.getScrewIndex, self.returnScrewIndex, self.getMillingIndex, self.returnMillingIndex = getChangeToolIndices()
        self.currentSchedule = {}
        RobotDatabase().resetWholeFile()

    def initPublishers(self):
        self.publishers = {}
        self.publishers[Topics.NODE_TO_OPERATE] = rospy.Publisher(Topics.NODE_TO_OPERATE.value, Int32,queue_size=1,latch=True)
        self.publishers[Topics.START_COLLISION_DETECTED] = rospy.Publisher(Topics.START_COLLISION_DETECTED.value, Bool,queue_size=1)

    def initSubscribers(self):
        self.subscribers = {}
        self.subscribers[Topics.NODE_SUCCESS] = rospy.Subscriber(Topics.NODE_SUCCESS.value, NodeResponse, self.nodeSuccessCallback,queue_size=1)
        # self.subscribers[Topics.COLLISION_DETECTED] = rospy.Subscriber(Topics.COLLISION_DETECTED, Bool)
    
    def initServices(self):
        self.services = {}
        self.services[Services.GET_SCREW_LIST.value] = rospy.Service(Services.GET_SCREW_LIST.value, ScrewList, self.getScrewList)
        self.services[Services.SCHEDULAR.value] = rospy.Service(Services.SCHEDULAR.value, Schedular, self.getSchedular)

    def getScrewList(self,req):
        key =  StorageKeys.LIST_OF_SCREWS if self.currentNode == 2 else StorageKeys.CANT_UNSCREW_LIST
        screwList = RobotDatabase().readFromDB(key=key)
        screwList=json.loads(screwList)
        response = ScrewListResponse()
        print(f"Screw list {screwList}")
        screwIndex = -1
        try:
            screwIndex = RobotDatabase().readFromDB(StorageKeys.SCREW_INDEX)
            screwIndex=json.loads(screwIndex)
            print("screwindex after load",screwIndex)

        except:
            screwIndex = 0
        response.screwList = screwList[(screwIndex)*6:]
        print("Service response: ", response.screwList)
        return response
    
    def getSchedular(self,req):

        wayPoints, waypointTypes, checkTorque, velocity, acceleration = self.currentSchedule[StorageKeys.WAYPOINTS], self.currentSchedule[StorageKeys.WAYPOINTS_TYPES], self.currentSchedule[StorageKeys.CHECK_FORCE], self.currentSchedule[StorageKeys.VEL], self.currentSchedule[StorageKeys.ACC] 
        print(f"Waypoints {wayPoints}")
        startIndex = -1
        try:
            startIndex = RobotDatabase().readFromDB(StorageKeys.CHANGE_TOOL_SCHEDULE_INDEX)
            startIndex=json.loads(startIndex)
        except:
            startIndex = 0

        response = SchedularResponse()
        response.waypoints = wayPoints[startIndex * 6:]
        response.waypoint_types = waypointTypes[startIndex:]
        response.checkTorque = checkTorque[startIndex:]
        response.velocity = velocity[startIndex:]
        response.acceleration = acceleration[startIndex:]
        return response

    def start(self):
        rospy.init_node(Nodes.CENTRAL.value)
        self.initPublishers()
        self.initSubscribers()
        self.initServices()
        rate = rospy.Rate(10)

        while not rospy.is_shutdown():
            print("Central node is starting... ", self.currentNode)
            self.publishers[Topics.NODE_TO_OPERATE].publish(self.currentNode)
            rospy.spin()


    def config(self):
        db = RobotDatabase()
        data = db.readAllFromDB()
        if self.objectExists:
            if db.isNotEmpty():
                pass

                

    def nodeSuccessCallback(self,nodeResponse:NodeResponse):
        print("Current node: ", self.currentNode)
        print("Recieved: ", nodeResponse.status)
        print("Recieved: ", nodeResponse.extraMessage)
        if nodeResponse.status == Response.IN_PROGRESS.value:
            handleInProgress(self.currentNode, nodeResponse, self.currentSchedule)
        elif nodeResponse.status == Response.SUCCESSFULL.value:
            handleSuccess(self.currentNode, nodeResponse)
            RobotDatabase().addToDB(StorageKeys.OPERATION_DONE, self.currentNode)
            if self.currentNode < len(OPERATIONS):
                RobotDatabase().addToDB(StorageKeys.OPERATION_INPROGRESS, self.currentNode + 1)
                self.currentNode += 1
                print(f"Current node {self.currentNode}")
                self.setSchedule()
                self.publishers[Topics.NODE_TO_OPERATE].publish(self.currentNode)
    def setSchedule(self):
        if self.currentNode == self.getScrewIndex:
            self.currentSchedule = RobotDatabase().getScrewSchedule()
        elif self.currentNode == self.returnScrewIndex:
            self.currentSchedule = RobotDatabase().returnScrewSchedule()
        elif self.currentNode == self.getMillingIndex:
            self.currentSchedule = RobotDatabase().getMillingSchedule()
        elif self.currentNode == self.returnMillingIndex:
            self.currentSchedule = RobotDatabase().returnMillingSchedule()
        
if __name__ == '__main__':
    try:
        c = CentralNode()
        c.start()
    except rospy.ROSInterruptException:
        pass 