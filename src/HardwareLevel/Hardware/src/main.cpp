#include <Arduino.h>
#include <ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Int32.h>
#define ClampingPin 12 
#define MotorPinA 7
#define MotorPinB 6
#define MotorPinPWM 5
bool state = true;
// initialize ros node handle
ros::NodeHandle nh;
std_msgs::Int32 Finishing;
int operationMode=0;

ros::Publisher pub_operation_mode("/NODE_SUCCESSArduino",&Finishing);

void callback(const std_msgs::Int32& msg){
  operationMode = msg.data;
  if (operationMode==0){
    digitalWrite(ClampingPin,state);
    state = !state;
    Finishing.data = 3;
    pub_operation_mode.publish(&Finishing);
    nh.loginfo("Clamping");
  }
}

void MotorCallback(const std_msgs::Int32& msg){
  if(msg.data==1){
    digitalWrite(MotorPinA,HIGH);
    digitalWrite(MotorPinB,LOW);
    analogWrite(MotorPinPWM,150);
    nh.loginfo("Motor is cc working");
  }
  else if(msg.data==0){
    digitalWrite(MotorPinA,LOW);
    digitalWrite(MotorPinB,LOW);
    analogWrite(MotorPinPWM,0);
    nh.loginfo("Motor is not working");
  }
  else if(msg.data==2){
    digitalWrite(MotorPinA,LOW);
    digitalWrite(MotorPinB,HIGH);
    analogWrite(MotorPinPWM,150);
    nh.loginfo("Motor is cw working");
  }
}
ros::Subscriber<std_msgs::Int32> sub_finishing("/NodeToOperate", &callback);
ros::Subscriber<std_msgs::Int32> Motor("/MOTOR_COMMAND", &MotorCallback);
ros::Subscriber<std_msgs::Int32> Motor("/MOTOR_COMMAND", &MotorCallback);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  nh.getHardware()->setBaud(115200);
  nh.initNode();
  nh.advertise(pub_operation_mode);
  nh.subscribe(sub_finishing);
  nh.subscribe(Motor);
  nh.negotiateTopics();
}

void loop() {
  nh.spinOnce();
}
