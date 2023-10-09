#include <Arduino.h>
#include "ArduinoClass.h"
#include <stdlib.h>
#include<Wire.h>
int up = 0, down = 0, left = 0, right = 0;
const char* nanpy::ArduinoClass::get_firmware_id()
{
  return "A";
}

void requestEvent() {
  
  Wire.write(up>>8);
Wire.write(up);
Wire.write(down>>8);
Wire.write(down);
Wire.write(right>>8);
Wire.write(right);
Wire.write(left>>8);
Wire.write(left);

// respond with message of 6 bytes
  // as expected by master
}

void nanpy::ArduinoClass::elaborate( nanpy::MethodDescriptor* m ) {
  if (strcmp(m->getName(), "dw") == 0) { // digitalWrite
    digitalWrite(m->getInt(0), m->getInt(1));
    m->returns(0);
  }

  if (strcmp(m->getName(), "r") == 0) {  // digitalRead
    m->returns(digitalRead(m->getInt(0)));
  }

  if (strcmp(m->getName(), "aw") == 0) { // analogWrite
    int temp = m->getInt(0);
    if (temp < 20)
    {
      analogWrite(temp, m->getInt(1));
      m->returns(0);
    }
    else if (temp == 20)
    {
      Wire.begin(8);                // join i2c bus with address #8
      Wire.onRequest(requestEvent);
      m->returns(0);
    }
    else if (temp==21)
    {
      up = m->getInt(1);
      m->returns(0);
    }
     else if (temp==22)
    {
      down = m->getInt(1);
      m->returns(0);
    }
     else if (temp==23)
    {
      right = m->getInt(1);
      m->returns(0);
    }
     else if (temp==24)
    {
      left = m->getInt(1);
      m->returns(0);
    }
  }

  if (strcmp(m->getName(), "a") == 0) {  // analogRead
    m->returns(analogRead(m->getInt(0)));
  }

  if (strcmp(m->getName(), "pm") == 0) {  // pinMode
    pinMode(m->getInt(0), m->getInt(1));
    m->returns(0);
  }

  if (strcmp(m->getName(), "delay") == 0) {
    m->returns(0);
  }

  if (strcmp(m->getName(), "m") == 0) {  // millis
    m->returns(millis());
  }

  if (strcmp(m->getName(), "pi") == 0) {  // pulseIn
    pulseIn(m->getInt(0), m->getInt(1));
    m->returns(0);
  }

  if (strcmp(m->getName(), "s") == 0) {  // shiftOut
    // shiftOut(dataPin, clockPin, bitOrder, value)
    shiftOut(m->getInt(0), m->getInt(1), m->getInt(2), m->getInt(3));
    m->returns(0);
  }
};
