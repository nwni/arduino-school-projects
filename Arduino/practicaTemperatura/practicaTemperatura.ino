float temp;
int tempPin = A5;
int azul = 3;
int verde = 5;
int rojo = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  temp = analogRead(tempPin);
  temp = temp * 0.48828125;
  Serial.print("Temperatura = ");
  Serial.print(temp);
  Serial.print(" C");
  Serial.println();

  Serial.println(temp);
  if(temp < 22){
    digitalWrite(azul, HIGH);
    digitalWrite(rojo, LOW);
    digitalWrite(verde, LOW);
  }else if(temp >= 22 && temp < 26){
    digitalWrite(verde, HIGH);
    digitalWrite(rojo, LOW);
    digitalWrite(azul, LOW); 
   }else{
      digitalWrite(verde, LOW);
      digitalWrite(azul, LOW);
      digitalWrite(rojo, HIGH);
    }
    delay(500);
}
