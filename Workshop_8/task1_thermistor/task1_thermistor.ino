#include <math.h>
#include <LiquidCrystal.h>
// include the library https://www.arduino.cc/en/Reference/LiquidCrystal
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int ThermistorPin = 1; //Set value to match which analog input you are using
float Vo;
float T;
float R_T;
float i;
float B=3950;
float T0=25;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
}
void loop() {
 Vo = 5.0*analogRead(ThermistorPin)/1024.0;
 i = (5-Vo)/10000;
 R_T = Vo/i;
 T = 1/((1/B)*log(R_T/10000)+(1)/(273+T0))-273;
 lcd.setCursor(0,0);
 lcd.print("Temperature: ");
 lcd.setCursor(0,12);
 lcd.print(T);
 delay(1000);
}
