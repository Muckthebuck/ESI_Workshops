#include <dht.h>
#include <math.h>
// include the library from LMS

dht DHT;
#define DHT11_PIN 3

#define ThermistorPin 1 //Set value to match which analog input you are using
float Vo;
float T;
float R_T;
float i;
float B=3950;
float T0=25;
float grad = 0.9735;
float offset = 0.4419;

void setup(){
 Serial.begin(9600);
}
void loop(){
 int chk = DHT.read11(DHT11_PIN);
 Vo = 5.0*analogRead(ThermistorPin)/1024.0;
 i = (5-Vo)/10000;
 R_T = Vo/i;
 T = 1/((1/B)*log(R_T/10000)+(1)/(273+T0))-273;
 Serial.print(DHT.temperature);
 Serial.print(", ");
 Serial.print(T);
 double after = grad*T + offset;
  Serial.print(", ");
 Serial.println(after);
 delay(100);
}
