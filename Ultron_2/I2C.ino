void recvVal()
{ 
     Wire.requestFrom(addr, data);
     camUp = Wire.read()<<8|Wire.read();
     camDown = Wire.read()<<8|Wire.read();
     camRight = Wire.read()<<8|Wire.read();
     camLeft = Wire.read()<<8|Wire.read();
}

