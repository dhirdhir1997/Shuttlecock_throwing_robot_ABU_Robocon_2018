bool runTill(int val)
{
  if (timer)
  {
    if (millis()-pervMilli<val)
      return true;
    else
    {
      timer = false;
      return false;
    }
  }
  else
  {
    pervMilli = millis();
    timer = true;
    return true;
  }
}


