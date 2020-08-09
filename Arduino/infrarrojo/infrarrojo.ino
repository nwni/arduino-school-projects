//
//int pinReceptor = A0; //Guardamos en esta variable el pin Analógico
//int sensorVal;
//int led = 13;
//void setup(){
//Serial.begin(9600); // Abrir comunicación por Serial
//pinMode(led, OUTPUT);
//}
//void loop(){
//sensorVal = analogRead(pinReceptor);
//Serial.println(sensorVal); // Leer el valor del Pin y escribirlo
//if(sensorVal == HIGH){
//  digitalWrite(led, sensorVal);
//}
//else{
//  digitalWrite(led, sensorVal);
//led
//delay(100);
//}

int input = A0;
int output = 13;
int val = 0;
  
void setup() {
  Serial.begin(9600);
  pinMode(input, INPUT);
  pinMode(output, OUTPUT);
}

void loop() {
  val = analogRead(input);
  Serial.println(val);
//  delay(500);
  if (val>1022) {
    digitalWrite(output, LOW);
    }
    else {
      digitalWrite(output, HIGH);
      }
}
