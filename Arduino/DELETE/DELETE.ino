/**
 * Project name: Sonar-V
 * Author: Allan Brazute Alves
 * 
 * What it takes:
 * 1- Arduino (UNO R3)
 * 2- Steeper (28BYJ-48 - Pins IN1:8, IN2:10, IN3:9, IN4:11 - 5V)
 * 3- Ultrasonic range finder (HC-SRD4 - Pins E:12, T:13 - 5V)
 * 4- Buzzer (Pin 3)
 * 
 */

#include "Ultrasonic.h"
#include <Stepper.h>
#include <math.h>

// Constants
const byte BUZZER_PIN = 3;
const byte BUZZER_VOL = 100;

const byte STEPPER_PIN[] = {24, 26, 25, 27};
const byte STEPPER2_PIN[] = {2, 4, 3, 5};
const byte STEPPER_RPM = 32;
const int STEPPER_SPEED = 200;
const int STEPPER_STEPS2GO = 20; //2048;
const int STEPPER_ARC = 64;

const byte USONIC_PIN[] = {12,13};

const int SERIAL_BRATE = 9600;

FILE serial_stdout;

// Variables;
byte minDistDiff = 3;
int maxDistDiff = 1000;
int l = 0;
int r = 0;

int radar[2][round((STEPPER_ARC/STEPPER_STEPS2GO)+1)];
int countPos = 0;
int motorPos = 0;
int motorDir = 1; //1 Right, -1 Left

// Instantiate classes
Stepper stepper1(STEPPER_RPM, STEPPER_PIN[0], STEPPER_PIN[1], STEPPER_PIN[2], STEPPER_PIN[3]);
Stepper stepper2(STEPPER_RPM, STEPPER2_PIN[0], STEPPER2_PIN[1], STEPPER2_PIN[2], STEPPER2_PIN[3]);

Ultrasonic ultrasonic(USONIC_PIN[0], USONIC_PIN[1]); //(Trig,Echo);


void setup()
{
  stepper1.setSpeed(STEPPER_SPEED);
  stepper2.setSpeed(STEPPER_SPEED);
  Serial.begin(SERIAL_BRATE);
  pinMode(BUZZER_PIN, OUTPUT);
  
  fdev_setup_stream(&serial_stdout, serial_putchar, NULL, _FDEV_SETUP_WRITE);
  stdout = &serial_stdout;
}

void loop()
{
  if (motorDir < 0) 
  {
    l = radar[0][countPos] = ultrasonic.Ranging(CM);
  }
  else
  {
    r = radar[1][countPos] = ultrasonic.Ranging(CM);
  }
  
  int lrDiff = (l > r)? l - r : r - l;
  
  printf("{\"countPos\":\"%u\",\"motorPos\":\"%u\",\"motorDir\":\"%d\",\"l\":\"%u\",\"r\":\"%u\",\"lrDiff\":\"%u\"}\n", countPos, motorPos, motorDir, l, r, lrDiff);
  
  if ( lrDiff > minDistDiff && lrDiff < maxDistDiff )
  {
    analogWrite(BUZZER_PIN, BUZZER_VOL);
    delay(lrDiff);
    digitalWrite(BUZZER_PIN, LOW);
  }
  
  motorStep();
}

void motorStep()
{
  if ( (motorDir == -1 && motorPos <= (STEPPER_ARC - STEPPER_ARC)) || (motorDir == 1 && motorPos >= STEPPER_ARC) )
  {
    motorDir *= -1;
  }

  int stepNow = STEPPER_STEPS2GO * motorDir;
  
  stepper1.step(stepNow);
  stepper2.step(stepNow);
  countPos += motorDir;
  motorPos += stepNow;
}

int serial_putchar(char c, FILE* f) {
    if (c == '\n') serial_putchar('\r', f);
    return Serial.write(c) == 1? 0 : 1;
}
