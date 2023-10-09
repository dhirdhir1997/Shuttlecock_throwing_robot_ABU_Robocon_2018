void XBOX_Setup()
{
  read_joystick();
  calculate_joystick();
  acc_vel_ratio();
  calculate_vectors();

}

void setLed()
{
  if(pidVal ==true && speedVal==true)
  {
    Xbox.setLedOn(LED1, 0);
  }
  else if(pidVal ==true && speedVal==false)
  {
    Xbox.setLedOn(LED2, 0);
  }
  else if(pidVal ==false && speedVal==true)
  {
    Xbox.setLedOn(LED3, 0);
  }
  else if(pidVal ==false && speedVal== false)
  {
    Xbox.setLedOn(LED4, 0);
  }
}

void read_joystick()                       //reads values from joystick.
{
  
 
 Usb.Task();
   if(Xbox.XboxReceiverConnected)
   {
      rt = map(Xbox.getButtonPress(R2,0),0,255,0,127);                      //0,127
      lt = map(Xbox.getButtonPress(L2,0),0,255,0,127);                     //0,-127
      joylx = map(Xbox.getAnalogHat(LeftHatX,0),-32768,32767,0,255);       //-127,127
   // joyly = map(Xbox.getAnalogHat(LeftHatY,0),-32768,32767,-128,128);
      joyrx = map(Xbox.getAnalogHat(RightHatX,0),-32768,32767,0,255);
      joyry= map(Xbox.getAnalogHat(RightHatY,0),32767,-32768,0,255);
      
     
      joyry = joyry   + lt - rt;
    
       joyry = constrain(joyry, 0, 255);
           
       if(Xbox.getButtonClick(R1, 0))
       {
        MAX_VELOCITY = 30;
        MAX_ROTATION = 20;
        speedVal = false;
        setLed();
       }
       if(Xbox.getButtonClick(L1, 0))
       {
        MAX_VELOCITY = 50;
        MAX_ROTATION = 40;
        speedVal = true;
        setLed();
       }
       if(Xbox.getButtonClick(BACK, 0))
       {
        pidVal = false;
        setLed();
       }
       if(Xbox.getButtonClick(START, 0))
       {
        pidVal = true;
        setLed();
       }
       if (Xbox.getButtonClick(XBOX, 0))
       {
        if (xboxVal)
        {
          xboxVal = false;
          Xbox.setLedMode(ROTATING, 0);
          
        }
        else
        {
          setLed();
          xboxVal = true;
        }
       }
       
                                                  //Piston 1
      if(Xbox.getButtonClick(X))
        digitalWrite(piston1, LOW);
      if(Xbox.getButtonClick(LEFT))
        digitalWrite(piston1,HIGH);
                                                //Piston 2
      if(Xbox.getButtonClick(Y))
        digitalWrite(piston2, LOW);
        //Breaking_High();
      if(Xbox.getButtonClick(UP))
        digitalWrite(piston2,HIGH);
        //Breaking_Low();
                                                //Piston3
      if (Xbox.getButtonClick(B))
        digitalWrite(piston3,LOW);
      if(Xbox.getButtonClick(RIGHT))
        digitalWrite(piston3,HIGH);

                                                 //All Piston
      if(Xbox.getButtonClick(DOWN))
      {
        digitalWrite(piston1,HIGH);
        digitalWrite(piston2,HIGH);
        digitalWrite(piston3,HIGH);
      }
      if(Xbox.getButtonClick(A))
      {
        digitalWrite(piston1,LOW);
        digitalWrite(piston2,LOW);
        digitalWrite(piston3,LOW);
      }
   }
  else
    DRIVE(90,90,90,90);
   
}

