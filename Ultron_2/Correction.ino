void correctDown()
{
  recvVal();
  if(camRight == 0 || camLeft==0)
  {
    goUp(1);
    //Serial.println("going back...");
  }
    
    else
    {
  
    while(runTill(2500))
      {
        alignXCam();
        //Serial.println("aligning...");  
      }
    }  
}
void correctDownnew()
{
    giveMeABreak(450);
    recvVal();
   
    while(camLeft==0 || camRight==0)
    { recvVal();
      if(camLeft==0)
      {
        driveLeft(Speed,true);
      }
      else
      {
        driveLeft(0,false);
      }
      if(camRight==0)
      {
        driveRight(-Speed,true);
      }
      else
      {
        driveRight(0,false);
      }
    }
    
}

void correctUpnew()
{
    giveMeABreak(450);
    recvVal();
   
    while(camLeft==0 || camRight==0)
    { recvVal();
      if(camLeft==0)
      {
        driveLeft(-Speed,true);
      }
      else
      {
        driveLeft(0,false);
      }
      if(camRight==0)
      {
        driveRight(Speed,true);
      }
      else
      {
        driveRight(0,false);
      }
    }
    while(runTill(500))
    {
      alignY1Cam();
    }
}

void correctUp()
{
  recvVal();
  if(camRight == 0)
    goDown(1);
  else
  {
    while(runTill(2000))
      alignXCam();
  }
}

void correctRight()
{
  recvVal();
  if(camUp == 0)
    goLeft(1);
  else
  {
    while(runTill(2000))
      alignYCam();
  }
}
void correctRightnew()
{
  giveMeABreak(450);
  recvVal();
  
  while(camUp==0 || camDown==0)
    { 
      recvVal();
      if(camUp==0)
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

void correctLeft()
{
  recvVal();
  if(camUp == 0)
    goRight(1);
  else
  {
    while(runTill(2000))
      alignYCam();
  }
}
void correctLeftnew()
{
  recvVal();
  while(camUp==0 || camDown==0)
    { 
      recvVal();
      if(camUp==0)
      {
        driveUp(slowSpeed,true);
      }
      else
      {
        driveUp(0,false);
      }
      if(camDown==0)
      {
        driveDown(-slowSpeed,true);
      }
      else
      {
        driveDown(0,false);
      }
    }
   giveMeABreak(350);
}

