int resis = A0;
int Value;
int Volume;
void setup() {
  Serial.begin(9600);
  pinMode(resis, INPUT);
}
void loop() {
  Value = analogRead(resis);
  Volume = (64. / 1023.) * Value;
  Serial.println(Volume);
  Serial.println(Value);
  delay(1000);
}
