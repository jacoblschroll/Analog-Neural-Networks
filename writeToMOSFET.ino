// List of pins used, first pin is the LSB
int mosfet_pins[4] = {3, 2, 1, 0};

// Value in decimal that will be written to the 4 MOSFETs
int toWrite = 4;

void setup() {
  // Setup every pin
  for (int i = 0; i < 4; i++){
    pinMode(mosfet_pins[i], OUTPUT);
  }

  for (int i = 0; i < 4; i++)
  {
    int state = bitRead(toWrite, i);
    digitalWrite(mosfet_pins[i], state);
  }
}

void loop() {
// Verify this worked with a multimeter
}