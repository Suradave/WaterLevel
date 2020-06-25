#include "LiquidCrystal_I2C.h"
LiquidCrystal_I2C lcd(0x27, 20, 4);

int resis = A0;
int Value;
int Volume;
int RED = 10;
int GREEN = 9;
int BLUE = 11;
void setup() {
  Serial.begin(9600);
  pinMode(resis, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 1);
  lcd.print("Hello, world!");
  delay(2000);
  lcd.clear();
}
void loop() {
  int sensorValue = analogRead(A1);
  Value = analogRead(resis);
  Volume = (64. / 1023.) * Value;
  Serial.println(sensorValue);
  if (sensorValue <= 440) {
    analogWrite(RED, 0);
    analogWrite(GREEN, Volume);
    analogWrite(BLUE, 0);
    lcd.setCursor(0, 2);
    lcd.print("Green");
  } else if (sensorValue > 440 && sensorValue <= 520) {
    analogWrite(RED, Volume);
    analogWrite(GREEN, Volume / 2);
    analogWrite(BLUE, 0);
    lcd.setCursor(0, 2);
    lcd.print("Yellow");
  } else if (sensorValue > 520) {
    analogWrite(RED, Volume);
    analogWrite(GREEN, 0);
    analogWrite(BLUE, 0);
    lcd.setCursor(0, 2);
    lcd.print("Red");
  }
  lcd.setCursor(0, 1);
  lcd.print("Water Level : ");
  lcd.print(sensorValue);
  delay(200);
  lcd.clear();
}