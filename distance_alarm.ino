#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define TRIG_PIN 9
#define ECHO_PIN 10
#define BUZZER_PIN 8

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  lcd.init();
  lcd.backlight();
}

void loop() {
  // Clear trigger pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  
  // Send 10us ultrasonic burst
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo pulse length with a 30ms timeout (~500cm max range)
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  float distance = duration * 0.034 / 2;

  // Display reading on LCD
  lcd.setCursor(0, 0);
  lcd.print("Distance:      ");
  lcd.setCursor(0, 1);
  
  if (duration == 0) {
    lcd.print("Out of range   ");
    noTone(BUZZER_PIN); // Silence buzzer on timeout
  } else {
    lcd.print(distance);
    lcd.print(" cm      ");

    // Strictly trigger buzzer between 0.5cm and 5cm
    if (distance >= 0.5 && distance <= 5.0) {
      tone(BUZZER_PIN, 1000); 
    } else {
      noTone(BUZZER_PIN);
    }
  }

  delay(100);
}
