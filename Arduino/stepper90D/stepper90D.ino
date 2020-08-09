#include  <Stepper.h>

int motorPin1 = 8; // wire 1 (blue)
int motorPin2 = 9; // wire 2 (pink)
int motorPin3 = 10; // wire 3 (yellow)
int motorPin4 = 11; // wire 4 (orange)

#define STEPS 48

Stepper small_stepper(STEPS, motorPin1, motorPin2, motorPin3, motorPin4);

int Steps2Take;

void setup() {
  // put your setup code here, to run once:
  small_stepper.setSpeed(128);
}

void loop() {
  // put your main code here, to run repeatedly:
  //small_stepper.setSpeed(300);
  Steps2Take = 512;
  small_stepper.step(Steps2Take);
  delay(500);

  //small_stepper.setSpeed(300);
  Steps2Take = -512;
  small_stepper.step(Steps2Take);
  delay(500);
}
