int data_in = 0;
int data_out = 0;
const int led_pin = 13;
const int pot_pin = A0;
void setup()
{
 pinMode(led_pin, OUTPUT);
 pinMode(pot_pin, INPUT);
 Serial.begin(9600);
}
void loop()
{
 data_in = analogRead(pot_pin);
 data_out = map(data_in, 0, 1023, -255, 255);
 analogWrite(led_pin, 255-abs(data_out));
 Serial.print("led 13: ");
 Serial.print(255-abs(data_out));
 Serial.print("\n");
 delay(10);
}
