#define LDAC 0
#define chipSelect 1
#define signal 2
#define clock 3

float clockDelay;

// This is needed to start the message to the DAC
int signalHeader[16] = {0, 1, 1, 1};

void setup() {
  // Define pins
  pinMode(clock, OUTPUT);
  pinMode(signal, OUTPUT);
  pinMode(chipSelect, OUTPUT);
  pinMode(LDAC, OUTPUT);

  // Change resolution for 12-bit ADC
  analogReadResolution(12);

  // Set starting values for active low pins
  digitalWrite(LDAC, HIGH);
  digitalWrite(chipSelect, HIGH);

  Serial.begin(9600);

  // Slowed down for first run
  clockDelay = 1;
  writeDAC(0);
  clockDelay = 0.1;
}

void loop() {
  // Test code to write a sin wave and view it in the serial monitor
  for (float i = 0; i <= 618; i += 12.36){
    int toWrite = (127 * sin(i / 100)) + 128;
    writeDAC(toWrite);
    float voltage = 3.3 * analogRead(A0) / 4096.0;
    Serial.println(voltage);
  }
}

// Function for bit banging the SPI line on the DAC
void writeDAC(int value){
  // Select chip
  digitalWrite(chipSelect, LOW);

  // Add binary to message
  int pos = 4;
  for (int i = 7; i >= 0; i--){
    signalHeader[pos] = bitRead(value, i);
    pos++;
  }

  // Clock and Write
  for (int i = 0; i < 16; i++){
    digitalWrite(signal, signalHeader[i]);
    delay(clockDelay);
    digitalWrite(clock, HIGH);
    delay(clockDelay);
    digitalWrite(clock, LOW);
    delay(clockDelay);
  }

  // Deselect Chip
  digitalWrite(chipSelect, HIGH);

  // Move value to VOUT register
  digitalWrite(LDAC, LOW);
  delay(clockDelay);
  digitalWrite(LDAC, HIGH);
}