void calculate_joystick()                  // calculates angle,linear_velocity and rotational_velocity.
{
  // Calculate the magnitude of the joystick position vector to set the speed or the linear velocity to be imparted


  vel = (int)(joyry);

  if (vel > 255)
    vel = 255;
  else if (vel < 0)
    vel = 0;

  vel_ratio = mapf(vel, 0, 255, 1, -1);    //normalizing velocity into 0-1 ratio.

  //acc_vel_ratio();

  if (abs(vel_ratio) < joystick_debounce_factor)                     //debouncing joystick values.//In case of new joystick reduce the check.
    vel_ratio = 0;

  velx = (int)(joyrx);                 //directly gives the rotational velocity from -90(left) to +90(right)

  if (velx > 255)
    velx = 255;
  else if (velx < 0)
    velx = 0;

  velx_ratio = mapf(velx, 0, 255, -1, 1);
  

  if ( abs(velx_ratio) < joystick_debounce_factor )                      //debouncing joystick values
    velx_ratio = 0;



  rot_vel = (int)(joylx);

  if (rot_vel > 255)
    rot_vel = 255;
  else if (rot_vel < 0)
    rot_vel = 0;

  rot_vel_ratio = mapf(rot_vel, 0, 255, -1, 1);     //normalizing velocity into 0-1 ratio.

  //acc_vel_ratio();

  if (abs(rot_vel_ratio) < joystick_debounce_factor)                     //debouncing joystick values.//In case of new joystick reduce the check.
    rot_vel_ratio = 0;

  if(vel_ratio==0&&velx_ratio==0&&rot_vel_ratio==0)
    Breaking_High();
  else
    Breaking_Low();
  if(!xboxVal)
  {
    vel_ratio = -vel_ratio;
    velx_ratio = -velx_ratio;
  }

  prev_vel_ratio = vel_ratio;
  prev_velx_ratio = velx_ratio;
  prev_rot_vel_ratio = rot_vel_ratio;
}


void acc_vel_ratio()
{
  if (abs(vel_ratio) > abs(prev_vel_ratio))
    vel_ratio = prev_vel_ratio + vel_ratio_acc_factor * (vel_ratio - prev_vel_ratio);
  if (vel_ratio > 1)
    vel_ratio = 1;

  if (abs(velx_ratio) > abs(prev_velx_ratio))
    velx_ratio = prev_velx_ratio + vel_ratio_acc_factor * (velx_ratio - prev_velx_ratio);
  if (velx_ratio > 1)
    velx_ratio = 1;  

  
}


