/*
Code Name:OBSTACLE COUNTER
Author: ammarece
Description: This program is used for OBSTACLE COUNTER for counting obstacle
License: Remixing or Changing this Thing is allowed. Commercial use is not allowed.
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define irPin 2   // IR sensor digital pin

int obstacleCount = 0;  // Counter for obstacles detected

// Initialize LCD display with I2C address 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();  // Initialize LCD display
  lcd.backlight();  // Turn on LCD backlight
  lcd.setCursor(0, 0);
  lcd.print("Obstacle Count:");  // Print initial message on LCD
  Serial.begin(9600);
  pinMode(irPin, INPUT);
}

void loop() {
  // Read IR sensor value
  int irValue = digitalRead(irPin);

  // Check if obstacle is detected
  if (irValue == LOW) {
    obstacleCount++;
    lcd.setCursor(0, 1);
    lcd.print(obstacleCount);  // Update obstacle count on LCD display
    Serial.print("Obstacle detected! Count: ");
    Serial.println(obstacleCount);
  }

  delay(100);  // Wait for 0.1 seconds before reading again
}
