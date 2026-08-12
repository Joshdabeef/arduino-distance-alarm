# Arduino Uno R4 Ultrasonic Distance Sensor + Buzzer Alarm

Got a quick project running on the Uno R4 WiFi using an HC-SR04 ultrasonic sensor, a 16x2 I2C LCD, and a piezo buzzer. It measures distance in real time, displays it on the screen, and sets off a beep if anything gets closer than 5cm.

### Hardware
* Arduino Uno R4 WiFi
* HC-SR04 Ultrasonic sensor
* LCD1602 with I2C backpack
* Piezo buzzer
* Breadboard & jumpers

### Wiring
Power and ground go to the breadboard's vertical rails (5V and GND from the R4).

* HC-SR04: Trig -> Pin 9, Echo -> Pin 10
* LCD: SDA -> SDA, SCL -> SCL
* Buzzer: Positive -> Pin 8, Negative -> GND rail

### Notes & Libraries
Requires the `LiquidCrystal_I2C` library (by Frank de Brabander). If the screen lights up but doesn't show text, adjust the contrast screw on the back of the I2C backpack or check if your board's address is 0x3F instead of 0x27.

### How it works
The code triggers a pulse every 100ms and calculates distance in cm. If an object is detected between 0.5cm and 5cm, Pin 8 pulls high and sounds a 1kHz tone. Anything past 5cm keeps the buzzer silent.
