long distancia;
long tiempo;
void setup(){
  Serial.begin(9600);
  pinMode(12, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode(13, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
}

void loop(){
  digitalWrite(12,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(5);
  digitalWrite(12, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo=pulseIn(13, HIGH); /* Función para medir la longitud del pulso entrante. Mide el tiempo que transcurrido entre el envío
  del pulso ultrasónico y cuando el sensor recibe el rebote, es decir: desde que el pin 12 empieza a recibir el rebote, HIGH, hasta que
  deja de hacerlo, LOW, la longitud del pulso entrante*/
  distancia= int(0.017*tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/
  /*Monitorización en centímetros por el monitor serial*/
  Serial.print(tiempo);
  Serial.print("s ");
  Serial.print(distancia);
  Serial.println(" cm");
  delay(100);
}
