void Motor_Setup()
{
  flMotor.attach(flMotor_pin,980,1985);
  frMotor.attach(frMotor_pin,1030,2015);
  rlMotor.attach(rlMotor_pin,1030,2015);
  rrMotor.attach(rrMotor_pin,985,1990);
  
}



void DRIVE(int a, int b, int c, int d)                 //sets values of x,y to motors left and right respectively.
{

  
    front_left_speed(a);
    front_right_speed(b);
    rear_left_speed(c);
    rear_right_speed(d);
 
}

void front_left_speed(int x)
{

  flMotor.write(90 - (x));
}
void front_right_speed(int x)
{
  frMotor.write(90 + (x));
}
void rear_left_speed(int x)
{
  rlMotor.write(90 - (x));
}
void rear_right_speed(int x)
{
  rrMotor.write(90 + (x));
}


