// DualMotorShield.pde
// -*- mode: C++ -*-
//
// Shows how to run 2 simultaneous steppers
// using the Itead Studio Arduino Dual Stepper Motor Driver Shield
// model IM120417015
// This shield is capable of driving 2 steppers at 
// currents of up to 750mA
// and voltages up to 30V
// Runs both steppers forwards and backwards, accelerating and decelerating
// at the limits.
//
// Copyright (C) 2014 Mike McCauley
// $Id:  $
#include <AccelStepper.h>
// Define some steppers and the pins the will use
//AccelStepper stepper1(AccelStepper::DRIVER, STEPPER1_STEP_PIN, STEPPER1_DIR_PIN);
//AccelStepper stepper2(AccelStepper::DRIVER, STEPPER2_STEP_PIN, STEPPER2_DIR_PIN);
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
AccelStepper stepper1(FULLSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
AccelStepper stepper2(FULLSTEP, motorPin5, motorPin7, motorPin6, motorPin8);

void setup()
{  
    //Serial.begin(9600);
    stepper1.setMaxSpeed(1000.0);
    //stepper1.setAcceleration(100.0);
    //stepper1.moveTo(-10240);
    stepper1.setSpeed(400);
    //Serial.println(stepper1.speed());
    stepper2.setMaxSpeed(1000.0);
    //stepper2.setAcceleration(100.0);
    //stepper2.moveTo(10240);
    stepper2.setSpeed(-400);
}
void loop()
{
    // Change direction at the limits
//    if (stepper1.distanceToGo() == 0)
//        stepper1.moveTo(-stepper1.currentPosition());
//    if (stepper2.distanceToGo() == 0)
//        stepper2.moveTo(stepper1.currentPosition());
        
    stepper1.runSpeed();
    stepper2.runSpeed();
   
    //Serial.println(stepper1.speed());
    //Serial.println(stepper2.speed());
}
