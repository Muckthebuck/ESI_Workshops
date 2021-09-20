#include "Arduino.h"
#include "mServo.h"

mServo::mServo(int pin, int pos_min, int pos_mid, int pos_max){
  _pin = pin;
  _pos_min = pos_min;
  _pos_mid = pos_mid;
  _pos_max = pos_max;
}

void mServo::servoPosition(int pos){
  if (_real_position != pos){
    int duration = mServo::MattMap(pos, 0, 180, _pos_min, _pos_mid, _pos_max);
    for(int i=0; i<100; i++){
      servoPulse(duration, _pin);
    }
    _real_position = pos;
  }
}

void mServo::servoPulse(int duration, int pin){
  digitalWrite(pin, HIGH);
  delayMicroseconds(duration);
  digitalWrite(pin, LOW);
  delayMicroseconds(20000-duration);
}

int mServo::MattMap(int value, int fromMin, int fromMax, int toMin, int toMid, int toMax){
  if (value <= (fromMax/2)){
    return map(value, fromMin, fromMax/2, toMin, toMid);
  } else {
    return map(value, fromMax/2, fromMax, toMid, toMax);
  }
}
//void mServo::servoreset(){
//  servoPosition1(0);
//  servoPosition2(0);
//  delay(1000);
//}
