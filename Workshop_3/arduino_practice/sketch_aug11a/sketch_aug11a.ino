char val = ' ';
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  val =' ';
}

void loop() {
  // put your main code here, to run repeatedly:
  val =' ';
  for(int i =1; i <=255; i++){
    Serial.print(val);
    Serial.print(" ");
    Serial.print(val, DEC);
    Serial.print(" ");
    Serial.print(val, HEX);
    Serial.print(" ");
    Serial.print(val, OCT);
    Serial.print(" ");
    Serial.println(val, BIN);
    val++;

  }
}
