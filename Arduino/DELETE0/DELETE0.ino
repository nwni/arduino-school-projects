/*-----( Import needed libraries )-----*/
#include <Stepper.h>

/*-----( Declare Constants, Pin Numbers )-----*/
//---( Number of steps per revolution of INTERNAL motor in 4-step mode )---
#define STEPS_PER_MOTOR_REVOLUTION 32   

//---( Steps per OUTPUT SHAFT of gear reduction )---
#define STEPS_PER_OUTPUT_REVOLUTION 16 * 64  //2048  

/*-----( Declare objects )-----*/
// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to

//The pin connections need to be 4 pins connected
// to Motor Driver In1, In2, In3, In4  and then the pins entered
// here in the sequence 1-3-2-4 for proper sequencing
Stepper small_stepper(STEPS_PER_MOTOR_REVOLUTION, 24, 26, 25, 27);
Stepper small_stepper2(STEPS_PER_MOTOR_REVOLUTION, 5, 3, 4, 2);


/*-----( Declare Variables )-----*/
int  Steps2Take;
int data;
String dataS ; 
int sensorValue, stepsDone;

const int trigPin = 12;
const int echoPin = 13;

void setup()   /*----( SETUP: RUNS ONCE )----*/
{
// Nothing (Stepper Library sets pins as outputs)
//serial communication
Serial.begin(9600);
}/*--(end setup )---*/

void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
delay(3000);
//half shaft
for (int i = 1 ; i < 33 ; i++) 
{
  Steps2Take  = 32;  
  small_stepper.setSpeed(500);   
  small_stepper.step(Steps2Take);
  small_stepper2.setSpeed(500);   
  small_stepper2.step(Steps2Take);
  sensorValue= distance () ;
  stepsDone = i;  
   if (sensorValue < 51)
   {
   data = stepsDone*100 + sensorValue ;
   dataS = String(data);
   Serial.println(dataS);
   Serial.println("< 51");
   }
   else
   {
   data = stepsDone*100 ;
   dataS = String(data);
   Serial.println(dataS);
   Serial.println("mayor");
   }
} 
  delay(3000);
  //half shaft to the right
for (int i = 1 ; i < 33 ; i++ )
{
  Steps2Take  =  - 32 ;  
  small_stepper.setSpeed(500);  
  small_stepper.step(Steps2Take);
  small_stepper2.setSpeed(500);   
  small_stepper2.step(Steps2Take);
  sensorValue= distance () ;
  stepsDone =32 - i;  
    if (sensorValue < 51)
    {
    data = stepsDone*100 + sensorValue ;
    dataS = String(data);
    Serial.println(dataS);
    Serial.println("< 51");
    }
    else
    {
    data = stepsDone*100 ;
    dataS = String(data);
    Serial.println(dataS);
    Serial.println("mayor");
    }

}
  
}/* --(end main loop )-- */



 long distance () 
   {
  long duration, inches, cm;
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  cm = microsecondsToCentimeters(duration);

  //delay(100);
  
  return cm ; 
  }
 
//  long microsecondsToInches(long microseconds)
//  {
//  return microseconds / 74 / 2;
//  }
 
  long microsecondsToCentimeters(long microseconds)
  {
  return microseconds / 29 / 2;
  }
