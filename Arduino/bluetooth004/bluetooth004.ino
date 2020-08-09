#include <SoftwareSerial.h>
SoftwareSerial BT1(0,1); // RX, TX recorder que se cruzan

void setup()
   {
       Serial.begin(9600);
       Serial.println("Enter AT commands:");
       BT1.begin(9600);
   }

void loop()
   {
       if (BT1.available())
           Serial.write(BT1.read());
       
       if (Serial.available()>0)
          {  String S = GetLine();
             BT1.print(S);
             Serial.println("---> " + S);
          }
}

String GetLine()
   {   String S = "" ;
       if (Serial.available()>0)
          {    char c = Serial.read(); ;
                while ( c != '\n')            //Hasta que el caracter sea intro
                  {     S = S + c ;
                        delay(25) ;
                        c = Serial.read();
                  }
                return( S + '\n') ;
          }
   }
