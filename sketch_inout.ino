#include <LiquidCrystal_I2C.h>
//initialize the liquid crystal library
LiquidCrystal_I2C lcd(0x27, 16, 2);

//declare user strings
int aj = 0; int andrew = 0; int thatcher = 0; int charles = 0;

//declare an array storing possible statuses
//because of how long thatcher the raptors name is, we only get 6 characters to work with
const String status[] = {"Out", "In", "Busy"};

void setup() {
  //initialize lcd screen
  lcd.begin();
  lcd.backlight();

  //wait  for a second
  delay(1000);
  updateDisplay(0);
}
void loop() {
  delay(2000);
  aj = 1;
  andrew = 2;
  updateDisplay(0);
  delay(2000);
  thatcher = 2;
  charles = 0;
  updateDisplay(1);
}

//this method displays the status a pair of students, either aj and andrew on mode 0, or charles and thatcher on mode 1
void updateDisplay(int mode){
  //first clear the screen
  lcd.clear();

  if(mode == 0)
  {
    //now set the cursor in the top left and print the first status
    lcd.setCursor(0, 0);
    lcd.print("AJ:");
    lcd.setCursor((16 - status[aj].length()), 0); //this right justifies the text
    lcd.print(status[aj]);

    //now write the next out on the next line
    lcd.setCursor(0, 1);
    lcd.print("Andrew:");
    lcd.setCursor((16 - status[andrew].length()), 1);
    lcd.print(status[andrew]);
  }
  else if(mode == 1)
  {
    //now set the cursor in the top left and print the first status
    lcd.setCursor(0, 0);
    lcd.print("Charles:");
    lcd.setCursor((16 - status[charles].length()), 0); //this right justifies the text
    lcd.print(status[charles]);

    //now write the next out on the next line
    lcd.setCursor(0, 1);
    lcd.print("Thatcher:");
    lcd.setCursor((16 - status[thatcher].length()), 1);
    lcd.print(status[thatcher]);
  }
}
