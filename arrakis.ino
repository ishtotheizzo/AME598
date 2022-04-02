// adopted from www.elegoo.com
// adapted from class example 

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int lightPin = A0;  //light sensor pin
int ledPin = 8; 
int ledRed = 7;
void setup()
{
  pinMode(ledPin, OUTPUT); 
  pinMode(ledRed, OUTPUT); 
  lcd.begin(16, 2);
  Serial.begin(9600);
}
void loop()
{
  int lightValue = analogRead(lightPin);
  Serial.println(lightValue);   // for debug
  lcd.clear();                  // clear LCD 
  lcd.setCursor(0, 0);          // reset cursor position
  // print a message based on light sensor value
  // your threshholds might be different
  if (lightValue < 700 && lightValue > 0) {
    lcd.print("NIGHT");
    digitalWrite(ledPin, HIGH); 
    digitalWrite(ledRed, LOW);
  } else if (lightValue < 710 && lightValue > 700) {
     lcd.print("early morning");
     
  } 

  else if (lightValue < 770 && lightValue > 711)
  {
    lcd.print("WARNING MORNING");
    digitalWrite(ledRed, HIGH); 
    digitalWrite(ledPin, LOW);
  }

  else if( lightValue > 771 && lightValue < 800)
  {
    lcd.print("WARNING AFTERNOON - UV LEVELS CRITICAL"); 
    digitalWrite(ledRed, HIGH); 
    digitalWrite(ledPin, LOW);
  }
  else {
    lcd.print("GET BACK INSIDE");
    digitalWrite(ledPin, LOW);
    digitalWrite(ledRed, HIGH);
    delay(100); 
    digitalWrite(ledRed, LOW);  
    delay(100); 
  }  
  delay(500);
}
