#include <AccelStepper.h>

/*-----( Declare Constants and Pin Numbers )-----*/
#define FULLSTEP 4
#define HALFSTEP 8
// motor pins
#define motorPin1  4     // Blue   - 28BYJ48 pin 1
#define motorPin2  5     // Pink   - 28BYJ48 pin 2
#define motorPin3  6     // Yellow - 28BYJ48 pin 3
#define motorPin4  7     // Orange - 28BYJ48 pin 4
                        // Red    - 28BYJ48 pin 5 (VCC)
                        
//#define motorPin5  11     // Blue   - 28BYJ48 pin 1
//#define motorPin6  10     // Pink   - 28BYJ48 pin 2
//#define motorPin7  9    // Yellow - 28BYJ48 pin 3
//#define motorPin8  8    // Orange - 28BYJ48 pin 4
                        // Red    - 28BYJ48 pin 5 (VCC)

#define motorPin5  23     // Blue   - 28BYJ48 pin 1
#define motorPin6  25     // Pink   - 28BYJ48 pin 2
#define motorPin7  27    // Yellow - 28BYJ48 pin 3
#define motorPin8  29    // Orange - 28BYJ48 pin 4
//                        // Red    - 28BYJ48 pin 5 (VCC)


AccelStepper stepper1(FULLSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
AccelStepper stepper2(FULLSTEP, motorPin5, motorPin7, motorPin6, motorPin8);

// you can change these to DOUBLE or INTERLEAVE or MICROSTEP!
void setup()
{  
   Serial.begin(9600);           // set up Serial library at 9600 bps
   Serial.println("Stepper test!");
  
   stepper1.setMaxSpeed(500);     
   stepper1.setSpeed(500);        
   stepper2.setMaxSpeed(500);     
   stepper2.setSpeed(500); 
}
void loop()
{  
   stepper1.runSpeed();
   stepper2.runSpeed();
}
