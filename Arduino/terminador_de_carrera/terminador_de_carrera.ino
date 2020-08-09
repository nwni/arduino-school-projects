/*************************************************************
11460268
11460247
11460262
**************************************************************/
int pulsador = 5; //Definimos el puerto del pulsador
int led = 13; //LED de salida para ver el estado
void setup(){
pinMode(pulsador, INPUT); //Declaramos el interruptor como entrada
pinMode(led, OUTPUT); //Declaramos el led como salida
Serial.begin(9600); //Iniciamos la comunicacion Serial
}
void loop(){
boolean estado = analogRead(pulsador); //Leemos el estado del interruptor
digitalWrite(led, estado); //Escribimos en el LED el estado del interruptor
if(estado == 1)
  digitalWrite(led, estado); //Escribimos en el LED el estado del interruptor
else
  digitalWrite(led, estado); //Escribimos en el LED el estado del interruptor
}
