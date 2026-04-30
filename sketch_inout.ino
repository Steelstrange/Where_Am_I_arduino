#include <LiquidCrystal_I2C.h>
//initialize the liquid crystal library
LiquidCrystal_I2C lcd(0x27, 16, 2);

//status vars
String ajStatus = "IN";
String andrewStatus = "OUT";

void setup() {
  //initialize lcd screen
  lcd.begin();
  // turn on the backlight
  lcd.backlight();
  //wait  for a second
  delay(1000);
  updateDisplay();
}
void loop() {
}

void updateDisplay(){
  // tell the screen to write on the top row
  lcd.setCursor(0, 0);
  lcd.print("AJ:");
  lcd.setCursor(16 - ajStatus.length(), 0); //this alligns the text to the right
  lcd.print(ajStatus);

  lcd.setCursor(0, 1);
  lcd.print("Andrew:");
  lcd.setCursor(16 - andrewStatus.length(), 1);
  lcd.print(andrewStatus);
}
