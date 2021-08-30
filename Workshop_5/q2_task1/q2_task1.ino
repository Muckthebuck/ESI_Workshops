//#define SOUNDSPEED 0.034
//#define THRESHOLD 10
//
//const int servPin = 9;
//const int servPin1 = 10;
//int input;
//int input1;
//long duration;
//int pos;
//int pos1;
//int i;
//void setup() {
//  // put your setup code here, to run once:
//  pinMode(servPin, OUTPUT);
//  for(i =0;i<100;i++){
//    moveZero(servPin);
//    moveZero(servPin1);
//  }
//  Serial.begin(9600);
//}
//
//void loop() {
//
//  if(Serial.available()){
//    input = Serial.readStringUntil(',').toInt();
//    input1 = Serial.readStringUntil('\n').toInt();
//    Serial.println(input);
//    Serial.println(input1);
//    pos = map(input, 0, 180, 300, 2100); 
//    pos = map(input1, 0, 180, 300, 2100); 
//    for (i=0;i<100;i++){
//       moveserv(pos,servPin);
//       moveserv(pos,servPin1);
//    }
//  }
//  delay(1000);
//   
//}
//void moveserv(int pos, const int Pin){
//  digitalWrite(Pin, HIGH);
//  delayMicroseconds(pos);
//  digitalWrite(Pin, LOW);
//  delayMicroseconds(20000-pos);
//}
//void moveZero(const int Pin){
//  digitalWrite(Pin, HIGH);
//  delayMicroseconds(300);
//  digitalWrite(Pin, LOW);
//  delayMicroseconds(20000-300);
//}
//void pulse(){
//  digitalWrite(servPin, LOW);
//  delayMicroseconds(1000);
//  digitalWrite(servPin, HIGH);
//  delayMicroseconds(1000);
//  digitalWrite(servPin, LOW);
//}
const int pin_servo1 = 9;
const int pin_servo2 = 10;

int test = 300;
int real_position1 = -1;
int real_position2 = -1;
String myString;
 
void setup() {
  Serial.begin(9600);
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

  String str_data = myString;
  int firstCommaIndex = str_data.indexOf(',');
  int secondCommaIndex = str_data.indexOf(',', firstCommaIndex+1);
  String Pos1 = str_data.substring(0, firstCommaIndex);
  String Pos2 = str_data.substring(firstCommaIndex+1, secondCommaIndex);
  String Pos3 = str_data.substring(secondCommaIndex+1);

  servoPosition1(Pos1.toInt());
  servoPosition2(Pos2.toInt());

}

void servoPosition1(int pos){
  if (real_position1 != pos){
    int duration = map(pos, 0, 180, 300, 2100);
    for(int i=0; i<100; i++){
      servoPulse(duration, pin_servo1);
    }
    real_position1 = pos;
  }
}

void servoPosition2(int pos){
  if (real_position2 != pos){
    int duration = map(pos, 0, 180, 500, 2400);
    for(int i=0; i<100; i++){
      servoPulse(duration, pin_servo2);
    }
    real_position2 = pos;
  }
}

void servoPulse(int duration, int pin){
  digitalWrite(pin, HIGH);
  delayMicroseconds(duration);
  digitalWrite(pin, LOW);
  delayMicroseconds(20000-duration);
}

void servoreset(){
  servoPosition1(0);
  servoPosition2(0);
  delay(1000);
}
