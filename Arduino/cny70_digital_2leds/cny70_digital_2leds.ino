/* Programa que utiliza el sensor infrarrojos CNY70 como entrada digital para encender o apagar dos LEDs

El CNY70 está cableado para que al estar sobre negro lea un '1'; y si está sobre blanco lea un '0'

Se puede encontrar el cableado del CNY70 en el documento que hay en el archivo descomprimido

Si el sensor de infrarrojos está sobre negro, la entrada digital 8 tendrá el valor '1': un LED se encenderá y 
la entrada digital 9 tendrá el valor '0': el otro LED se apagará 
Si el sensor de infrarrojos está sobre blanco, la entrada digital 8 tendrá el valor '0', un LED se apagará
y la entrada digital 9 tendrá el valor '1': el otro LED se encenderá 

Basado en un programa encontrado en http://wiki.medialab-prado.es/ 

Por Julio Megía, liberado para la Comunidad */


int ledPin1 = 8;     // pin de un LED 
int ledPin2 = 9;      // pin de otro LED
int infraPin = 4;    // pin del infrarrojos utilizado como entrada digital
int valorInfra = 0;  // Valor inicial de la lectura digital del infrarrojos. 



void setup() { 
  pinMode(ledPin1, OUTPUT);     // Inicializa el pin del LED1 como salida digital
  pinMode(ledPin2, OUTPUT);     // Inicializa el pin del LED2 como salida digital
  pinMode(infraPin, INPUT);    // Inicializa el pin 4 como entrada digital
} 


void loop() { 
  valorInfra = digitalRead(infraPin);    // Lee el valor de la entrada 4, esto es, el valor que lee el infrarrojo
  digitalWrite(ledPin1, valorInfra);     /* Escribe en el pin 8 el valor que lee la entrada 4, esto es, el mismo valor que lee el infrarrojo
                                         Si el infrarrojo lee 0, entonces, el LED estará apagado
                                         Si el infrarrojo lee 1, entonces, el LED estará encendido */ 
  valorInfra = !valorInfra;              // Se asigna a valorInfra el valorInfra negado. Si valorInfra es 1, el nuevo valorInfra será 0; y viceversa
  digitalWrite(ledPin2, valorInfra);     /* Escribe en el pin 9 el valor negado que lee la entrada 4, esto es, el negado del valor que lee el infrarrojo
                                         Si el infrarrojo lee 0, entonces, el LED conectado al pin 9 estará encendido
                                         Si el infrarrojo lee 1, entonces, el LED conectado al pin 9 estará apagado */ 
}
 
