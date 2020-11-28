/*Simple program to display text on the LCD 1602 module using Arduino Uno
 * 
 * RS to ground rail
 * VDD, 5V, A(anode) to positive rail
 * VSS, K (cathode) to negative rail. Similar layout for potentiometer
 * V0 to Potentiometer (10K)
 */


//including library for communication with the LCD
#include <LiquidCrystal.h>

//constants created for different pins on the LCD 1602 Module
int register_select = 7; //RS
int enable = 8; //E

//data pins
int D4 = 9;
int D5 = 10;
int D6 = 11;
int D7 = 12;

//1 & 2 millisecond delays
int one_msDelay = 1000;
int two_msDelay = 2000;

//LCD display matrix: size of 16 columns x 2 rows
int sixteen = 16;
int two = 2; 

//creating the object for LCD for using the library
//parameters set for register select (RS), enable (E), and data pins
LiquidCrystal lcd_disp(register_select, enable, D4, D5, D6, D7);

void setup() {
  // put your setup code here, to run once:
  lcd_disp.begin(sixteen,two);
}

//prints simple statement using the LCD object
//in reference to Mr Robot show
void loop() {
  // put your main code here, to run repeatedly:
  lcd_disp.setCursor(0,0);
  lcd_disp.print("Bonsoir, Elliot");
  delay(one_msDelay);

  lcd_disp.setCursor(0,0);
  lcd_disp.print("R u a 0 or 1 ...");
  delay(two_msDelay);
  lcd_disp.clear();
}
