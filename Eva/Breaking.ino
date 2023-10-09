void Breaking_Setup()
{
  pinMode(flMotor_pin_break,OUTPUT);
  pinMode(frMotor_pin_break,OUTPUT);
  pinMode(rrMotor_pin_break,OUTPUT);
  pinMode(rlMotor_pin_break,OUTPUT);
}

void Breaking_High()
{
  digitalWrite(flMotor_pin_break,HIGH);
  digitalWrite(frMotor_pin_break,HIGH);
  digitalWrite(rrMotor_pin_break,HIGH);
  digitalWrite(rlMotor_pin_break,HIGH);
}

void Breaking_Low()
{
  digitalWrite(flMotor_pin_break,LOW);
  digitalWrite(frMotor_pin_break,LOW);
  digitalWrite(rrMotor_pin_break,LOW);
  digitalWrite(rlMotor_pin_break,LOW);
}


