#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;


// the used PINs
const int s0=4;
const int s1=5;
const int s2=6;
const int s3=7;
const int sensorData=8;

// Global variable to store data

int dataR=0;
int dataG=0;
int dataB=0;

void setup() 
{

  mySoftwareSerial.begin(9600);
  Serial.begin(9600);

  Serial.println();
  Serial.println(F("Booting Colour Recognition System"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.setTimeOut(500); //Set serial communictaion time out 500ms

  //----Set volume----
  myDFPlayer.volume(60);  //Set volume value (0~30).
  myDFPlayer.volumeUp(); //Volume Up
  myDFPlayer.volumeDown(); //Volume Down

  //----Set different EQ----
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
  //----Set device we use SD as default----
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);

   pinMode(s0,OUTPUT);
   pinMode(s1,OUTPUT);
   pinMode(s2,OUTPUT);
   pinMode(s3,OUTPUT);
   pinMode(sensorData,INPUT);
  // Serial.begin(9600);

   digitalWrite(s0,HIGH);
   digitalWrite(s1,LOW);
   
}

void loop()
{
   digitalWrite(s2,LOW);
   digitalWrite(s3,LOW);
   dataR=pulseIn(sensorData,LOW);
   delay(20);

   digitalWrite(s2,HIGH);
   digitalWrite(s3,HIGH);
   dataG=pulseIn(sensorData,LOW);
   delay(20);

   digitalWrite(s2,LOW);
   digitalWrite(s3,HIGH);
   dataB=pulseIn(sensorData,LOW);
   delay(20);
   
   if(isRed())
   {
    myDFPlayer.playFolder(1, 3); 
    Serial.println("this is the RED color");
    delay(3000);
    
   }

    if(isRed2())
   {
    myDFPlayer.playFolder(1, 3);  
    Serial.println("this is the RED color");
    delay(3000);
   }
   if(isBlue())
   {
    myDFPlayer.playFolder(1, 5);  
    Serial.println("this is the Blue color");
    delay(3000);
    
   }
     if(isBlue2())
   {
    myDFPlayer.playFolder(1, 5); 
    Serial.println("this is the Blue color");
    delay(3000);
    
   }
   if(isGreen())
   {
    myDFPlayer.playFolder(1, 4); 
    Serial.println("this is the GREEN color");
    delay(3000);
    
   }

    if(isGreen2())
   {
    myDFPlayer.playFolder(1, 4);  
    Serial.println("this is the GREEN color");
    delay(3000);
   }

   if(isGreen3())
   {
    myDFPlayer.playFolder(1, 4); 
    Serial.println("this is the GREEN color");
    delay(3000);
   }
   if(isYellow())
   {
    myDFPlayer.playFolder(1, 6); 
    Serial.println("this is the YELLOW color");
    delay(3000);
    
    
   }

  if(isYellow2())
   {
    myDFPlayer.playFolder(1, 6);  
    Serial.println("this is the YELLOW color");
    delay(3000);
   }
   
   if(isOrange())
   {
    myDFPlayer.playFolder(1, 7);  
    Serial.println("this is the Orange color");
    delay(3000);
   }

  if(isOrange2())
   {
    myDFPlayer.playFolder(1, 7);  
    Serial.println("this is the Orange color");
    delay(3000);
   }
   if(isOrange3())
   {
    myDFPlayer.playFolder(1, 7);  
    Serial.println("this is the Orange color");
    delay(3000);
   }
   
   if(isWhite())
   {
    myDFPlayer.playFolder(1, 2);  
    Serial.println("this is the White color");
    delay(3000);
   }

   if(isBlack())
   {
    myDFPlayer.playFolder(1, 1);  
    Serial.println("this is the Black color");
    delay(3000);
   }

    if(isBrown())
   {
    myDFPlayer.playFolder(1, 10);  
    Serial.println("this is the Brown color");
    delay(3000);
   }

   if(isBrown2())
   {
    myDFPlayer.playFolder(1, 10);  
    Serial.println("this is the Brown color");
    delay(3000);
   }
   
    if(isPurple())
   {
    myDFPlayer.playFolder(1, 9);  
    Serial.println("this is the Purple color");
    delay(3000);
   }
    if(isPink())
   {
    myDFPlayer.playFolder(1, 8);  
    Serial.println("this is the Pink color");
    delay(3000);
   }

   if(isPink2())
   {
    myDFPlayer.playFolder(1, 8);  
    Serial.println("this is the Pink color");
    delay(3000);
   }
}

bool isRed()
{
  if((dataR<60 && dataR>10) && (dataG<195 && dataG>135) && (dataB<135 && dataB>90))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isRed2()
{
  if((dataR<60 && dataR>30) && (dataG<205 && dataG>185) && (dataB<155 && dataB>130))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isGreen()
{
  if((dataR<100 && dataR>68) && (dataG<50 && dataG>18) && (dataB<90 && dataB>52))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isGreen2()
{
  if((dataR<145 && dataR>115) && (dataG<110 && dataG>18) && (dataB<145 && dataB>110))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isGreen3()
{
  if((dataR<115 && dataR>90) && (dataG<85 && dataG>60) && (dataB<145 && dataB>115))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isBlue()
{
  if((dataR<210 && dataR>170) && (dataG<115 && dataG>67) && (dataB<67 && dataB>27))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isBlue2()
{
  if((dataR<135 && dataR>105) && (dataG<70 && dataG>50) && (dataB<55 && dataB>25))
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool isYellow()
{
  if((dataR<40 && dataR>0) && (dataG<50 && dataG>10) && (dataB<70 && dataB>30))
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool isYellow2()
{
  if((dataR<45 && dataR>25) && (dataG<50 && dataG>10) && (dataB<80 && dataB>60))
  {
    return true;
  }
  else
  {
    return false;
  }
}



bool isOrange()
{
  if((dataR<36 && dataR>-4) && (dataG<85 && dataG>45) && (dataB<82 && dataB>42))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isOrange2()
{
  if((dataR<56 && dataR>20) && (dataG<105 && dataG>85) && (dataB<120 && dataB>95))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isOrange3()
{
  if((dataR<40 && dataR>15) && (dataG<70 && dataG>40) && (dataB<100 && dataB>70))
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool isWhite()
{
  if((dataR<51 && dataR>11) && (dataG<51 && dataG>11) && (dataB<46 && dataB>6))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isBlack()
{
  if((dataR<600 && dataR>250) && (dataG<600 && dataG>240) && (dataB<550 && dataB>180))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isBrown()
{
  if((dataR<115 && dataR>80) && (dataG<214 && dataG>180) && (dataB<180 && dataB>145))
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool isBrown2()
{
  if((dataR<140 && dataR>110) && (dataG<360 && dataG>310) && (dataB<430 && dataB>395))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isPurple()
{
  if((dataR<130 && dataR>90) && (dataG<180 && dataG>150) && (dataB<100 && dataB>65))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isPink()
{
  if((dataR<65 && dataR>30) && (dataG<155 && dataG>115) && (dataB<85 && dataB>60))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isPink2()
{
  if((dataR<40 && dataR>10) && (dataG<75 && dataG>40) && (dataB<50 && dataB>20))
  {
    return true;
  }
  else
  {
    return false;
  }
}
