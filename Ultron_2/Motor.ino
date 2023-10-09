void motorSetup()
{
  u.attach(uMotorPin, 985,2010);
  d.attach(dMotorPin, 985, 2005);
  r.attach(rMotorPin, 1050,2040);
  l.attach(lMotorPin, 985,2020);
}

int speedLmt(int val)
{
  if (val<-speedLimit)
    val = -speedLimit;
  else if(val> speedLimit)
    val = speedLimit;
  return val;
}

void driveUp(int val, bool tempx)
{
  if(tempx) 
  {
    val = speedLmt(val);  
  }
  u.write(90+val);
}

void driveDown(int val, bool tempx)
{
  if(tempx) 
  {
    val = speedLmt(val);  
  }
  d.write(90+val);
}

void driveRight(int val, bool tempx)
{
  if(tempx) 
  {
    val = speedLmt(val);  
  }
  r.write(90+val);
}

void driveLeft(int val, bool tempx)
{
  if(tempx) 
  {
    val = speedLmt(val);  
  }
  l.write(90+val);
}



void driveUp(int val)
{
  if(val >0)
    val+= offset;
  else
    val -= offset;
  u.write(90+val);
}

void driveDown(int val)
{
  if(val >0)
    val+= offset;
  else
    val -= offset;
  d.write(90+val);
}

void driveRight(int val)
{
  if(val >0)
    val+= offset;
  else
    val -= offset;
  r.write(90+val);
}

void driveLeft(int val)
{
  if(val >0)
    val+= offset;
  else
    val -= offset;
  l.write(90+val);
}








void moveUp(int val)
{
  driveRight(-val, false);
  driveLeft(val, false);
}


void moveDown(int val)
{
  driveLeft(-val, false);
  
  driveRight(val, false);
  
}

void moveRight(int val)
{
  driveUp(val, false);
  driveDown(-val, false);
}


void moveLeft(int val)
{
  driveUp(-val, false);
  driveDown(val, false);
}

void stopDrive()
{
  driveUp(0, false);
  driveDown(0, false);
  driveRight(0, false);
  driveLeft(0, false);
}

