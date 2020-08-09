#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h> 



LiquidCrystal_I2C lcd(0x3f, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.print("QUE HAY DE TAREA?");
  delay(500);

}

void loop() {
  // scroll 13 positions (string length) to the left
  // to move it offscreen left: MOVERLO A LA IZQ, FUERA DE LA PANTALLA
  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(300);
  }

  // scroll 29 positions (string length + display length) to the right
  // to move it offscreen right: MOVERLO A LA DERECHA, FUERA DE LA PANTALLA
  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(300);
  }

  // scroll 16 positions (display length + string length) to the left
  // to move it back to center: CENTRARLO
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(800);
  }
  delay(1000);
}
