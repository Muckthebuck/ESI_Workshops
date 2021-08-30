char mychar1 = 'A';
char mychar2 = 65;
char mychars[] = {'E','s','i','!'};
String myString = "ESI IS AWESOME!";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 Serial.println(mychar1);
 delay(500);
 Serial.println(mychar2);
 delay(500);
 Serial.println(mychars);
 delay(500);
 Serial.println(myString);
 delay(500);
}
