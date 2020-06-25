int RED = 9;
int GREEN = 10;
int BLUE = 11;
void setup() {
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}
void loop() {
  analogWrite(RED, 0);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 64);
  delay(1000);
  analogWrite(RED, 0);
  analogWrite(GREEN, 64);
  analogWrite(BLUE, 0);
  delay(1000);
  analogWrite(RED, 64);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 0);
  delay(1000);
}
