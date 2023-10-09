void _5mSharpSetup()
{
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
}

int upSharp()
{
  float dist1 = 0;
    for(int i = 0; i < 20; i++)
            dist1 += 30421 * pow(analogRead(sharpUPin), -1.169);
     dist1 /=20;
     return (int) dist1;
}

int downSharp()
{
  float dist1 = 0;
    for(int i = 0; i < 20; i++)
    {
            dist1 += 30421 * pow(analogRead(sharpDPin), -1.169);
            //Serial.println(analogRead(sharpDPin));
    }
     dist1 /=20;
     //Serial.println(dist1);
     return (int) dist1;
}

int rightSharp()
{
  float dist1 = 0;
    for(int i = 0; i < 20; i++)
            dist1 += 30421 * pow(analogRead(sharpRPin), -1.169);
     dist1 /=20;
     return (int) dist1;
}

int leftSharp()
{
  float dist1 = 0;
    for(int i = 0; i < 20; i++)
            dist1 += 30421 * pow(analogRead(sharpLPin), -1.169);
     dist1 /=20;
     return (int) dist1;
}

int ySharp()
{
  digitalWrite(sharpYPinAcc, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);    
  int sensorValue = 0;
  // read the input on analog pin 0:
  for (int i  = 0; i< 20;i++)
  sensorValue += analogRead(sharpYPin);
  // print out the value you read:
  
  delay(1);        // delay in between reads for stability
   digitalWrite(sharpYPinAcc, LOW);    // turn the LED off by making the voltage LOW
  delay(20);
  return((int)sensorValue/20);
}

int xSharp()
{
  digitalWrite(sharpXPinAcc, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);    
  int sensorValue = 0;
  // read the input on analog pin 0:
  for (int i  = 0; i< 20;i++)
  sensorValue += analogRead(sharpXPin);
  // print out the value you read:
  
  delay(1);        // delay in between reads for stability
   digitalWrite(sharpXPinAcc, LOW);    // turn the LED off by making the voltage LOW
  delay(20);
  return((int)sensorValue/20);
}





bool leftHitSwitch()
{
  if(digitalRead(leftHitSwitchPin)==HIGH)
    return false;
  else
    return true;
}


bool rightHitSwitch()
{
  if(digitalRead(rightHitSwitchPin)==HIGH)
    return false;
  else
    return true;
}

