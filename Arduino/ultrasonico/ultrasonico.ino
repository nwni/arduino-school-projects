#include <NewPing.h>

#define TRIGGER_PIN 12
#define ECHO_PIN 13
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int uS, totalDistance;
void setup(){
  Serial.begin(9600);
}

void loop(){
  delay(500);
  uS = sonar.ping_median();
  totalDistance = uS/US_ROUNDTRIP_CM;
  Serial.print("Distancia: ");
  Serial.print(totalDistance);
  Serial.println("cm");
}

