// MAKE SURE THAT AGND IS CONNECTED TO AN UNUSED ANALOG PIN FOR BETTER READINGS

const float AREF_DIVIDER = 0.5;

void setup() {
  // Set baud rate to 9600
  Serial.begin(9600);

  // Change resolution for the 12-bit ADC on the RP2040 
  analogReadResolution(12);
}

void loop() {
  int reading = analogRead(A0);

  // Normal voltage, times the fraction of the full range, times the ratio of the reference voltage to supply voltage
  float voltage = 3.3 * (reading / 4095) * AREF_DIVIDER;

  Serial.println(voltage);
}