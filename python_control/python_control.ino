#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD address and size

const int vinPin = A0;
const int voutPin = A1;

// Resistors
const float R1 = 4000.0;  // First resistor (ohms)
const float R2 = 2000.0;   // R2 for voltage divider (Vout = Vin * R2/(R1+R2))
const float R3 = 2000.0;   // R3 for current calculation (I = Vin / (R1 + R3))

void setup() {
  lcd.init();      // Initialize LCD
  lcd.backlight(); // Turn on backlight
  Serial.begin(9600);
}

void loop() {
  float vin_meas = analogRead(vinPin) * (5.0 / 1023.0);
  float vout_meas = analogRead(voutPin) * (5.0 / 1023.0);

  // Voltage divider formula: Vout = Vin * (R2 / (R1 + R2))
  float vout_calc = vin_meas * (R2 / (R1 + R2));

  // Current calculation: I = Vin / (R1 + R3)
  float current = vin_meas / (R1 + R3);      // Current in Amps
  float current_mA = current * 1000.0;       // Convert to milliamps

  // Serial Monitor Output
  Serial.print("Vin: "); Serial.print(vin_meas, 2); Serial.print(" V | ");
  Serial.print("Vout (calc): "); Serial.print(vout_calc, 2); Serial.print(" V | ");
  Serial.print("Vout (meas): "); Serial.print(vout_meas, 2); Serial.print(" V | ");
  Serial.print("Current: "); Serial.print(current_mA, 2); Serial.println(" mA");

  // LCD Output
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Vin:"); lcd.print(vin_meas, 2); lcd.print("V");

  lcd.setCursor(0, 1);
  lcd.print("I:"); lcd.print(current_mA, 2); lcd.print("mA ");
  lcd.print("Vo:"); lcd.print(vout_calc, 2); lcd.print("V");

  delay(1000);
}