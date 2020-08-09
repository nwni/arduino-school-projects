/* YourDuinoStarter Example: 2 Stepper Motors
 - WHAT IT DOES: Runs 2 28BYJ-48 stepper motors with AccelStepper Library
 - Motors accelerate and decelerate simultaneously in opposite rotations
 - SEE the comments after "//" on each line below
 -  Derived from example code by Mike McCauley
 -  modified by Celem for single stepper
 -  modified by lowres for two steppers 
 NOTE: This may not run 2 motors from USB. 
       May need separate +5 Supply for motors
 - CONNECTIONS: See Pin definitions below

 - V1.01 11/30/2013
   Questions: terry@yourduino.com */

/*-----( Import needed libraries )-----*/
#include <AccelStepper.h>
//#include <NewPing.h>
//#include <MultiStepper.h>

/*-----( Declare Constants and Pin Numbers )-----*/
#define FULLSTEP 4
#define HALFSTEP 8
// motor pins
#define motorPin1  32     // Blue   - 28BYJ48 pin 1
#define motorPin2  30     // Pink   - 28BYJ48 pin 2
#define motorPin3  28     // Yellow - 28BYJ48 pin 3
#define motorPin4  26     // Orange - 28BYJ48 pin 4
                        // Red    - 28BYJ48 pin 5 (VCC)
                        
//#define motorPin5  11     // Blue   - 28BYJ48 pin 1
//#define motorPin6  10     // Pink   - 28BYJ48 pin 2
//#define motorPin7  9    // Yellow - 28BYJ48 pin 3
//#define motorPin8  8    // Orange - 28BYJ48 pin 4
//                        // Red    - 28BYJ48 pin 5 (VCC)

#define motorPin5  4     // Blue   - 28BYJ48 pin 1
#define motorPin6  5     // Pink   - 28BYJ48 pin 2
#define motorPin7  6    // Yellow - 28BYJ48 pin 3
#define motorPin8  7    // Orange - 28BYJ48 pin 4
//                        // Red    - 28BYJ48 pin 5 (VCC)

//#define TRIGGER_PIN 12
//#define ECHO_PIN 13
//#define MAX_DISTANCE 200

#define trigPIN1 50
#define echoPIN1 52

//#define trigPIN2
//#define echoPIN2
/*-----( Declare objects )-----*/
// NOTE: The sequence 1-3-2-4 is required for proper sequencing of 28BYJ48
AccelStepper stepper1(FULLSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
AccelStepper stepper2(FULLSTEP, motorPin5, motorPin7, motorPin6, motorPin8);

//NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
/*-----( Declare Variables )-----*/

int uS, totalDistance, fdistance, sonarTime, distance, duration, mvnIncrease;
int trigPin = 12, echoPin = 13;
void setup()   /****** SETUP: RUNS ONCE ******/
{
   Serial.begin(9600);
   //stepper1.setMaxSpeed(1000);   
   //stepper1.setAcceleration(100.0);  
   //stepper1.setSpeed(800);        
   //stepper2.setMaxSpeed(1000);
   //stepper2.setAcceleration(100.0);     
   //stepper2.setSpeed(800);

   pinMode(trigPIN1, OUTPUT);
   pinMode(echoPIN1, INPUT);

}//--(end setup )---


void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{
  frontSensor();
}

//ULTRASONICO 1
void calculateDistance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); //2
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); //10
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print(distance);
  Serial.println("cm");
}

void frontSensor(){
  //runSteppers();
  calculateDistance();
    while(distance >= 7){
      runSteppers();
      calculateDistance();
    }
  stopSteppers();
}



void blockingRunSpeedToPosition(long position){
    stepper1.moveTo(position);
    stepper1.setSpeed(500);
    stepper2.moveTo(position);
    stepper2.setSpeed(500);
    while (stepper1.distanceToGo() != 0 && stepper2.distanceToGo() != 0){
      stepper1.runSpeedToPosition();
      stepper2.runSpeedToPosition();
    }
}



//void frontSensor(){
//    while(distance >= 7){
//      
//      //calculateDistance(trigPIN1, echoPIN1);
//      runSteppers();
//      calculateDistance(trigPIN1, echoPIN1);
//      
//    }
//    //calculateDistance(trigPIN1, echoPIN1);
//  //reverse();
//    //stopSteppers();
//    reverseRight();
//  //stopSteppers();
//  //calculateDistance(trigPIN1, echoPIN1);
//}



void runSteppers(){
  //stopSteppers();
  stepper1.setMaxSpeed(800);     
  stepper1.setAcceleration(500);
  stepper1.setSpeed(500);    
  //stepper1.moveTo(10000);
  stepper2.setMaxSpeed(800);   
  stepper2.setAcceleration(500);  
  stepper2.setSpeed(500);
  //stepper2.moveTo(1000);

  stepper1.runSpeed();
  stepper2.runSpeed();
}

void stopSteppers(){
  //stepper1.moveTo(0);
  //stepper2.moveTo(0);
  stepper1.setSpeed(50);
  stepper1.setSpeed(50);
  
  stepper1.stop();
  stepper2.stop();

  //delay(500);
  //stepper1.runToPosition();
  //stepper2.runToPosition();
}

void reverse(long position){
    stepper1.moveTo(-position);
    stepper1.setSpeed(500);
    stepper2.moveTo(-position);
    stepper2.setSpeed(500);
    //while (stepper1.distanceToGo() != 0 && stepper2.distanceToGo() != 0){
      stepper1.run();
      stepper2.run();
    //}
}

void turn(long position){
    stepper1.moveTo(-position);
    stepper1.setSpeed(-500);
    stepper2.moveTo(position);
    stepper2.setSpeed(500);
    while (stepper1.distanceToGo() != 0 && stepper2.distanceToGo() != 0){
      stepper1.runSpeedToPosition();
      stepper2.runSpeedToPosition();
    }
}

