// Arduino
int counter = 0;
void setup() {
 Serial.begin(9600);
}
void loop() {
 Serial.print("Count is: ");
 Serial.println(counter);
 counter++;
 delay(1000);
}
