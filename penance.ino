//THE PENITENT MAN SHALL PASS


// inputs 
int wirePin = 9; //wire write  
int dial = A0;  //pentiometer to control how "penitent" you are 
int LEDGreen = 3;  // LED to represent your "ascention" 




void setup() {
  
  pinMode(wirePin, OUTPUT); 
  pinMode(dial, INPUT);  
  pinMode(LEDGreen, OUTPUT); 
  Serial.begin(9600);
}

void loop() {


  int state = analogRead(dial); 
  int mapGreen= map(state, 0, 1000, 0, 255);
  delay(500);
  analogWrite(LEDGreen, mapGreen);

  Serial.println(mapGreen);
  
  if(mapGreen >= 150 && mapGreen <=255)
  {
    digitalWrite(wirePin, HIGH); 
    Serial.println("THE PENITENT MAN SHALL PASS"); 
    delay(1000);
  }

  else
  {
    digitalWrite(wirePin, LOW);
  }
 
  
}
