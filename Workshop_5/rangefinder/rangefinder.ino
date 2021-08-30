#define SOUNDSPEED 0.034
#define THRESHOLD 10

const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;
int pos;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {

  
    readDistance();
//    while (distance <=THRESHOLD){
//      readDistance();
//    }
    delay(500);
   
}

void readDistance(){
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
   Serial.println(duration);
//  distance = duration*SOUNDSPEED/2;
//
//  Serial.print("Distance: ");
//  Serial.print(distance);
//  Serial.println(" cm");
  delay(500);
}
