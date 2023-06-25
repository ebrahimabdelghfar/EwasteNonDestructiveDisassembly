#!/usr/bin/env python3
import rospy
import numpy as np
from std_msgs.msg import Int32,Bool
from geometry_msgs.msg import WrenchStamped
from enums.nodes import Nodes
from enums.topics import Topics

class Unscrewing:
    def __init__(self,Epsilon=0.7,delay=0.5) -> None:
        rospy.init_node(Nodes.UNSCREW.value)
        self.unscrewingPub = rospy.Publisher(Topics.UNSCREW_DONE.value, Bool, queue_size=1)
        self.motorPub = rospy.Publisher(Topics.ScrewDriverMOTOR_COMMAND.value, Int32, queue_size=1)
        rospy.Subscriber(Topics.ForceSensorWrenchWeightedFilter.value, WrenchStamped, self.ftCallback)
        rospy.Subscriber(Topics.UNSCREW_START_FLAG.value, Bool, self.startUnscrewing_Callback)
        # Delay between previous and current sensor readings
        self.ftSensor_delay = delay  # 500 ms
        # Variables to store previous and current readings
        self.ftSensor_previousReading = 0
        self.ftSensor_currentReading = 0
        # The range of readings that indicates near constant reading
        self.ftSensor_epsilon = Epsilon
        # A counter to check failure every specific period without adding an extra rospy.sleep()
        self.unscrewingFailure_counter = 0
        # The max number that the counter reaches when unscrewing fails
        # ftSensor_delay multiplied by 120
        self.unscrewingFailure_max = (self.ftSensor_delay) * 60
        # .data for publishing
        self.False_data = Bool()
        self.True_data = Bool()
        self.True_data.data = True
        self.False_data.data = False
        # Global variable that contains the .data for the start flag
        self.startUnscrewing_Flag = False
        pass

    def ftCallback(self,ftSensor_incomingReading:WrenchStamped):
        # Update sensor readings
        self.ftSensor_currentReading = ftSensor_incomingReading.wrench.force.z
        # rospy.loginfo("ftSensor_currentReading = %f" , ftSensor_currentReading)

    def startUnscrewing_Callback(self,startUnscrewing:Bool):
        rospy.loginfo("entered startUnscrewing_Callback")
        self.startUnscrewing_Flag = startUnscrewing.data
        if self.startUnscrewing_Flag is True:
            self.motorPub.publish(2)
        else:
            rospy.loginfo("Didn't enter checkReadings")

    def checkReadings(self):
        rospy.loginfo("entered checkReadings")
        # Check current reading aganist previous readings every "ftSensor_delay" seconds
        rospy.sleep(self.ftSensor_delay)
        unscrewingFailure_counter += 1
        # If the difference between readings is < epsilon then the bolt isn't going upwards anymore and unscrewing is done
        if abs(self.ftSensor_currentReading-ftSensor_previousReading) < self.ftSensor_epsilon:
            rospy.loginfo("Finished Unscrewing <3")
            self.motorPub.publish(0)
            self.unscrewingPub.publish(self.True_data)
        else:
            rospy.loginfo("-----Unscrewing Unscrewing Unscrewing-----")
            
        if unscrewingFailure_counter == self.unscrewingFailure_max:
            self.motorPub.publish(0)
            self.unscrewingPub.publish(self.False_data)
            unscrewingFailure_counter = 0
            rospy.loginfo("Unscrewing Failed")

        ftSensor_previousReading = self.ftSensor_currentReading

    def main(self):
        while not rospy.is_shutdown():
            screwingFLag:Bool = rospy.wait_for_message(Topics.UNSCREW_START_FLAG.value, Bool)
            if screwingFLag.data:
                self.checkReadings()
            else:
                pass                

UnscrewingNode=Unscrewing()
UnscrewingNode.main()
