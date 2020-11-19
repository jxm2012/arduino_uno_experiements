//Simple program which takes checks to see if enough light reaches photo resistor
//and turns on warning light if not
int red = 10;
int photo_resistorPin = A0;
int light_resistance;
int light_delay = 100; //100 milliseconds

void setup() {
  // put your setup code here, to run once:
  pinMode(photo_resistorPin,INPUT);
  pinMode(red,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  light_resistance = analogRead(photo_resistorPin);
  Serial.print("Value of Light is: ");
  Serial.println(light_resistance);
  delay(light_delay);

  if(light_resistance<110)
  {
    Serial.print("Turning on warning light\n");
    digitalWrite(red,HIGH);
    delay(2000);
    digitalWrite(red,LOW);
    delay(2000);
  }
  
}
