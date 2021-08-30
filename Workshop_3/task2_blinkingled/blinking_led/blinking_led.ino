const int transistorPin = 3;
const int Hz = 50;
const int sec = (1000)/(HZ*2)
void setup()
{
 pinMode (transistorPin, OUTPUT);
}
void loop()
{
 digitalWrite (transistorPin, HIGH);
 //delay(1000);
 delay(sec);
 digitalWrite (transistorPin, LOW);
 //delay(1000);
 delay(sec);
}
