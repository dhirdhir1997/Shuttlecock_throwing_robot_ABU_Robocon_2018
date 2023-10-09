void alignY1Camnew()
{
  recvVal();
  if(camDown != -1)
  {
    int tempUp = yCamMid-camUp;
    int tempDown = yCamMid - camDown;
    tempUp *= Kpc;
    tempDown *= Kpc;

    
  
    
    if (camDown != 0)
    {
      driveDown(tempDown, true);
      driveUp(-tempUp, true);
    }
    else
    {
      if(downSide)
      {
       driveUp(-speedLimit, false);
        driveDown(speedLimit, false);
      }
      else
      {
       driveUp(speedLimit, false);
        driveDown(-speedLimit, false);
      }
    }


    
    if(camUp != 0)
    {
      if (tempUp>0)
        upSide = true;
      else
        upSide = false;
    }
    if(camDown != 0)
    {
      if (tempDown>0)
        downSide = true;
      else
        downSide = false;  
    }
  }
  
}

void alignY1Cam()
{
  recvVal();
  if(camUp != -1)
  {
    int tempUp = yCamMid-camUp;
    int tempDown = yCamMid - camDown;
    tempUp *= Kpc;
    tempDown *= Kpc;
    if (camUp != 0)
      driveUp(-tempUp, true);
    else
    {
      if(upSide)
        driveUp(-speedLimit, false);
      else
        driveUp(speedLimit, false);
    }
    if (camDown != 0)
      driveDown(tempDown, true);
    else
    {
      if(downSide)
        driveDown(speedLimit, false);
      else
        driveDown(-speedLimit, false);
    }
    if(camUp != 0)
    {
      if (tempUp>0)
        upSide = true;
      else
        upSide = false;
    }
    if(camDown != 0)
    {
      if (tempDown>0)
        downSide = true;
      else
        downSide = false;  
    }
  }
  
}





void alignX1Cam()
{
  recvVal();
  if(camUp != -1)
  {
    int tempRight = xCamMid - camRight;
    int tempLeft = xCamMid- camLeft;
    tempRight *= Kpc;
    tempLeft *= Kpc;
    if(camRight != 0)
      driveRight(-tempRight, true);
    else
    {
      if(rightSide)
        driveRight(-speedLimit, false);
      else
        driveRight(speedLimit, false);
    }
    if (camLeft != 0)
      driveLeft(tempLeft, true);
    else
    {
      if(leftSide)
        driveLeft(speedLimit, false);
      else
        driveLeft(-speedLimit, false);
    }
    if(camRight != 0)
    {
      if (tempRight>0)
        rightSide = true;
      else
        rightSide = false;
    }
    if(camLeft != 0)
    {
      if (tempLeft>0)
        leftSide = true;
      else
        leftSide = false;  
    }
  }
}

void alignYCam()
{
  recvVal();

  if(camUp != -1)
  {
    int tempUp = yCamMid-camUp;
    int tempDown = yCamMid - camDown;
    tempUp *= Kpc;
    tempDown *= Kpc;
    
    driveUp(-tempUp, true);
    driveDown(tempDown, true);
  }
  
}

void alignXCam()
{
  recvVal();
 
  if(camRight != -1)
  {
    int tempRight = xCamMid - camRight;
    int tempLeft = xCamMid- camLeft;
    tempRight *= Kpc;
    tempLeft *= Kpc;

    driveRight(-tempRight, true);
    driveLeft(tempLeft, true);
  }
}




void alignYCam3(int valx, int valy)
{
  recvVal();
  
  if(camUp == 0 && camDown == 0)
  {
    stopDrive();
  }
  else if(camUp != -1)
  {
    if (camUp-valx>wdiff)
      driveUp(wspeed);
    else if(camUp - valx < -wdiff)
      driveUp(-wspeed);
    else
      driveUp(0);



    if (camDown-valy>wdiff)
      driveDown(-wspeed);
    else if(camDown - valy < -wdiff)
      driveDown(wspeed);
    else
      driveDown(0);
  }
  
}

void alignXCam3(int valx, int valy)
{
  recvVal();
  
  if(camRight == 0 && camLeft == 0)
  {
    stopDrive();
  }
  else if(camRight != -1)
  {
    if (camRight-valx>wdiff)
      driveRight(wspeed);
    else if(camRight - valx < -wdiff)
      driveRight(-wspeed);
    else
      driveRight(0);



    if (camLeft-valy>wdiff)
      driveLeft(-wspeed);
    else if(camLeft - valy < -wdiff)
      driveLeft(wspeed);
    else
      driveLeft(0);
  }
}

void alignY2Cam()
{
  recvVal();
  if(camUp == 0 && camDown == 0)
  {
    stopDrive();
  }
  else if(camUp != -1)
  {
    int tempUp = 160-camUp;
    int tempDown = 160 - camDown;
    tempUp *= Kpc;
    tempDown *= Kpc;
    if(camUp == 0)
      tempUp = 0;
    if(camDown == 0)
      tempDown = 0;
    driveUp(-tempUp, true);
    driveDown(tempDown, true);
  }
  
}



void alignY2abc()
{
  recvVal();
  if(camUp == 0 && camDown == 0)
  {
    stopDrive();
  }
  else if(camUp != -1)
  {
    int tempUp = 160-camUp;
    int tempDown = 160 - camDown;
    tempUp *= Kpc1;
    tempDown *= Kpc1;
    if(camUp == 0)
      tempUp = 0;
    if(camDown == 0)
      tempDown = 0;
    driveUp(-tempUp, true);
    driveDown(tempDown, true);
  }
  
}

void alignX2Cam()
{
  recvVal();
  if(camRight == 0 && camLeft == 0)
  {
    stopDrive();
  }
  else if(camRight != -1)
  {
    int tempRight = 120 - camRight;
    int tempLeft = 120 - camLeft;
    tempRight *= Kpc;
    tempLeft *= Kpc;
    if(camRight == 0)
      tempRight = 0;
    if(camLeft == 0)
      tempLeft = 0;
    driveRight(-tempRight, true);
    driveLeft(tempLeft, true);
  }
}
