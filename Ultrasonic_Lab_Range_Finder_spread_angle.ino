﻿// Constant variables indicating the connections for pins
const int triggerpin = 10;
const int echopin = 9;
const int ledpin = 2;
int min = 200;


// Variable initialization
float time = 0;
float distance = 0;


void setup()
{
  pinMode(triggerpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600); //allows output
}


void loop()
{
  digitalWrite(triggerpin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerpin, HIGH);
  delayMicroseconds(5);
  digitalWrite(triggerpin, LOW);
 
  //DISTANCE
  time = pulseIn(echopin, HIGH);
  distance = time/29/2;  


  //LED
  if (distance > 30)
  {
    digitalWrite(ledpin, HIGH);
  }
  else
  {
    digitalWrite(ledpin, LOW);
    double output = acos(15/distance);
   
    output = output * 2;
    output = output * (180/3.14159);    
    Serial.println("DEGREE");
    Serial.println(output);
  }


 
}