#ifndef DuoServo_h
#define DuoServo_h

#include "Arduino.h"

class DuoServo
{
  public:
    DuoServo(int pin_servo1, int pin_servo2, int real_position1, int real_position2);
    void servoPosition1(int pos1);
    void servoPosition2(int pos2);
    void servoPulse(int duration, int pin);
    void servoreset();
  private:
    int _pin_servo1;
    int _pin_servo2;
    int _real_position1;
    int _real_position2;
    int _pos1;
    int _pos2;
    int _duration;
    int _pin;
};

#endif // DuoServo_h
