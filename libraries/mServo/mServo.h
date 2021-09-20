#ifndef Servo_h
#define Servo_h

#include "Arduino.h"

class mServo {

  public:
    mServo(int pin, int pos_min, int pos_mid, int pos_max);

    void servoPosition(int pos);
    void servoPulse(int duration, int pin);
    int MattMap(int value, int fromMin, int fromMax, int toMin, int toMid, int toMax);
    //servoreset();

  private:

    int _pin;
    int _real_position = -1;
    int _pos_min;
    int _pos_mid;
    int _pos_max;
};












#endif
