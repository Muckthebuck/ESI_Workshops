#include <DuoServo.h>

const int pin_servo1 = 9;
const int pin_servo2 = 10;

int test = 300;
int real_position1 = -1;
int real_position2 = -1;
String myString;

DuoServo duoServo(pin_servo1, pin_servo2, real_position1, real_position2);
 
void setup() {
  Serial.begin(9600);
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

  String str_data = myString;
  int firstCommaIndex = str_data.indexOf(',');
  int secondCommaIndex = str_data.indexOf(',', firstCommaIndex+1);
  String Pos1 = str_data.substring(0, firstCommaIndex);
  String Pos2 = str_data.substring(firstCommaIndex+1, secondCommaIndex);
  String Pos3 = str_data.substring(secondCommaIndex+1);

  duoServo.servoPosition1(Pos1.toInt());
  duoServo.servoPosition2(Pos2.toInt());

}
