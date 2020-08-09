
int motor1Pin1 = 2; // wire 1 (blue)
int motor1Pin2 = 3; // wire 2 (pink)
int motor1Pin3 = 4; // wire 3 (yellow)
int motor1Pin4 = 5; // wire 4 (orange)

int motor2Pin1 = 24; // wire 1 (blue)
int motor2Pin2 = 25; // wire 2 (pink)
int motor2Pin3 = 26; // wire 3 (yellow)
int motor2Pin4 = 27; // wire 4 (orange)

#define motorSpeed 1

//ULTRASONIC
#define trigPIN1 12
#define echoPIN1 13

#define trigPIN2 47
#define echoPIN2 49

//

int duration, distance, duration2, distance2;
int trigPin = 12, echoPin = 13, trigPin2 = 47, echoPin2 = 49;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor1Pin3, OUTPUT);
  pinMode(motor1Pin4, OUTPUT);

  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(motor2Pin3, OUTPUT);
  pinMode(motor2Pin4, OUTPUT);
  
  pinMode(trigPIN1, OUTPUT);
  pinMode(echoPIN1, INPUT);
  pinMode(trigPIN2, OUTPUT);
  pinMode(echoPIN2, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:LOW
  calculateDistance();
  calculateDistance2();
  //for(int i = 0; i < duration; i++){
    //moveM();
  //}
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 64; j++){
      //frontMovement();
      //delayMicroseconds(100);
      if((distance < 10) && (distance2 > 5)){
        //stopMovement(); 
        backwardsMovement();
      }
        //frontMovement();
      //else if(distance < 16 && distance2 > 7 ){
      else{
       frontMovement();
      }
       // backwardsMovement();
       //stopMovement();
      //}
      //stopMovement();
    }
    calculateDistance();
    calculateDistance2();
  }
  
  //delay(5000);
  //backwardsMovement();
  
  //avanzarM2();
}

void chooseMovement(){
  
}

//FRONT MOVEMENT
void frontMovement(){
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor1Pin3, LOW);
    digitalWrite(motor1Pin4, HIGH);
    delay(motorSpeed);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    digitalWrite(motor2Pin3, LOW);
    digitalWrite(motor2Pin4, LOW);
    delay(motorSpeed);
    
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor1Pin3, HIGH);
    digitalWrite(motor1Pin4, LOW);
    delay(motorSpeed);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
    digitalWrite(motor2Pin3, LOW);
    digitalWrite(motor2Pin4, LOW);
    delay(motorSpeed);
        
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor1Pin3, LOW);
    digitalWrite(motor1Pin4, LOW);
    delay(motorSpeed);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    digitalWrite(motor2Pin3, HIGH);
    digitalWrite(motor2Pin4, LOW);
    delay(motorSpeed);
        
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor1Pin3, LOW);
    digitalWrite(motor1Pin4, LOW);
    delay(motorSpeed);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    digitalWrite(motor2Pin3, LOW);
    digitalWrite(motor2Pin4, HIGH);
    delay(motorSpeed);    
}
//BACKWARDS MOVEMENT
void backwardsMovement(){
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor1Pin3, LOW);
    digitalWrite(motor1Pin4, LOW);
    delay(motorSpeed);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    digitalWrite(motor2Pin3, LOW);
    digitalWrite(motor2Pin4, HIGH);
    delay(motorSpeed);
    
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor1Pin3, LOW);
    digitalWrite(motor1Pin4, LOW);
    delay(motorSpeed);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    digitalWrite(motor2Pin3, HIGH);
    digitalWrite(motor2Pin4, LOW);
    delay(motorSpeed);
        
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor1Pin3, HIGH);
    digitalWrite(motor1Pin4, LOW);
    delay(motorSpeed);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
    digitalWrite(motor2Pin3, LOW);
    digitalWrite(motor2Pin4, LOW);
    delay(motorSpeed);
        
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor1Pin3, LOW);
    digitalWrite(motor1Pin4, HIGH);
    delay(motorSpeed);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    digitalWrite(motor2Pin3, LOW);
    digitalWrite(motor2Pin4, LOW);
    delay(motorSpeed);    
}


void stopMovement(){
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor1Pin3, LOW);
    digitalWrite(motor1Pin4, LOW);
    delay(motorSpeed);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    digitalWrite(motor2Pin3, LOW);
    digitalWrite(motor2Pin4, LOW);
    delay(motorSpeed);
    
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor1Pin3, LOW);
    digitalWrite(motor1Pin4, LOW);
    delay(motorSpeed);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    digitalWrite(motor2Pin3, LOW);
    digitalWrite(motor2Pin4, LOW);
    delay(motorSpeed);
        
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor1Pin3, LOW);
    digitalWrite(motor1Pin4, LOW);
    delay(motorSpeed);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    digitalWrite(motor2Pin3, LOW);
    digitalWrite(motor2Pin4, LOW);
    delay(motorSpeed);
        
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor1Pin3, LOW);
    digitalWrite(motor1Pin4, LOW);
    delay(motorSpeed);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    digitalWrite(motor2Pin3, LOW);
    digitalWrite(motor2Pin4, LOW);
    delay(motorSpeed);      
}

void calculateDistance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); //2
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); //10
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print(distance);
  Serial.print(" CM  ");
  Serial.print(duration);
  Serial.println(" TM");
}

void calculateDistance2(){
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2); //2
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); //10
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2/2) / 29.1;
  Serial.print(distance2);
  Serial.print(" CM2  ");
  Serial.print(duration2);
  Serial.println(" TM2");
}
