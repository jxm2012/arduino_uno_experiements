/* 
 First Program:
 * Experimenting with different colors 
 * and simple functions in Arduino Uno using RGB LED
 * Output pins to connect to for the LED:
 * Red = 4
 * Green = 5
 * Blue = 6
 * 
 * 
 */

int red= 4;
int green = 5;
int blue = 6;
//boolean condition = true;

//Wait Time or delay between each light for show switching between 
//lights properly
int waitTime = 600; 

//new delay assigned for looping through colors --- testing
int specialDelay = 2000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
   Serial.println("Flashing lights: \n");
   turnOn_red();
   delay(waitTime);
   turnOn_green();
   delay(waitTime);
   turnOn_blue();
   delay(waitTime);
   turnOn_magenta();
   delay(waitTime);
   turnOnCyan();
   delay(waitTime);
   turnOnyellow();
   delay(waitTime);
   newColor();
   delay(waitTime);
 //  randomizer();
   delay(waitTime);
   turnOff();
  
}

void randomizer()
{
  for(int i=0;i<255;i++)
  {
    analogWrite(red, i);
    analogWrite(green, i);
    analogWrite(blue, i);
    delay(specialDelay);
  }
}

void turnOn_red()
{
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
}

void turnOn_green()
{
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
}

void turnOn_blue()
{
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
}


void turnOn_magenta()
{
    analogWrite(red, 255);
    analogWrite(green, 0);
    analogWrite(blue, 100);
}

void turnOnCyan()
{
    analogWrite(red, 0);
    analogWrite(green, 255);
    analogWrite(blue, 255);
}

void turnOnyellow()
{
    analogWrite(red, 255);
    analogWrite(green, 100);
    analogWrite(blue, 0);
}

//random values to create new color
void newColor()
{
    analogWrite(red, 200);
    analogWrite(green, 75);
    analogWrite(blue, 75);
}

//final turn off all colors, loops back to red
void turnOff()
{
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
}
