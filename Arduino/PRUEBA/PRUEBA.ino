int motorPin1 = 2; // wire 1 (blue)
int motorPin2 = 3; // wire 2 (pink)
int motorPin3 = 4; // wire 3 (yellow)
int motorPin4 = 5; // wire 4 (orange)
//wire 5 (Red) is a VCC and should be put to 5V, with this setup it is not needed, but it is good to know if you make something like an 8 step spinup

int motorSpeed = 2;
int cont = 0;
void setup() {
  
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  pinMode(13, OUTPUT);
}
//512

void loop(){

  for(int i = 0; i < 2; i++){
    cuarentay5();
  }
  digitalWrite(13, HIGH);
  delay(1000);
  
  for(int i = 0; i < 3; i++){
    cuarentay5tr3s();
  } 
  delay(1000);

  ciento80();

  exit(0);
}
void cuarentay5(){
  for(int i=0;i<64;i++){ 
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(motorSpeed);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(motorSpeed);
     digitalWrite(motorPin1,LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    delay(motorSpeed);
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    delay(motorSpeed);
  }
delay(500);
}

void cuarentay5tr3s(){
  for(int i=0;i<64;i++){ 
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    delay(motorSpeed);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    delay(motorSpeed);
     digitalWrite(motorPin1,LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(motorSpeed);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(motorSpeed);
  }
delay(500);
}

void ciento80(){
  for(int i=0;i<8;i++){ 
    
     for(int j=0;j<32                                                                                                                                                                                                                                                                                                                                                       ;j++){
      
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, HIGH);
        delay(motorSpeed);
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, HIGH);
        digitalWrite(motorPin4, LOW);
        delay(motorSpeed);
         digitalWrite(motorPin1,LOW);
        digitalWrite(motorPin2, HIGH);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, LOW);
        delay(motorSpeed);
        digitalWrite(motorPin1, HIGH);
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, LOW);
        delay(motorSpeed);
        digitalWrite(13, HIGH);
     }
     digitalWrite(13, LOW);
  }
}

