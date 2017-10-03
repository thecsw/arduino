//Sagindyk Urazayev
#include <OneWire.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
OneWire iButton(10); // создаём объект 1-wire на 10 выводе

bool found = false;

void nok() {
  if (!found) {
  for (int i = 0; i < 3; i++) {
     lcd.setCursor(15+i, 1);
     lcd.print('.');
     delay(1000);
     }
    lcd.setCursor(15, 1);
    lcd.print("   ");
    }
  }

 void granted() {
  lcd.clear();
  lcd.setCursor(3, 1);
  lcd.print("ACCESS GRANTED");
  lcd.setCursor(3, 2);
  lcd.print("Welcome, Sandy");
  digitalWrite(9, HIGH);
  found = true;
  }

  void notg() {
    lcd.clear();
    lcd.setCursor(3, 1);
    lcd.print("ACCESS DENIED");
    lcd.setCursor(7, 2);
    lcd.print("WAIT");
    for (int i = 9; i >= 0; i--) {
      lcd.setCursor(12, 2);
      lcd.print(i);
      delay(1000);
      }
    }

void setup (void) {
  lcd.begin(20, 4);
  lcd.clear();
  found = false;
  lcd.setCursor(2, 1);
  lcd.print("NOT CONNECTED");
  digitalWrite(9, LOW);
}

void loop(void) {
  delay(1000); // задержка 1 сек 
  byte addr[8]; // массив для хранения данных ключа
  if (!found) {
    lcd.clear();
    lcd.setCursor(2, 1);
    lcd.print("NOT CONNECTED");
  } if ( !iButton.search(addr) ) { // если ключ не приложен
      nok();
      return; 
  }
  if (addr[0] == 1 && addr[1] == 143 && addr[2] == 52 && addr[3] == 225 
  && addr[4] == 1 && addr[5] == 0 && addr[6] == 0 && addr[7] == 5) {
    granted();  
    } else {
      notg();
      }
  iButton.reset(); // сброс ключа
}
