#include "Arduino.h"
#include "DuoServo.h"

DuoServo::DuoServo(int pin_servo1, int pin_servo2, int real_position1, int real_position2)
{
     pinMode(pin_servo1, OUTPUT);
     pinMode(pin_servo2, OUTPUT);
     _pin_servo1 = pin_servo1;
     _pin_servo2 = pin_servo2;
     _real_position1 = real_position1;
     _real_position2 = real_position2;
}

void DuoServo::servoPosition1(int pos1)
{
    if (_real_position1 != pos1){
    int duration = map(pos1, 0, 180, 300, 2100);
    for(int i=0; i<100; i++){
      servoPulse(duration, _pin_servo1);
    }
    _real_position1 = pos1;
    }
}

void DuoServo::servoPosition2(int pos2)
{
    if (_real_position2 != pos2){
    int duration = map(pos2, 0, 180, 500, 2400);
    for(int i=0; i<100; i++){
      servoPulse(duration, _pin_servo2);
    }
    _real_position2 = pos2;
  }
}

void DuoServo::servoPulse(int duration, int pin)
{
    digitalWrite(pin, HIGH);
    delayMicroseconds(duration);
    digitalWrite(pin, LOW);
    delayMicroseconds(20000-duration);
}
void DuoServo::servoreset(){
  servoPosition1(0);
  servoPosition2(0);
  delay(1000);
}
