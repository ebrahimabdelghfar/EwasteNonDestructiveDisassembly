#include <Arduino.h>
#include <ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Int32.h>
#define ClampingPin 12 
bool state = true;
// initialize ros node handle
ros::NodeHandle nh;
// initialize publisher and subscriber
std_msgs::Bool Finishing;
int operationMode=0;

void callback(const std_msgs::Int32& msg){
  operationMode = msg.data;
}

ros::Publisher pub_operation_mode("ClampingState",&Finishing);
ros::Subscriber<std_msgs::Int32> sub_finishing("NodeToOperate", &callback);

void setup() {
  // put your setup code here, to run once:
  nh.initNode();
  nh.advertise(pub_operation_mode);
  nh.subscribe(sub_finishing);
}

void loop() {
  /*If the operation mode equal to zero so it will clamp for the first message*/
  /*In the seconed message the state of clamping will change it's state*/
  if (operationMode==0){
    digitalWrite(ClampingPin,state);
    state = !state;
    Finishing.data = true;
    pub_operation_mode.publish(&Finishing);
  }
  delay(2000);
  Finishing.data = false;
  pub_operation_mode.publish(&Finishing);
  /*this line will wait only one message to enter the callback*/
  nh.spinOnce();
}
