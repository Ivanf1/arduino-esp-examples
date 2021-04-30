#include <Arduino.h>

#define LATCH_PIN 17  // SH/!LD pin (1) on 165
#define CLOCK_PIN 12  // CLK pin (2) on 165
#define DATA_PIN 14   // QH pin (9) on 165

int scan165(int bitToRead) {
  /* pull the latch low to load all the 8 bits
  simultaneously into the shift register */
  digitalWrite(LATCH_PIN, LOW);
  delayMicroseconds(10);
  /* pull the latch high so we can read
  the values from the shift register */
  digitalWrite(LATCH_PIN, HIGH);
  delayMicroseconds(10);

  // load all the bits from the shift register
  uint8_t bits = shiftIn(DATA_PIN, CLOCK_PIN, LSBFIRST);
  // return a single bit from the 8 bits
  return (int)bitRead(bits, bitToRead);
}

void setup() {
  Serial.begin(115200);
  
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, INPUT);
}

void loop() {
  for(uint8_t i = 0; i < 8; i++) {
    Serial.printf("input %d: %d", i, scan165(i));
  }
}