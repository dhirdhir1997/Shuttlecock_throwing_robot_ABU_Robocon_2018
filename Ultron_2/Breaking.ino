void breakingSetup()
{
  pinMode(breakingUpPin, OUTPUT);
  pinMode(breakingDownPin, OUTPUT);
  pinMode(breakingRightPin, OUTPUT);
  pinMode(breakingLeftPin, OUTPUT);
}

bool pause(int val)
{
  breakAll();
  stopDrive();
  while(runTill(val))
  {
    recvVal();
    if(camUp != 0 || camDown != 0)
    {
      release_All();
      return true;
    }
  }
  release_All();
  return false;  
}

void giveMeABreak(int val)
{
  breakAll();
  stopDrive();
  delay(val);
  release_All();
}

void breakUp()
{
  digitalWrite(breakingUpPin, HIGH);
}

void releaseUp()
{
  digitalWrite(breakingUpPin, LOW);
}


void breakDown()
{
  digitalWrite(breakingDownPin, HIGH);
}

void releaseDown()
{
  digitalWrite(breakingDownPin, LOW);
}

void breakLeft()
{
  digitalWrite(breakingLeftPin, HIGH);
}

void releaseLeft()
{
  digitalWrite(breakingLeftPin, LOW);
}

void breakRight()
{
  digitalWrite(breakingRightPin, HIGH);
}

void releaseRight()
{
  digitalWrite(breakingRightPin, LOW);
}

void breakAll()
{
  breakUp();
  breakDown();
  breakRight();
  breakLeft();
}

void release_All()
{
  releaseUp();
  releaseDown();
  releaseRight();
  releaseLeft();
}

