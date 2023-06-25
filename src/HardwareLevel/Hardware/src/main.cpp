#include <Arduino.h>
#include <ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Int32.h>

#define ClampingPinA 4 
#define ClampingPinB 5
#define MotorPinA 8
#define MotorPinB 9
#define MotorPinPWM 6
#define MillingPinA 10
#define LimitSwitchPin 8

bool state = true;
// initialize ros node handle
ros::NodeHandle nh;
std_msgs::Int32 Finishing;
std_msgs::Int32 Object;

int operationMode=0;

ros::Publisher pub_operation_mode("/NODE_SUCCESSArduino",&Finishing);
ros::Publisher LimitSwitch("/Object",&Object);

void callback(const std_msgs::Int32& msg){
  operationMode = msg.data;
  if (operationMode == 0){
    digitalWrite(ClampingPinA,state);
    digitalWrite(ClampingPinB,!state);
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
    analogWrite(MotorPinPWM,250);
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
    analogWrite(MotorPinPWM,250);
    nh.loginfo("Motor is cw working");
  }
}

void MillingCallback(const std_msgs::Int32& msg){
  if(msg.data==1){
    digitalWrite(MillingPinA,HIGH);
    nh.loginfo("Milling working");
  }
  else if(msg.data==0){
    digitalWrite(MillingPinA,LOW);
    nh.loginfo("Milling is not working");
  }
}
ros::Subscriber<std_msgs::Int32> sub_finishing("/NodeToOperate", &callback);
ros::Subscriber<std_msgs::Int32> Motor("/MOTOR_COMMAND", &MotorCallback);
ros::Subscriber<std_msgs::Int32> Milling("/Milling_COMMAND", &MillingCallback);
void setup() {
  // put your setup code here, to run once:
  pinMode(MillingPinA,OUTPUT);
  pinMode(MotorPinA,OUTPUT);
  pinMode(MotorPinB,OUTPUT);
  pinMode(ClampingPinA,OUTPUT);
  pinMode(ClampingPinB,OUTPUT);
  pinMode(LimitSwitchPin,INPUT);

  Serial.begin(115200);
  nh.getHardware()->setBaud(115200);
  nh.initNode();
  nh.advertise(pub_operation_mode);
  nh.advertise(LimitSwitch);
  nh.subscribe(sub_finishing);
  nh.subscribe(Motor);
  nh.subscribe(Milling);
  nh.negotiateTopics();
}

void loop() {
  // if(digitalRead(LimitSwitchPin)==HIGH){
  //   Object.data = 1;
  //   LimitSwitch.publish(&Object);
  //   nh.loginfo("Object is detected");
  // }
  nh.spinOnce();
}
