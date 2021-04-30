#include <Arduino.h>

#define POT_PIN 32

void setup() {
  Serial.begin(115200);
  adcAttachPin(POT_PIN);
}

void loop() {
  uint16_t potValue = analogRead(POT_PIN);
  Serial.println(potValue);
}