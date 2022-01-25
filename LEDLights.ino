/*
 SEVEN NATION ARMY 
 by Ishrat Lallmamode 
 Blinks 3 LED lights in time with a beat
*/


// FIRST INITIALIZE LEDS

int LEDBlue = 10;  
int LEDGreen = 9; 
int LEDRed = 11; 

int i = 0; // i represents when the other LEDs chime in 


void setup() {
  // initialize digital pins  as an output.
  pinMode(LEDBlue, OUTPUT);
  pinMode(LEDGreen, OUTPUT); 
  pinMode(LEDRed, OUTPUT); 
}


// the loop function runs over and over again forever
void loop() {

    digitalWrite(LEDBlue, HIGH); 
    delay(500); 
    digitalWrite(LEDBlue, LOW);
    delay(500);

    if(i>=3)
    {
      digitalWrite(LEDGreen, HIGH); 
      delay(500); 
      digitalWrite(LEDGreen, LOW);
      delay(500);
      
    }

    if(i>=5)
    {
      digitalWrite(LEDRed, HIGH); 
      delay(250); 
      digitalWrite(LEDRed, LOW);
      delay(250);
      
    }

    digitalWrite(LEDBlue, HIGH); 
    delay(250); 
    digitalWrite(LEDBlue, LOW);
    delay(250); 


    
    if(i>=3)
    {
      digitalWrite(LEDGreen, HIGH); 
      delay(500); 
      digitalWrite(LEDGreen, LOW);
      delay(500);
    }

    if(i>=5)
    {
      digitalWrite(LEDRed, HIGH); 
      delay(250); 
      digitalWrite(LEDRed, LOW);
      delay(250);
      
    }

    digitalWrite(LEDBlue, HIGH); 
    delay(250); 
    digitalWrite(LEDBlue, LOW);
    delay(250);

    
    if(i>=3)
    {
      digitalWrite(LEDGreen, HIGH); 
      delay(500); 
      digitalWrite(LEDGreen, LOW);
      delay(500);
      
    }

    
    if(i>=5)
    {
      digitalWrite(LEDRed, HIGH); 
      delay(250); 
      digitalWrite(LEDRed, LOW);
      delay(250);
      
    }

    digitalWrite(LEDBlue, HIGH); 
    delay(250); 
    digitalWrite(LEDBlue, LOW);
    delay(250);

    
    if(i>=3)
    {
      digitalWrite(LEDGreen, HIGH); 
      delay(500); 
      digitalWrite(LEDGreen, LOW);
      delay(500);
      
      
    }

    
    if(i>=5)
    {
      digitalWrite(LEDRed, HIGH); 
      delay(250); 
      digitalWrite(LEDRed, LOW);
      delay(250);
      
    }

    digitalWrite(LEDBlue, HIGH); 
    delay(250); 
    digitalWrite(LEDBlue, LOW);
    delay(250);

    
    if(i>=3)
    {
      digitalWrite(LEDGreen, HIGH); 
      delay(500); 
      digitalWrite(LEDGreen, LOW);
      delay(500);
      
    }

    if(i>=5)
    {
      digitalWrite(LEDRed, HIGH); 
      delay(250); 
      digitalWrite(LEDRed, LOW);
      delay(250);
      
    }

    digitalWrite(LEDBlue, HIGH); 
    delay(750); 
    digitalWrite(LEDBlue, LOW);
    delay(750);

    if(i>=3)
    {
      digitalWrite(LEDGreen, HIGH); 
      delay(500); 
      digitalWrite(LEDGreen, LOW);
      delay(500);
      
    }
    if(i>=5)
    {
      digitalWrite(LEDRed, HIGH); 
      delay(250); 
      digitalWrite(LEDRed, LOW);
      delay(250);
      
    }

    digitalWrite(LEDBlue, HIGH); 
    delay(750); 
    digitalWrite(LEDBlue, LOW);
    delay(750);

    if(i>=3)
    {
      digitalWrite(LEDGreen, HIGH); 
      delay(500); 
      digitalWrite(LEDGreen, LOW);
      delay(500);
      
    }

    if(i>=5)
    {
      digitalWrite(LEDRed, HIGH); 
      delay(250); 
      digitalWrite(LEDRed, LOW);
      delay(250);
      
    }

    i = i+1;


    Serial.println(i); 

}
