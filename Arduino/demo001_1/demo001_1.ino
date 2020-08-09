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
#define motorPin1  5     // Blue   - 28BYJ48 pin 1
#define motorPin2  4     // Pink   - 28BYJ48 pin 2
#define motorPin3  3     // Yellow - 28BYJ48 pin 3
#define motorPin4  2     // Orange - 28BYJ48 pin 4
                        // Red    - 28BYJ48 pin 5 (VCC)
                        
#define motorPin5  24     // Blue   - 28BYJ48 pin 1
#define motorPin6  25     // Pink   - 28BYJ48 pin 2
#define motorPin7  26    // Yellow - 28BYJ48 pin 3
#define motorPin8  27    // Orange - 28BYJ48 pin 4
                        // Red    - 28BYJ48 pin 5 (VCC)
//PING SENSOR OBJECT
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
//STEPPER OBJECTS
AccelStepper stepper1(FULLSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
AccelStepper stepper2(FULLSTEP, motorPin5, motorPin7, motorPin6, motorPin8);

//VAR
int uS, totalDistance, fdistance;
void setup(){
  Serial.begin(115200);
  stepper1.setMaxSpeed(500.0);
  stepper1.setAcceleration(200.0);
  stepper1.setSpeed(400);
//  //stepper1.moveTo(850);
  stepper2.setMaxSpeed(500.0);
  stepper2.setAcceleration(200.0);
  stepper2.setSpeed(400);
//  //stepper2.moveTo(850);
}

void loop(){
 //calculateDistance();
  //delay(500);
//  uS = sonar.ping_median();
  
//  Serial.print(totalDistance);
//  Serial.println("cm");
   calculateDistance();
   //startMovement();
   movementCondition();
}

//CALCULATE THE DISTANCE OF THE FRONT PING SENSOR...
void calculateDistance(){
  uS = sonar.ping_median();
  //fdistance = sonar.convert_cm(uS);
  fdistance = uS/US_ROUNDTRIP_CM;
  Serial.print(fdistance);
  Serial.println("cm");
}

void movementCondition(){
  while(fdistance >= 8){
    //Serial.println(distanceS1);
    //startMovement();
    //calculateDistance();
    startMovement();
   calculateDistance();
  }
  stopMovement();
  calculateDistance();
  
}

void startMovement(){
  stepper1.runSpeed();
  stepper2.runSpeed(); 
}
void stopMovement(){
  stepper1.stop();
  stepper2.stop();
}


