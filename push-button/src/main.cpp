#include <Arduino.h>

#define BUTTON_PIN 26

unsigned long buttonTime = 0;
// the amount of time (in ms) you want to wait
// before considering the button state valid
uint8_t buttonDebounceDelay = 50;
// previous value of the button
uint8_t prevButtonState = 0;
// current value of the button
uint8_t curButtonState = 0;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  // Debouncing
  // save the current reading from the button
  int reading = digitalRead(BUTTON_PIN);

  // this will keep resetting buttonTime
  // until it reaches a stable value
  if (reading != prevButtonState) {
    // reset the buttonTime to this time
    buttonTime = millis();
  }

  // once the button has reached a stable value
  // wait for the debouce time to pass
  if ((millis() - buttonTime) > buttonDebounceDelay) {
    // now that the debouce time has passed
    // we can check the button state
    if (reading != curButtonState) {
      // if the button state has changed, save the new state
      curButtonState = reading;
      Serial.println(curButtonState);
    }
  }
  prevButtonState = reading;
}