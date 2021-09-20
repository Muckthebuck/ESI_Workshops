const int buzzPin = 11;
const int ledPin = 13;
const int ldrPin = A0;
const int threshold = 90;

void setup() {
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
}

void loop() {
  int ldrReading = analogRead(ldrPin);
  int freq = map(ldrReading, 0,182, 0,3000);
  tone(buzzPin, freq);
  if (ldrReading <= threshold) {
    digitalWrite(ledPin, HIGH);
    Serial.print("Its DARK, Turn on the LED : ");
    Serial.println(ldrReading);
    } else {
    digitalWrite(ledPin, LOW);
    Serial.print("Its BRIGHT, Turn off the LED : ");
    Serial.println(ldrReading);
}
  
}
