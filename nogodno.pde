import processing.sound.*;
import processing.serial.*;

Serial myPort;  // Create object from Serial class
String val;     // Data received from the serial port

// min threshhold when hover is deteced
int minVal = 400;
int upperLimit = 6000;

SoundFile sound;
SoundFile sound2;

void setup()
{
  printArray(Serial.list()); // print all ports
  String portName = Serial.list()[5]; //change the number 7 to match your port
  myPort = new Serial(this, portName, 9600);
  sound = new SoundFile(this, "nogod.wav");
  sound2 = new SoundFile(this, "base.wav"); 
}



void draw()
{
  if ( myPort.available() > 0) 
  {  // If data is available, read it and store into val
  val = myPort.readStringUntil('\n');         
  } 
  // if data is not null
  if (val != null && val!="") { 
    println(val); //print it out in the console
    
    //arduino prints to serial as string, need to transform that into something that proceessing to read 
    int number = Integer.parseInt(val.trim()); // convert string to integer
    if (number > minVal) { // if we are detecting touch or hover gesture
      number = constrain(number, minVal, upperLimit);
      float rate = map(number, minVal, upperLimit, 0.8, 1.8);
      float volume = map(number, minVal, upperLimit, 0, 1);
      if (!sound.isPlaying()){
        sound.play();
      }
      if (!sound2.isPlaying()){
        sound2.play();
      }
      sound.amp(volume);
      sound2.amp(0.5);
      sound2.rate(rate);

    } else {
        // stop the sound if no gesture is detected
        if (sound.isPlaying()) {
          sound.stop(); 
          sound2.stop();
        }
    }
  }
}
