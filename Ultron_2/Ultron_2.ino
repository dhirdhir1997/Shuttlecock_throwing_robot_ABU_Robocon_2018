#include <Wire.h>
#include <Servo.h>
#include "pinDef.h"

bool timer = false, rightSide = false, leftSide = false, upSide = false, downSide = false;

int camUp, camDown, camLeft, camRight, aglinVal = 0;
int mode = 0, offset = 0, wspeed = 28, wdiff = 15; // do not exceed value of wdiff by 16

unsigned long pervMilli = 0;

float Kpc = 0.6, Kpc2 = 0.8, Kpc1 = 0.3;

double Kp=5, Ki=2, Kd=1;
double Kpcam = 0.2, Kicam = 0.2, Kdcam = 0.1;
double SetpointU, InputU, OutputU, SetpointD, InputD, OutputD, SetpointL, InputL, OutputL, SetpointR, InputR, OutputR;
double SetpointUcam, InputUcam, OutputUcam, SetpointDcam, InputDcam, OutputDcam, SetpointLcam, InputLcam, OutputLcam, SetpointRcam, InputRcam, OutputRcam;


Servo u, d, r, l;



void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  motorSetup();
  
  pistonSetup();
  breakingSetup();
  while(digitalRead(A6)!=HIGH)
  {
    delay(50);
  }
  while(digitalRead(A6)!=LOW)
  {
    delay(50);
  }
  //getYourAssOutOfThere();
  startbot(1500);
  recvVal();
  if(camDown == 0)
  {
    recvVal();
  
  while( camDown==0)
    { 
      recvVal();
      if(camDown==0)
      {
        driveUp(-Speed,true);
      }
      else
      {
        driveUp(0,false);
      }
      if(camDown==0)
      {
        driveDown(Speed,true);
      }
      else
      {
        driveDown(0,false);
      }
    }
   giveMeABreak(350);
  }
  while(runTill(800))
  {
     alignY2Cam(); 
     moveDown(Speed);
  }
  goDownnew();
  giveMeABreak(350);
  correctDown();
  giveMeABreak(350);
  mode = 1;
}

void loop() {
 callMeMaybe();
 
}


void callMeMaybe()
{
   makeWayForNoddy();
  while(digitalRead(stopBaumerPinDown)!=HIGH)
  {
    delay(2000);
  }
  while(digitalRead(stopBaumerPinDown)!=LOW)
  {
    delay(2000);
  }
  switch (selectAZone())
  {
    case 1:
    {
      goTZ1();
      break;
    }
    case 2:
    {
      goTZ2();
      break;
    }
    case 3:
    {
      goTZ3();
      break;
    }
    default:
      break;
  }
}

