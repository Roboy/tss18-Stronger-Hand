#ifndef Joint_h
#define Joint_h

#include "Arduino.h"
#include"Wire.h"

class Joint
{

  private:
    int magnetpin;
    int deviceaddress;
    float angle;
    byte rdata[2];            
    uint8_t eeaddress;
    uint8_t num;
    
    
  public:
    float offset_angle;
    Joint (int Magnetpin,int Sensor_ID );
    void lock_Joint (int a);
    bool readMemory(uint8_t deviceaddress, uint8_t eeaddress, byte* rdata, uint8_t num);
    float get_Joint_angle(float off_angle);
    
    
};

#endif
