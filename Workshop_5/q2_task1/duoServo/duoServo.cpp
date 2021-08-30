#include "Arduino.h"
#include "duoServo.h"

duoServo::duoServo(const int pin_servo1, const int pin_servo2, int real_position1, int real_position2)
{
     pinMode(pin_servo1, OUTPUT);
     pinMode(pin_servo2, OUTPUT);
     _pin_servo1 = pin_servo1;
     _pin_servo2 = pin_servo2;
     _real_position1 = real_position1;
     _real_position2 = real_position2;
}

void duoServo::servoPosition1(int pos1)
{
    if (real_position1 != pos){
    int duration = map(pos, 0, 180, 300, 2100);
    for(int i=0; i<100; i++){
      servoPulse(duration, pin_servo1);
    }
    real_position1 = pos;

}
void duoServo::servoPosition2(int pos2)
{
    if (real_position2 != pos){
    int duration = map(pos, 0, 180, 500, 2400);
    for(int i=0; i<100; i++){
      servoPulse(duration, pin_servo2);
    }
    real_position2 = pos;
  }
}

void duoServo::servoPulse(int duration, int pin)
{
    digitalWrite(pin, HIGH);
    delayMicroseconds(duration);
    digitalWrite(pin, LOW);
    delayMicroseconds(20000-duration);
}
void duoServo::servoreset(){
  servoPosition1(0);
  servoPosition2(0);
  delay(1000);
}
