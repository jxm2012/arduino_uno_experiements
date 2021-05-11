/*
 * Program for keypad to take input key and display output on 16x4 LCD module. 
 */
#include <Mouse.h>

//library for LCD displays and the keypad
#include <LiquidCrystal.h> 
#include <Keypad.h>

int keypad_position = 0; //keypad position

#define R 4
#define C 4

char keyPad_vals [R] [C] = { 

  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins [R] = {1, 2, 3, 4}; 
byte colPins [C] = {5, 6, 7, 8};

Keypad myKeypad = Keypad( makeKeymap(keyPad_vals), rowPins, colPins, R, C);

// pins of the LCD. (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd (A0, A1, A2, A3, A4, A5); 

#define redLED 10 //define the LED pins
#define greenLED 11

char* key = "8068";
void setup(){

  // Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(redLED, OUTPUT);  
  pinMode(greenLED, OUTPUT);
}

void loop(){

  //Serial.println("Hello");
  char key_pressed = myKeypad.getKey(); 

 // lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Input key: ");

  if(key_pressed == key [keypad_position]){

    keypad_position ++;
  }
  if(keypad_position == 4){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("verifying...");
    //lcd.clear();
    delay(3000);
    lcd.setCursor(0,1);
    lcd.print("Unlocked!");   
    delay(8000);
  }
  delay(100);
}
