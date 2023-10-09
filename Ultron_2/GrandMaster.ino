void goTZ1()
{
  if(mode==2)
  {
    goLeft();
    giveMeABreak(350);
    goUp(1);
    giveMeABreak(350);
    correctUpnew();
    giveMeABreak(350);
    goRightnew(2);
  }
  else
    goRightnew(3);
 
  aglin();
   delay(2500);
  TZ1Piston();
  
  
  goDown(1);
  giveMeABreak(350);
  correctDownnew();
  while(runTill(1500))
  {
    alignX1Cam();
  }
  giveMeABreak(350);
  goLeft(2);
  giveMeABreak(350);
  
  mode = 1;
}

void goTZ2()
{
	if (mode == 1)
	{
		goRight(1);
		giveMeABreak(350);
		goDown(1);
		giveMeABreak(350);
		correctDownnew();
		while (runTill(500))
		{
			alignY1Cam();
			alignX1Cam();
		}
		giveMeABreak(350);
    goRightnew(2);
	}
  else
  {
    goDown();
  giveMeABreak(350);
  correctDownnew();
  while(runTill(500))
  {
    alignY1Cam();
    alignX1Cam();
  }
 
  giveMeABreak(350);
  goRightnew(2);
  }
  
  aglin();
  delay(2500);
  TZ2Piston();
  
  goDown(1);
  giveMeABreak(350);
  while(runTill(1500))
  {
    alignX1Cam();
  }
  giveMeABreak(350);
  goLeft(2);
  giveMeABreak(350);
  mode = 2;
}

void goTZ3()
{
  if(mode==1)
  {
    goRight(1);
    giveMeABreak(350);
    goDown(1);
    giveMeABreak(350);
    correctDownnew();
    while(runTill(500))
    {
      alignY1Cam();
      alignX1Cam();
    }
    giveMeABreak(350);
    
  goRightnew(5);
  }
  else
  {
    goDown();
    giveMeABreak(350);
    correctDownnew();
    while(runTill(500))
    {
            alignX1Cam();
    }
    giveMeABreak(350);
    
  goRightnew(5);
  }
    
  aglin();
  delay(2500);
  TZ3Piston();
  
  goDown(1);
  giveMeABreak(350);
  while(runTill(1500))
  {
    alignX1Cam();
  }
  giveMeABreak(350);
  goLeftnew(5);
  giveMeABreak(350);
  mode = 2;
}





