const int pin1 = 6;
const int pin2 = 10;
const int pin3 = 11;
const int pin_in = A0;

int count = 0;
bool pin1stat = 0;
bool pin2stat = 0;
bool pin3stat = 0;
int input = 0;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin_in, INPUT);
}

void loop() {

    pin1stat = !pin1stat;
    digitalWrite(pin1, pin1stat);

  if ((count%2)==0){
    
    pin2stat = !pin2stat;
    digitalWrite(pin2, pin2stat);
  }

  if ((count%4)==0){
    pin3stat = !pin3stat;
    digitalWrite(pin3, pin3stat);
  }
  input =  analogRead(pin_in);
  
  count++;
  if (count == 8){
    count = 0;
  }
  delay(12.5);
  
}
