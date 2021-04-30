#include <Arduino.h>

#define DATA_PIN 32   // SER pin (14) on 595
#define LATCH_PIN 26  // RCLK pin (12) on 595
#define CLOCK_PIN 33  // SRCLK pin (11) on 595

// bytes to send to 595
const byte bits[] = {
  B00000001,
  B00000010,
  B00000100,
  B00001000,
  B00010000,
  B00100000,
  B01000000,
  B10000000
};

void update595(byte value) {
  // freeze the state of the storage register
  digitalWrite(LATCH_PIN, LOW);
  // transfer the bits to the shift register
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, value);
  /* store the shift register data in the storage
  register and make it available on the outputs */
  digitalWrite(LATCH_PIN, HIGH);
}

void setup() {
  Serial.begin(115200);

  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
}

void loop() {
  for(uint8_t i = 0; i < 8; i++) {
    update595(bits[i]);
  }
}