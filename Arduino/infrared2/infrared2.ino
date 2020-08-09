int tcrt;
void setup(){
pinMode(13,OUTPUT);
Serial.begin(9600);
}
void loop(){
//int sensorValue = analogRead(A0);
//Serial.println(sensorValue);
analogWrite(13,tcrt/4);
Serial.println(tcrt);
delay(250);
}
