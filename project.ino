//JAGDEEP SINGH
//200424790
//Komalpreet Kaur
//200430366
#include <Servo.h>          // library for the servo
#include <NewPing.h>        //for the Ultrasonic sensor function library.

//L298N motor control pins
const int LeftMotorForward = 2;
const int LeftMotorBackward = 4;
const int RightMotorForward = 7;
const int RightMotorBackward = 8;

//sensor pins
#define trig_pin 10
#define echo_pin 11

#define maximum_distance 500
boolean goesForward = true;
int distance;

NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function
Servo servo; 

void setup(){

  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  
  servo.attach(5); //servo pin
  servo.write(115);
  delay(2000);
  distance = readPing();
  delay(1000);
  distance = readPing();
  delay(1000);
  distance = readPing();
  delay(1000);
  distance = readPing();
  delay(1000);
}

void loop(){

  int distanceR = 0;
  int distanceL = 0;
  delay(50);
  moveForward();

  if (distance <= 50){
    moveStop();
    delay(300);
    moveBackward();
    delay(100);
    turnRight();
    delay(100);
    moveStop();
    delay(100);
    distanceR = lookRight();
    delay(200);
    distanceL = lookLeft();
    delay(200);

    if (distance >= distanceL){
      turnRight();
      moveForward(); 
    }
    else{
      turnLeft();
      moveForward(); 
    }
  }
  else{
    moveForward(); 
  }
    distance = readPing();
}

int lookRight(){  
  servo.write(30);
  delay(500);
  int distance = readPing();
  delay(100);
  servo.write(90);
  return distance;
}

int lookLeft(){
  servo.write(90);
  delay(500);
  int distance = readPing();
  delay(100);
  servo.write(130);
  return distance;
  delay(100);
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

void moveStop(){
  
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward(){

  if(goesForward){

    goesForward=true;
    
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
  
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW); 
    
  }
}

void moveBackward(){

  goesForward=false;

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  moveForward();
  
}

void turnRight(){

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
  delay(500);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
 
  
  
}

void turnLeft(){

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);

  delay(500);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}