void calculate_vectors()
{
  
  if(rot_vel_ratio==0)
  {
    
  
  if((abs(vel_ratio)==0)&&(abs(velx_ratio)==0))
  {
    oldPosition_rl=myEnc_rl.read();
    oldPosition_fl=myEnc_fl.read();
    oldPosition_fr=myEnc_fr.read();
    oldPosition_rr=myEnc_rr.read();
    change_fl = 0;
    change_rr = 0;
    change_fr = 0;
    frontleft = int(vel_ratio * MAX_VELOCITY + velx_ratio * MAX_VELOCITY + rot_vel_ratio * MAX_ROTATION);
    frontright = int(vel_ratio * MAX_VELOCITY - velx_ratio * MAX_VELOCITY - rot_vel_ratio * MAX_ROTATION);
    rearleft = int(vel_ratio * MAX_VELOCITY - velx_ratio * MAX_VELOCITY + rot_vel_ratio * MAX_ROTATION);
    rearright = int(vel_ratio * MAX_VELOCITY + velx_ratio * MAX_VELOCITY - rot_vel_ratio * MAX_ROTATION);
  }
  else if(((abs(vel_ratio)>joystick_debounce_factor)&&(abs(velx_ratio)==0))||((abs(velx_ratio)>joystick_debounce_factor)&&(abs(vel_ratio)==0)))
  {
    optimal_rl=abs(myEnc_rl.read()-oldPosition_rl);
    sensor_fr=abs(myEnc_fr.read()-oldPosition_fr);
    sensor_rr=abs(myEnc_rr.read()-oldPosition_rr);
    sensor_fl=abs(myEnc_fl.read()-oldPosition_fl);
    //Serial.print(optimal_rl);//Serial.print("\t");//Serial.print(sensor_fr);//Serial.print("\t");//Serial.print(sensor_fl);//Serial.print("\t");//Serial.println(sensor_rr);
    if(pidVal)
    {
      change_fl= get_pidchange_fl(optimal_rl, sensor_fl, previous_error_fl, previous_integral_fl);
      change_rr= get_pidchange_rr(optimal_rl, sensor_rr, previous_error_rr, previous_integral_rr);
      change_fr= get_pidchange_fr(optimal_rl, sensor_fr, previous_error_fr, previous_integral_fr);
      //Serial.print("0");//Serial.print("\t");//Serial.print(change_fr);//Serial.print("\t");//Serial.print(change_fl);//Serial.print("\t");//Serial.println(change_rr);//Serial.print("\n");
    }
    else
    {
      change_fl = 0;
      change_rr = 0;
      change_fr = 0;
    }
   

    frontleft = int(vel_ratio * MAX_VELOCITY + velx_ratio * MAX_VELOCITY + rot_vel_ratio * MAX_ROTATION + (abs(frontleft)/frontleft)*change_fl);
    frontright = int(vel_ratio * MAX_VELOCITY - velx_ratio * MAX_VELOCITY - rot_vel_ratio * MAX_ROTATION + (abs(frontright)/frontright)*change_fr);
    rearleft = int(vel_ratio * MAX_VELOCITY - velx_ratio * MAX_VELOCITY + rot_vel_ratio * MAX_ROTATION);
    rearright = int(vel_ratio * MAX_VELOCITY + velx_ratio * MAX_VELOCITY - rot_vel_ratio * MAX_ROTATION + (abs(rearright)/rearright)*change_rr);
  }
  else if((abs(vel_ratio)>0.4)&&(abs(velx_ratio)>0.4))
  {
    if(abs(vel_ratio)>abs(velx_ratio))
    {
      velx_ratio=abs(vel_ratio)*abs(velx_ratio)/velx_ratio;
    }
    else
    {
      vel_ratio=abs(velx_ratio)*abs(vel_ratio)/vel_ratio;
    }
    oldPosition_rl=myEnc_rl.read();
    oldPosition_fl=myEnc_fl.read();
    oldPosition_fr=myEnc_fr.read();
    oldPosition_rr=myEnc_rr.read();
    change_fl = 0;
    change_rr = 0;
    change_fr = 0;
    frontleft = int(vel_ratio * MAX_VELOCITY + velx_ratio * MAX_VELOCITY + rot_vel_ratio * MAX_ROTATION);
    frontright = int(vel_ratio * MAX_VELOCITY - velx_ratio * MAX_VELOCITY - rot_vel_ratio * MAX_ROTATION);
    rearleft = int(vel_ratio * MAX_VELOCITY - velx_ratio * MAX_VELOCITY + rot_vel_ratio * MAX_ROTATION);
    rearright = int(vel_ratio * MAX_VELOCITY + velx_ratio * MAX_VELOCITY - rot_vel_ratio * MAX_ROTATION);
  }
  }
  else
  {
    oldPosition_rl=myEnc_rl.read();
    oldPosition_fl=myEnc_fl.read();
    oldPosition_fr=myEnc_fr.read();
    oldPosition_rr=myEnc_rr.read();
    change_fl = 0;
    change_rr = 0;
    change_fr = 0;
    frontleft = int(vel_ratio * MAX_VELOCITY + velx_ratio * MAX_VELOCITY + rot_vel_ratio * MAX_ROTATION);
    frontright = int(vel_ratio * MAX_VELOCITY - velx_ratio * MAX_VELOCITY - rot_vel_ratio * MAX_ROTATION);
    rearleft = int(vel_ratio * MAX_VELOCITY - velx_ratio * MAX_VELOCITY + rot_vel_ratio * MAX_ROTATION);
    rearright = int(vel_ratio * MAX_VELOCITY + velx_ratio * MAX_VELOCITY - rot_vel_ratio * MAX_ROTATION);
    
  }
  //////Serial.print(vel_ratio);////Serial.print("\t");////Serial.print(velx_ratio);////Serial.print("\t");////Serial.print(rot_vel_ratio);////Serial.println("\t");
  
  //right = int( -vel_ratio * MAX_VELOCITY + rot_ratio * MAX_ROTATION);// + get_dir(vel_ratio) * change);
  //left = int( vel_ratio * MAX_VELOCITY + rot_ratio * MAX_ROTATION);

}




