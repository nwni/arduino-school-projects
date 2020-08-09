#include <NewPing.h>
#include <AccelStepper.h>
//PIN AND DISTANCE REQUIRED FOR PING SENSOR 1
#define TRIGGER_PIN 12
#define ECHO_PIN 13
#define MAX_DISTANCE 200
//PIN AND DISTANCE REQUIRED FOR PING SENSOR 1

//CONSTANTS AND PIN NUMBER FOR STEPPERS
#define FULLSTEP 4
#define HALFSTEP 8
// motor pins
#define motorPin1  4     // Blue   - 28BYJ48 pin 1
#define motorPin2  5     // Pink   - 28BYJ48 pin 2
#define motorPin3  6     // Yellow - 28BYJ48 pin 3
#define motorPin4  7     // Orange - 28BYJ48 pin 4
                        // Red    - 28BYJ48 pin 5 (VCC)
                        
#define motorPin5  8     // Blue   - 28BYJ48 pin 1
#define motorPin6  9     // Pink   - 28BYJ48 pin 2
#define motorPin7  10    // Yellow - 28BYJ48 pin 3
#define motorPin8  11    // Orange - 28BYJ48 pin 4
                        // Red    - 28BYJ48 pin 5 (VCC)
//PING SENSOR OBJECT
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
//STEPPER OBJECTS
AccelStepper stepper1(FULLSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
AccelStepper stepper2(FULLSTEP, motorPin5, motorPin7, motorPin6, motorPin8);

//VAR
int uS, totalDistance, fdistance;
void setup(){
  Serial.begin(9600);
  //stepper1.setMaxSpeed(300.0);
  //stepper1.setAcceleration(100.0);
  //stepper1.setSpeed(200);
  //stepper1.moveTo(850);
  //stepper2.setMaxSpeed(300.0);
  //stepper2.setAcceleration(100.0);
  //stepper2.setSpeed(200);
  //stepper2.moveTo(850);
}

void loop(){
 //calculateDistance();
  //delay(500);
  uS = sonar.ping_median();
  totalDistance = uS/US_ROUNDTRIP_CM;  
  Serial.print(totalDistance);
  Serial.println("cm");
    if(totalDistance < 15){
      //stepper1.runSpeed();
      //stepper2.runSpeed();
      moveForward();
    }
}

//CALCULATE THE DISTANCE OF THE FRONT PING SENSOR...
void calculateDistance(){
  delay(500);
  uS = sonar.ping_median();
  totalDistance = uS/US_ROUNDTRIP_CM;
  Serial.print("Distancia: ");
  Serial.print(totalDistance);
  Serial.println("cm");
  //return totalDistance;
  //return uS/US_ROUNDTRIP_CM;
  //movementCondition(totalDistance);
}

//void movementCondition(int distanceS1){
//  //if(distanceS1 < 15){
//    //Serial.println(distanceS1);
//    moveForward();
//    calculateDistance();
//  //}
//}

void moveForward(){
  stepper1.setMaxSpeed(300.0);
  stepper2.setMaxSpeed(300.0);
  //stepper1.setAcceleration(100.0);
  stepper1.setSpeed(200);
  //stepper1.moveTo(850);
  
  //stepper2.setAcceleration(100.0);
  stepper2.setSpeed(200);
  //stepper2.moveTo(850);
  stepper1.moveTo(128);
  stepper2.moveTo(-128);
  stepper1.run();
  stepper2.run();
  stepper1.stop();
  stepper2.stop();

  //calculateDistance();
}

//void moveLeft(){
//  //stepper1.moveTo(800);
//  //stepper2.moveTo(800);
//  stepper1.runSpeed();
//  stepper2.runSpeed();
//  calculateDistance();
//}
//
//void stopMovement(){
//  stepper1.stop();
//  stepper2.stop();
//}


