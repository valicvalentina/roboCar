#include <Freenove_WS2812B_RGBLED_Controller.h>
#include "Freenove_WS2812B_RGBLED_Controller.h"

#define I2C_ADDRESS  0x20
#define LEDS_COUNT   10

Freenove_WS2812B_Controller strip(I2C_ADDRESS, LEDS_COUNT, TYPE_GRB);

void setup() {
  while (!strip.begin());

  strip.setAllLedsColor(0xFF0000); // Set all LED color to red
  delay(2000);
  strip.setAllLedsColor(0x0000FF); // Set all LED color to blue
  delay(2000);
  strip.setAllLedsColor(0x00FF00); // Set all LED color to green
  delay(2000);
  strip.setAllLedsColor(255, 255, 0); // Set all LED color to yellow
  delay(2000);
  strip.setAllLedsColor(0, 0, 0);    // Set all LED off
  delay(2000);

  strip.setLedColor(0, 255, 0, 0);   // Set the N0.0 LED to red
  delay(1000);
  strip.setLedColor(1, 0, 0, 255);   // Set the N0.1 LED to blue
  delay(1000);
  strip.setLedColor(2, 0, 255, 0);   // Set the N0.2 LED to green
  delay(1000);
  strip.setLedColor(3, 255, 255, 0); // Set the N0.3 LED to yellow
  delay(1000);
  strip.setLedColor(4, 255, 0, 255); // Set the N0.4 LED to purple
  delay(1000);
}

void loop() {
  for (int k = 0; k < 255; k += 2) {
    strip.setAllLedsColorData(strip.Wheel(k)); // Set color data for all LEDs
    strip.show();                              // Show the color set before
    delay(50);
  }
  delay(3000);

  for (int j = 0; j < 255; j += 2) {
    for (int i = 0; i < LEDS_COUNT; i++) {
      strip.setLedColorData(i, strip.Wheel(i * 256 / LEDS_COUNT + j)); // Set color data for LEDs one by one
    }
    strip.show();  // Show the color set
    delay(50);
  }
}
