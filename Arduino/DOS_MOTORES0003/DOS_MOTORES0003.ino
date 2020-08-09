
//MOTORES
//DERECHO
int motor1Pin1 = 32; // wire 1 (blue)
int motor1Pin2 = 30; // wire 2 (pink)
int motor1Pin3 = 28; // wire 3 (yellow)
int motor1Pin4 = 26; // wire 4 (orange)

int motor2Pin1 = 4; // wire 1 (blue)
int motor2Pin2 = 5; // wire 2 (pink)
int motor2Pin3 = 6; // wire 3 (yellow)
int motor2Pin4 = 7; // wire 4 (orange)

#define motorSpeed 2

//ULTRASONIC
//DERECHO
#define trigPIN1 50
#define echoPIN1 52
//FRENTE
#define trigPIN2 45
#define echoPIN2 47

//

int duration, distance, duration2, distance2;
int trigPin = 50, echoPin = 52, trigPin2 = 45, echoPin2 = 47;
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

  //DERECHO
  pinMode(trigPIN1, OUTPUT);
  pinMode(echoPIN1, INPUT);
  //FRENTE
  pinMode(trigPIN2, OUTPUT);
  pinMode(echoPIN2, INPUT);

}

void loop() {
  calculateDistance();
  calculateDistance2();

  if (distance >= 4 && distance <= 6 ) {
    //chooseMovement();
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 16; j++) {
        frontMovement();
      }
    }
  }
      else if (distance < 4) {
        //for(int i = 0; i < 2; i++){
        for (int j = 0; j < 16; j++) {
          girarIzquierda();
        }
        //}
      }
  
      else if (distance > 6){
        for (int j = 0; j < 16; j++) {
          girarDerecha();
        }
      }

  if (distance > 6) {
    for (int j = 0; j < 32; j++) {
      frontMovement();
    }
    for (int i = 0; i < 64; i++) {
      girarDerecha();
    }
    //for(int i = 0; i < 2; i++){
    //for(int j = 0; j < 16; j++){
    // girarDerecha();
    // }
    //}
  }

  if (distance2 < 6 && (distance > 0)) {
//    for (int j = 0; j < 16; j++) {
//      frontMovement();
//    }
    for (int i = 0; i < 300; i++) {
      girarIzquierda();
    }

  }

  //CUANDO EL SENSOR DE LA DERECHA DETECTE DISTANCIA MAYOR QUE 12, AVANZA DERECHO Y GIRA..
  //  else if(distance >= 12){
  //    for(int i = 0; i < 64; i++){
  //      frontMovement();
  //    }
  //    for(int j = 0; j < 128; j++){
  //      girarDerecha();
  //    }
  //  }

} //FIN LOOP

void chooseMovement() {
  if (distance <= 15 && distance2 >= 10) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 32; j++) {
        frontMovement();
      }
    }

  }
  else if ((distance <= 40 && distance2 < 10) && (distance > 5 && distance2 > 3))
  {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 128; j++) {
        girarIzquierda();
      }
    }

  }
  else if (distance <= 5 && distance2 < 3)
  {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 8; j++) {
        girarIzquierda();
      }
    }

  }
  else if (distance > 15) {
    for (int m = 0; m < 2; m++) {
      for (int n = 0; n < 32; n++) {
        frontMovement();
      }

    }
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 64; j++) {
        girarDerecha();
        //girarDerecha();
      }
    }
  }
  calculateDistance();
  calculateDistance2();

}

void girarDerecha() {
  digitalWrite(motor1Pin1, LOW);
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
  digitalWrite(motor1Pin2, LOW);
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
  digitalWrite(motor1Pin3, LOW);
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
  digitalWrite(motor1Pin4, LOW);
  delay(motorSpeed);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor2Pin3, LOW);
  digitalWrite(motor2Pin4, LOW);
  delay(motorSpeed);


}

void girarIzquierda() {
  digitalWrite(motor1Pin1, HIGH);
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
  digitalWrite(motor1Pin2, HIGH);
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
  digitalWrite(motor1Pin3, HIGH);
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
  digitalWrite(motor1Pin4, HIGH);
  delay(motorSpeed);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor2Pin3, LOW);
  digitalWrite(motor2Pin4, LOW);
  delay(motorSpeed);


}

//FRONT MOVEMENT
void backwardsMovement() {
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
void frontMovement() {
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


void stopMovement() {
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

//DERECHO
void calculateDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); //2
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); //10
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  Serial.print(distance);
  Serial.print(" CM DERECHA  ");
  Serial.print(duration);
  Serial.println(" TM DERECHA");
}

//frente
void calculateDistance2() {
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2); //2
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); //10
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2 / 2) / 29.1;
  Serial.print(distance2);
  Serial.print(" CM FRENTE  ");
  Serial.print(duration2);
  Serial.println(" TM FRENTE");
}
