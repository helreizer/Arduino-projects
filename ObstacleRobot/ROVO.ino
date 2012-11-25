#include <Moto.h>

Moto moto(12,11,10,9);


int trigP = 49;
int echoP = 48;

void setup() 
{
  pinMode(trigP, OUTPUT);
  pinMode(echoP, INPUT);

}

void loop() 
{



  int duration, distance;
  int  lastdistance = 0;
  digitalWrite(trigP, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigP, LOW);
  duration = pulseIn(echoP, HIGH);
  distance = (duration/2) / 74;
  delay(50);
  if(distance > 6)
  {
    moto.forward(255);
  }

  if(distance < 6)
  {
    moto.left(255);
    delay(300);
  }

}

