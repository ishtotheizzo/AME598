// map the different colors 

int mapGreen; 
int mapRed; 
int mapBlue; 

// create game quantifiers. if they get the signal, they can keep their light on

bool blue = false; 
bool green = false; 
bool red = false; 

// pentiometer 

int analogIn = A2;
int value = 0;


int mapValue = 0; 

// digital pins 

const int digBlue = 9; // digital blue 
const int digRed = 8; // digital red 
const int digGreen = 10;

// PEW out 

const int anaBlue = 3; 
const int anaRed = 5; 
const int anaGreen = 6;


void setup() {

  pinMode(analogIn, INPUT);
  pinMode(digBlue, OUTPUT); 
  pinMode(digRed, OUTPUT); 
  pinMode(digGreen, OUTPUT); 
  pinMode(anaBlue, OUTPUT); 
  pinMode(anaRed, OUTPUT); 
  pinMode(anaGreen, OUTPUT); 

  
  Serial.begin(9600);
  

}



void loop() {
  
  // this is the "SIGNAL SUCCESSFUL" 

   if(blue == true && green == true && red == true)
  {
    digitalWrite(digBlue, HIGH); 
    digitalWrite(digGreen, HIGH);
    digitalWrite(digRed, HIGH); 

    Serial.print("We have not heard the music of the spheres,\r The song of star to star, but there are sounds\fMore deep than human joy and human tears,\rThat Nature uses in her common rounds;\rThe fall of streams, the cry of winds that strain\rThe oak, the roaring of the sea’s surge, might\fOf thunder breaking afar off, or rain\rThat falls by minutes in the summer night\r");
  }





  delay(150); // stabilize reading 
  value = analogRead(analogIn);
  Serial.print("sensor value: ");
  Serial.println(value);

// this is if the signal is too low 
  
  if(value <=256) 
  {
     
      establishConnection();
 
    
  } 

  
  // if in range of "blue"
  if(value>256 && value<=512)
  {
    mapBlue = map(value, 0, 512, 0, 255);  
    analogWrite(anaBlue, mapBlue);

    if(mapBlue >= 200 && mapBlue <=255)
    {

      Serial.print("I am an Alien"); 
      Serial.println(" "); 
      blue = true; 
      digitalWrite(digBlue, HIGH); 
      
    }

  }

  // this is the range for Green 
  
  
 if(value>512 && value<=768)
 {
  mapGreen = map(value, 513, 768, 0, 255); 
  analogWrite(anaGreen, mapGreen); 

  if(mapGreen >= 200 && mapBlue <=255)
  {
    Serial.print("I want to learn about Earth");
    Serial.println(" ");
    green = true; 
    digitalWrite(digGreen, HIGH); 
  }
 }

  
  // this is the range for red 
if(value > 768 && 1024) 
{
  mapRed = map(value, 769, 1000, 0, 255); 
  analogWrite(anaRed, mapRed); 

  if(mapRed >= 200 && mapRed <=255)
  {
    Serial.print("It looks like a lovely place");
    Serial.println(" ");
    red = true; 
    digitalWrite(digRed, HIGH); 
  }
}


   

  
  
}


// this function handles the digital outputs of the lights because the code was too long 

void establishConnection () 
{
  Serial.println("establishing connection.......");

  if(blue == false && green == false && red == false)
  {
    
     digitalWrite(digRed, HIGH);
     delay(500); 
     digitalWrite(digRed, LOW); 
     delay(250); 
     digitalWrite(digBlue, HIGH);
     delay(500); 
     digitalWrite(digBlue, LOW); 
     delay(250);
     digitalWrite(digGreen, HIGH);
     delay(500); 
     digitalWrite(digGreen, LOW);
     delay(500); 
     digitalWrite(digRed, HIGH);
     delay(250);
     digitalWrite(digBlue, HIGH);
     delay(250); 
     digitalWrite(digGreen, HIGH);
     delay(250); 
     digitalWrite(digRed, LOW);
     delay(250); 
     digitalWrite(digBlue, LOW);
     delay(250); 
     digitalWrite(digGreen, LOW);
     delay(250); 
  }

  if(blue == true)
  {
     digitalWrite(digBlue, HIGH);
  }

  else

  {
    analogWrite(anaBlue, 0); 
  }

  if(green == true)
  {
    digitalWrite(digGreen, HIGH); 
  }

  else
  {
    analogWrite(anaGreen, 0); 
  }

  if(red == true)

  {
    digitalWrite(digRed, HIGH);
  }

  else
  {
    analogWrite(anaRed, 0); 
  }

 

  
}

