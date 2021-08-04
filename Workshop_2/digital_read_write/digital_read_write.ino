int data1 = 0;
int data2 = 0;
int count=0;

const int led_pin = 13;
const int btn1_pin = 12;
const int btn2_pin = 11;
void setup()
{
 pinMode(led_pin, OUTPUT);
 pinMode(btn1_pin, INPUT);
 pinMode(btn2_pin, INPUT_PULLUP);
}
void loop()
{
 data1= digitalRead(btn1_pin);
 data2= !digitalRead(btn2_pin);

 if(data1|data2){
  count++;
 }
 
 digitalWrite(led_pin, count);
 if(!data1&!data2&&count>0){
  count--;
 }
 delay(10);
}
