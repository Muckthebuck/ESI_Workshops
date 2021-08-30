//String str = " ";
//String in = " ";
//int in;
float in;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
//    str =  Serial.readStringUntil('\n');
//    in +=char(Serial.read());
//   in = Serial.parseInt();
    in = Serial.parseFloat();
    Serial.print("ARD received: ");
    Serial.println(in);
  }
}
