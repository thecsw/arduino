#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
//LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void chor(String fl, String sl, String tl, String fol) {
  outp(fl, 0, 0, 1);
  outp(sl, 0, 1, 1);
  outp(tl, 0, 2, 1);
  outp(fol, 0, 3, 1);
  clr();
  delay(100);
  }

void outp(String text, int a, int b, int d) {
  if (d == 1) delay(400);
  lcd.setCursor(a, b);
  lcd.print(text);
  }

void clr() {
    delay(300);
    for (int i = 0; i < 4; i++) {
        outp("                    ", 0, i, 0);
    }
}

void setup() {
  lcd.clear();
  lcd.begin(20, 4);
}
    
void loop() {
  for (byte i = 0; i < 14; i++) {
    switch(i) {
      case 0:
      chor(
      "Work it", 
      "Make it", 
      "Do it", 
      "Make us");
      case 1:
      chor(
      "Harder", 
      "Better", 
      "Faster", 
      "Stronger");
      case 2:
      chor(
      "More than", 
      "Hour", 
      "Our", 
      "Never");
      case 3:
      chor(
      "Ever", 
      "After", 
      "Work is", 
      "Over");
      case 4:
      chor(
      "Work it", 
      "Make it", 
      "Do it", 
      "Make us");
      case 5:
      chor(
      "Harder", 
      "Better", 
      "Faster", 
      "Stronger");
      case 6:
      chor(
      "Work it harder", 
      "Make it better", 
      "Do it faster", 
      "Makes us stronger");   
      case 7:
      chor(
      "More than ever", 
      "Hour after", 
      "Our work is", 
      "Never over");
      case 8:
      chor(
      "Work it harder", 
      "Make it better", 
      "Do it faster", 
      "Makes us stronger");   
      case 9:
      chor(
      "Work it harder", 
      "Make it better", 
      "Do it faster", 
      "Makes us stronger");  
      case 10:
      chor(
      "Work it harder", 
      "Make it better", 
      "Do it faster", 
      "Makes us stronger");
      case 11:
      chor(
      "Work it harder", 
      "Make it better", 
      "Do it faster", 
      "Makes us stronger");
      case 12:
      chor(
      "Work it harder", 
      "Make it better", 
      "Do it faster", 
      "Makes us stronger");
      case 13:
      chor(
      "Work it harder", 
      "Make it better", 
      "Do it faster", 
      "Makes us stronger");     
    }
  }
}
