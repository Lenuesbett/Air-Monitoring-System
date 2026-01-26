#include <LiquidCrystal.h>

/*
LCD connections (Arduino UNO)
RS  -> 12
EN  -> 11
D4  -> 5
D5  -> 4
D6  -> 3
D7  -> 2
*/

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Sensors
int mq2Pin = A0;
int lm35Pin = A1;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("System Starting");
  delay(2000);
  lcd.clear();
}

void loop() {

  // Read MQ-2 gas sensor
  int gasValue = analogRead(mq2Pin);

  // Read LM35 temperature sensor
  int lm35Value = analogRead(lm35Pin);
  float voltage = lm35Value * (5.0 / 1023.0);
  float temperature = voltage * 100.0; // LM35 formula

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("Gas Level: ");
  lcd.print(gasValue);
  lcd.print("   ");

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print((char)223); // degree symbol
  lcd.print("C  ");

  delay(1000);
}
