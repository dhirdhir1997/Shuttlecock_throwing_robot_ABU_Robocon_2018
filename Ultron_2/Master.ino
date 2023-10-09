void getYourAssOutOfThere()
{
  recvVal();
  while(camDown !=  0)
  {
    moveRight(Speed);
    recvVal();
  }
  while(camDown ==  0)
  {
    moveRight(Speed);
    recvVal();
  }
  giveMeABreak(350);
}

void startbot(int val)
{
  recvVal();
  while(camDown !=  0)
  {
    moveRight(Speed);
    recvVal();
  }
  while(camDown ==  0)
  {
    moveRight(Speed);
    recvVal();
  }
  giveMeABreak(350);
  while(runTill(val))
  {
   recvVal();

    if(camUp != -1)
    {
      int tempDown = yCamMid - camDown;
      tempDown *= Kpc1;
      
      driveUp(-tempDown, true);
      driveDown(tempDown, true);
    }
   // alignY1Camnew();
  }
}

void makeWayForNoddy()
{
  
  if (mode == 1)
  {
    //Serial.println(downSharp());
    while(downSharp()>30)
    {
      alignX1Cam();
      moveLeft(Speed);
    }
    giveMeABreak(350);
    while(runTill(1500))
    {
      alignX1Cam();
    }
  }
  else if(mode == 2)
  {
    while(downSharp()<110)
    {
      alignX1Cam();
      moveRight(Speed);
    }
    giveMeABreak(350);
    while(rightSharp()<110)
      moveUp(Speed);
    giveMeABreak(350);
  }
}

int selectAZone()
{
  if(digitalRead(baumer1Pin)==HIGH)
    return 2;
  else if(digitalRead(baumer2Pin)==HIGH)
    return 3;
  else if(digitalRead(baumer3Pin)==HIGH)
    return 1;
  return 0;
}
void goRight()
{
  
    recvVal();
    while(camDown != 0)
    {
      alignX2Cam();
      moveRight(Speed);
      recvVal();
    }
    while(camDown == 0)
    {
      alignX2Cam();
      moveRight(Speed);
      recvVal();
    }
  
}


void goRight(int val)
{
  for(int i = 0; i< val; i++)
  {
    recvVal();
    while(camDown != 0)
    {
      alignX1Cam();
      moveRight(Speed);
      recvVal();
    }
    while(camDown == 0 || camUp == 0|| (camUp - camDown) > 50)
    {
      alignX1Cam();
      moveRight(Speed);
      recvVal();
    }
  }
}

void goRightnew(int val)
{
  for(int i = 0; i< val-1; i++)
  {
    recvVal();
    while(camDown != 0)
    {
      alignX1Cam();
      moveRight(Speed+15);
      recvVal();
    }
    while(camDown == 0 || camUp == 0|| (camUp - camDown) > 50)
    {
      alignX1Cam();
      moveRight(Speed+15);
      recvVal();
    }
  }
  
  giveMeABreak(850);
    correctLeftnew();    
  
 
  giveMeABreak(350);
}

void goLeftnew(int val)
{
  for(int i = 0; i< val-1; i++)
  {
    recvVal();
    while(camDown != 0)
    {
      alignX1Cam();
      moveLeft(Speed+15);
      recvVal();
    }
    while(camDown == 0 || camUp == 0|| (camUp - camDown) > 50)
    {
      alignX1Cam();
      moveLeft(Speed+15);
      recvVal();
    }
  }
  
  giveMeABreak(350);
    goLeft(1);   
  
 
  giveMeABreak(350);
}


void goLeft()
{
  
    recvVal();
    while(camUp != 0)
    {
      alignX2Cam();
      moveLeft(Speed);
      recvVal();
    }
    while(camUp == 0 || camDown == 0|| (camUp - camDown) > 50)
    {
      alignX2Cam();
      moveLeft(Speed);
      recvVal();
    }
  
}


void goLeft(int val)
{
  for(int i = 0; i< val; i++)
  {
    recvVal();
    while(camUp != 0)
    {
      alignX1Cam();
      moveLeft(Speed);
      recvVal();
    }
    while(camUp == 0 || camDown == 0|| (camUp - camDown) > 50)
    {
      alignX1Cam();
      moveLeft(Speed);
      recvVal();
    }
  }
}


void goDown()
{
  
    recvVal();
    while(camRight != 0)
    {
      
     // Serial.println(camRight);
       alignY2Cam(); 
       moveDown(Speed);
       recvVal();
    }
    while(camRight == 0 || camLeft == 0 || (camUp - camDown) > 50)
    {
      //Serial.println(camRight);
       alignY2Cam(); 
       moveDown(Speed);
       recvVal();
    }
  
}

void goDownnew()
{
  
    recvVal();
    while(camRight != 0)
    {
      
     // Serial.println(camRight);
       alignY1Cam(); 
       moveDown(Speed+10);
       recvVal();
    }
    while(camRight == 0 || camLeft == 0 || (camUp - camDown) > 50)
    {
      //Serial.println(camRight);
       alignY1Cam(); 
       moveDown(Speed+10);
       recvVal();
    }
  
}



void goDown(int val)
{
  for(int i = 0; i< val; i++)
  {
    recvVal();
    while(camRight != 0)
    {
     // Serial.println(camRight);
       alignY1Cam(); 
       moveDown(Speed);
       recvVal();
    }
    while(camRight == 0 || camLeft == 0 || (camUp - camDown) > 50)
    {
      //Serial.println(camRight);
       alignY1Cam(); 
       moveDown(Speed);
       recvVal();
    }
  }
}



void goUp(int val)
{
  for(int i = 0; i< val; i++)
  {
    recvVal();
    while(camRight != 0)
    {
       alignY1Cam(); 
       moveUp(Speed);
       recvVal();
    }
    while(camRight == 0 || camLeft == 0|| (camUp - camDown) > 50)
    {
       alignY1Cam(); 
       moveUp(Speed);
       recvVal();
    }
  }
}



void aglin()
{
  while(runTill(3000))
  {
    alignY2abc();
  }
  giveMeABreak(350);

/*
  while(runTill(3000))
  {
    moveUp(28);
  }
  giveMeABreak(300);*/
  while(runTill(1000))
  {
    moveUp(Speed-13);
  }
  while((rightHitSwitch() || leftHitSwitch())&&runTill(6000))
  {
      driveLeft(Speed-13, false);
      driveRight(-(Speed-13), false);
  }
}

