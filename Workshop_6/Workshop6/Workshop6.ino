#include <mServo.h>

const int echo_pin = 10;
const int pulse_pin = 9;
const int pin_servo1 = 8;
const int pin_servo2 = 12;

mServo servo1(pin_servo1, 470,1275, 2250);
mServo servo2(pin_servo2, 435,1385, 2385);


String myString;
 
void setup() {
  Serial.begin(9600);
  pinMode(pulse_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(pin_servo1, OUTPUT);
  pinMode(pin_servo2, OUTPUT);
  //servoreset();
}

void loop() {

  if (Serial.available() > 0){
    myString = Serial.readString();
    Serial.print("ARD received:");
    Serial.print(" ");
    Serial.println(myString);
    delay(10);
  };
  servo1.servoPosition(0);
  superScan();
}

int pulseSensor(){
  pulseTrig();
  int duration = pulseIn(echo_pin, HIGH);
  return duration;
}

void pulseTrig(){
  digitalWrite(pulse_pin, LOW);
  delayMicroseconds(10);
  digitalWrite(pulse_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pulse_pin, LOW);
}

void superScan(){
  int degree = 0;
  for (int i=0; i<=180; i+=10){
    servo1.servoPosition(i);
    Serial.print("Distance:");
    Serial.println(pulseSensor());
    delay(1000);
  }
}
