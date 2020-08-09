/*Practica 2: Uso de botones
Al presionar el boton se enciende o se apaga dependiendo
del estado en que se encuentre*/

int estado = 0; //se declara una variable
int estadoAnterior = 0; //Guarda el estado anterior del boton
int salida = 0; //0= LED apagado, 1= LED encendido
int led=A0;
void setup() {
  //pinMode(A0, INPUT); //declaramos el boton como entrada
  pinMode(13, OUTPUT); //declaramos el LED como salida
}

void loop(){
  estado = analogRead(5);   //Leer el estado del boton

  if(estado==1) {   //Si estado esta en alto
    digitalWrite(13, HIGH);  //encendemos el LED
  } 
  else {
    digitalWrite(13, LOW); //Apagamos el LED
  }
}
