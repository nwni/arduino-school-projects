const int SensorPin = 12;
const int LEDPin = 13;
 
void setup() {
    pinMode(SensorPin , INPUT);
    digitalWrite(SensorPin , HIGH);    //activamos la resistencia interna PULL UP
    pinMode(LEDPin, OUTPUT);
}
 
void loop() {
    if (digitalRead(SensorPin)) {
        digitalWrite(LEDPin, HIGH);
    }  else {
        digitalWrite(LEDPin, LOW);
    }
}
