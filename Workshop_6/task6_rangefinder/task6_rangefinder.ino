#define SOUNDSPEED 0.034
#define THRESHOLD 10

const int trigPin = 9;
const int echoPin = 10;
const int pin_servo1 = 11;

int init = 300;
int real_position1 = -1;
int real_position2 = -1;
String myString;
 
long duration;
int distance;
int pos;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pin_servo1, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (
  servoPosition1(Pos1.toInt());
  
    readDistance();
//    while (distance <=THRESHOLD){
//      readDistance();
//    }
    delay(1000);
   
}

void readDistance(){
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  Serial.print("Distance: ");
  Serial.println(duration);
//  distance = duration*SOUNDSPEED/2;
//
//  
//  Serial.print(distance);
//  Serial.println(" cm");
}
