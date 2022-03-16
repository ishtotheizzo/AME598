//leds 

int anaIn = A2;
int yellow = 10;
int green = 6; 
int flash1 = 12; 
int flash2 = 13; 
int flash3 = 14; 

int buttonswitch = 7; 
int vibes = 8; 

 

void setup() {
  pinMode(anaIn, INPUT); 
  pinMode(flash1, OUTPUT);
  pinMode(flash2, OUTPUT); 
  pinMode(flash3, OUTPUT); 
  pinMode(buttonswitch, INPUT); 
  pinMode(LED_BUILTIN, OUTPUT); 
  pinMode(yellow, OUTPUT); 
  pinMode(green, OUTPUT); 
  Serial.begin(9600); 
}

void loop() {


  delay(500);  

    int val = analogRead(anaIn); 
    Serial.println(val);
    digitalWrite(LED_BUILTIN, HIGH); 
    int digiVal = digitalRead(buttonswitch); 
    Serial.println(digiVal); 

    if(digiVal ==1)
    {
      analogWrite(vibes, 255); 
    }
    
    if(val <= 300)
    {
      digitalWrite(green, LOW); 
      digitalWrite(yellow, HIGH); 
      Serial.print("Yellow is reading at: "); 
      Serial.println(val); 
      digitalWrite(flash1, HIGH); 
      delay(500); 
      digitalWrite(flash1, LOW); 
      delay(500);
      digiVal = digitalRead(buttonswitch); 
      digiVal = digitalRead(vibes); 
      if(digiVal == 1)
        {
          analogWrite(vibes, 200);
        }

    }
  
    if(val > 300 && val <= 1023)
    {

      digitalWrite(green, HIGH); 
      digitalWrite(yellow, HIGH);  
      val = analogRead(anaIn); 
      Serial.print("Blue/Green is reading at: "); 
      Serial.println(val); 
      val = analogRead(anaIn);  
      Serial.println(val); 
      digitalWrite(flash1, HIGH); 
      delay(200); 
      digitalWrite(flash1, LOW); 
      delay(200); 
      digitalWrite(flash2, HIGH);
      delay(200); 
      digitalWrite(flash2, LOW); 
      delay(200); 
      digitalWrite(flash3, HIGH); 
      delay(200); 
      digitalWrite(flash3, LOW); 
      digiVal = digitalRead(vibes); 
      if(digiVal == 1)
        {
          analogWrite(vibes, 255);
        }  


    }
 

  digitalWrite(LED_BUILTIN, HIGH); 

  delay(200);
  

}
