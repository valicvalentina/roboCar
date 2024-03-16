#include <IRremote.h>             // Include the IRremote library for infrared remote control

#define PIN_IRREMOTE_RECV  9      // Define the pin for receiving infrared signals

IRrecv irrecv(PIN_IRREMOTE_RECV); // Create an instance of IRrecv class for receiving

decode_results results;           // Create an instance of decode_results class for decoding

void setup()
{
  Serial.begin(9600);         // Initialize the serial communication with a baud rate of 9600
  irrecv.enableIRIn();        // Enable the receiver for infrared signals
}

void loop() {
  if (irrecv.decode(&results)) {        // Check if there's a signal being decoded
    Serial.println(results.value, HEX); // Print the decoded signal value in hexadecimal format
    irrecv.resume();                    // Resume receiving for the next signal
  }
  delay(100); // Delay for stability
}


