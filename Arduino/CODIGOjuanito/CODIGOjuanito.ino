// Ultrasonic - Library for HR-SC04 Ultrasonic Ranging Module.
// Proyecto fin de curso:
// PRADUINO_BOT_113
// BOT RESUELVE LABERINTO
// By: Eumelvi

//se incluye una librería para el control de los sensores SRF05, 
//(la librería es para los HR-SC04, pero es válida para los SRF05)
//cortesía de www.ardublog.com
#include <Ultrasonic.h> 

//definir variables globales:
Ultrasonic ultra(7,6);   // asignamos los pines del sensor delantero llamado ultra(pulso7,Eco6)
Ultrasonic ultraDer(9,8);  // y para el derecho (Trig PIN,Echo PIN)
int motor1_a = 3; //asignamos los pines de los motores
int motor1_b = 4; //motor1=derecho
int motor2_c = 11; //motor2=izquierdo
int motor2_d = 12; //a-c=adelante/b-d=atrás

//se definen las funciones de los movimientos de motores (direcciones de avance)

void adelante() //creamos función()
{
  digitalWrite(motor1_a,HIGH); //se ponen en alto las salidas
  digitalWrite(motor1_b,LOW);  //a-c y en bajo b-d
  digitalWrite (motor2_c, HIGH); 
  digitalWrite (motor2_d, LOW);
}

void atras()
{
  digitalWrite(motor1_a,LOW);
  digitalWrite(motor1_b,HIGH);
  digitalWrite (motor2_c, LOW);
  digitalWrite (motor2_d, HIGH);
}

void paro()
{
  digitalWrite(motor1_a,LOW);
  digitalWrite(motor1_b,LOW);
  digitalWrite (motor2_c, LOW);
  digitalWrite (motor2_d, LOW);
}

void derecha()
{
  digitalWrite(motor1_a,LOW);
  digitalWrite(motor1_b,HIGH);
  digitalWrite (motor2_c, HIGH);
  digitalWrite (motor2_d, LOW);
}

void izquierda()
{
  digitalWrite(motor1_a,HIGH);
  digitalWrite(motor1_b,LOW);
  digitalWrite (motor2_c, LOW);
  digitalWrite (motor2_d, HIGH);
}

void corrDer()
{
  digitalWrite(motor1_a,HIGH);
  digitalWrite(motor1_b,LOW);
  digitalWrite (motor2_c, LOW);
  digitalWrite (motor2_d, LOW);
}

void corrIzq()
{
  digitalWrite(motor1_a,LOW);
  digitalWrite(motor1_b,LOW);
  digitalWrite (motor2_c, HIGH);
  digitalWrite (motor2_d, LOW);
}


void setup() 
{
  Serial.begin(9600); //inicializar las comunicaciones serie

  pinMode(motor1_a, OUTPUT); //pone en salida los pines de los motores
  pinMode(motor1_b, OUTPUT); 

  pinMode(motor2_c, OUTPUT); 
  pinMode(motor2_d, OUTPUT); 
}


void loop()
{
  Serial.print("delante: ");  //imprime en monitor
  Serial.print(ultra.Ranging(CM)); //escribe en CM or INC las medidas de los sensores
  Serial.print(" cm     " );  //imprime cm despues de los datos medidos
  delay(50); //espera hasta escribir la siguiente medicion

  Serial.print("derecha: ");
  Serial.print(ultraDer.Ranging(CM)); // CM or INC
  Serial.println(" cm" );
  delay(50);

  int cm, cm2; //declara las variables de las medidas de los sensores
  cm=ultra.Ranging(CM); //cm= a la medida en cm del sensor delantero
  cm2=ultraDer.Ranging(CM); //cm2= a la medida del derecho

  //aquí comienzan las órdenes y decisiones que tomará el bot.

if(cm2>5&&cm2<10)
{
  adelante();//avanza
  delay(10);//10ms
}

if(cm<8&&cm2>5)
{
  derecha();
  delay(1);
}

/*
if(cm2<9&&cm2>8)
  {
    adelante();   
    delay(1); 
    paro(); 
  }
  else 
  {
    if (cm2<8)  
    {  
      izquierda();   
      delay(1);
      paro();   
    }
    else
    {
      derecha();
      delay(1);
      paro();  
    }
  }*/
}

 
Citar
12/06/2013  
