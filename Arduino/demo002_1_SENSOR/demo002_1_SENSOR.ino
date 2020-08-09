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

/*-----( Declare Constants and Pin Numbers )-----*/
#define FULLSTEP 4
#define HALFSTEP 8
// motor pins
#define motorPin1  2     // Blue   - 28BYJ48 pin 1
#define motorPin2  3     // Pink   - 28BYJ48 pin 2
#define motorPin3  4     // Yellow - 28BYJ48 pin 3
#define motorPin4  5     // Orange - 28BYJ48 pin 4
                        // Red    - 28BYJ48 pin 5 (VCC)
                        
//#define motorPin5  11     // Blue   - 28BYJ48 pin 1
//#define motorPin6  10     // Pink   - 28BYJ48 pin 2
//#define motorPin7  9    // Yellow - 28BYJ48 pin 3
//#define motorPin8  8    // Orange - 28BYJ48 pin 4
//                        // Red    - 28BYJ48 pin 5 (VCC)

#define motorPin5  27     // Blue   - 28BYJ48 pin 1
#define motorPin6  26     // Pink   - 28BYJ48 pin 2
#define motorPin7  25    // Yellow - 28BYJ48 pin 3
#define motorPin8  24    // Orange - 28BYJ48 pin 4
//                        // Red    - 28BYJ48 pin 5 (VCC)

//#define TRIGGER_PIN 12
//#define ECHO_PIN 13
//#define MAX_DISTANCE 200
#define trigPIN1 12
#define echoPIN1 13
//#define trigPIN2
//#define echoPIN2
/*-----( Declare objects )-----*/
// NOTE: The sequence 1-3-2-4 is required for proper sequencing of 28BYJ48
AccelStepper stepper1(FULLSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
AccelStepper stepper2(FULLSTEP, motorPin5, motorPin7, motorPin6, motorPin8);

//NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
/*-----( Declare Variables )-----*/

int uS, totalDistance, fdistance, sonarTime, distance, duration;

void setup()   /****** SETUP: RUNS ONCE ******/
{
   Serial.begin(9600);
   stepper1.setMaxSpeed(1000);     
   stepper1.setSpeed(800);        
   stepper2.setMaxSpeed(1000);     
   stepper2.setSpeed(800);

   pinMode(trigPIN1, OUTPUT);
   pinMode(echoPIN1, INPUT);

}//--(end setup )---


void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{
  //runSteppers();
  calculateDistance(trigPIN1, echoPIN1);
  //totalDistance = distance;
  //runSteppers();
  //stopSteppers();
  frontSensor();
}

void calculateDistanceBORRAR(){
  calculateDistance(trigPIN1, echoPIN1);
  totalDistance = distance;
  Serial.print(distance);
  Serial.println("cm");
}

void calculateDistance(int trigPin, int echoPin){
  //runSteppers();
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print(distance);
  Serial.println("cm");

  //frontSensor();
}

void frontSensor(){
  while(distance > 15){
    runSteppers();
    calculateDistance(trigPIN1, echoPIN1);
  }
  //calculateDistance(trigPIN1, echoPIN1);
  stopSteppers();
}

void runSteppers(){
  stepper1.runSpeed();
  stepper2.runSpeed();
}

void stopSteppers(){
  stepper1.stop();
  stepper2.stop();
}

