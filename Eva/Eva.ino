
#include <XBOXRECV.h>
// Satisfy IDE, which only needs to see the include statment in the ino.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif

#include <Servo.h>
#include <EncoderNew.h>
#include "pinDef.h"

USB Usb;
XBOXRECV Xbox(&Usb);
EncoderNew myEnc_rl(20, 30);//for rearleft motor
EncoderNew myEnc_fr(3, 24);//for front right
EncoderNew myEnc_rr(19,28);//for rearright
EncoderNew myEnc_fl(18, 26);//for frontleft


Servo flMotor,frMotor,rlMotor,rrMotor;
long oldPosition_rl,oldPosition_rr,oldPosition_fl,oldPosition_fr;
long optimal_rl,sensor_fr,sensor_fl,sensor_rr;
int ps2error = 0;
int joylx=0,
    joyly=0,
    joyrx=0,
    joyry=0;
int vel , velx, rot_vel;
float vel_ratio=0 , velx_ratio=0 , rot_vel_ratio=0 , prev_vel_ratio=0 , prev_velx_ratio=0 , prev_rot_vel_ratio=0; 
float vel_ratio_acc_factor = 0.1;
float joystick_debounce_factor = 0.5;
int frontleft, frontright, rearleft, rearright;

int MAX_VELOCITY = 50;
int MAX_ROTATION = 40;

int Kp = 40,
Ki = 3,
Kd = 25;
long integral = 0, error = 0, derivative = 0;
long previous_integral_rr = 0, previous_error_rr = 0,previous_integral_fl = 0, previous_error_fl = 0,previous_integral_fr = 0, previous_error_fr = 0;
long int change_fl = 0,change_rr = 0,change_fr = 0;

int rt, lt;
bool pidVal = true, speedVal = true, xboxVal=true;
char pistonVal='f';

void setup() {
 
  Serial.begin(9600);
  while (!Serial); // Wait for //Serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC //Serial connection
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  //Serial.print(F("\r\nXbox Wireless Receiver Library Started"));
  
  Motor_Setup();
  Breaking_Setup();
  
  
  pinMode(piston1,OUTPUT);
  pinMode(piston2,OUTPUT);
  pinMode(piston3,OUTPUT);
  digitalWrite(piston1,HIGH);
  digitalWrite(piston2,HIGH);
  digitalWrite(piston3,HIGH);
  
}
void loop() 
{

  
    XBOX_Setup();
    frontleft = constrain(frontleft, -90, 90);
    frontright = constrain(frontright, -90, 90);
    rearleft = constrain(rearleft, -90, 90);
    rearright = constrain(rearright, -90, 90);
   
    //Serial.print(frontleft);//Serial.print("\t");//Serial.print(frontright);//Serial.print("\t");//Serial.print(rearleft);//Serial.print("\t");//Serial.print(rearright);//Serial.print("\n");
    DRIVE(frontleft, frontright, rearleft, rearright);
  
  
  

}

