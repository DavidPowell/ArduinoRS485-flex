/*
  RS-485 Sender

  This sketch periodically sends a string over the RS-485 interface

  Based on original created 4 July 2018
  by Sandeep Mistry
*/

#include <ArduinoRS485-flex.h>

// Configure serial port and pins used
#define RS485Serial Serial1  // The hardware serial port connected to the RS485 transceiver
#define RS485_TX  D0         // should match the TX pin of chosen hardware serial port - used when sending breaks
#define RS485_DE  D2         // GPIO pin connected to DE pin of transceiver
#define RS485_RE  D3         // GPIO pin connected to RE pin of transceiver
// Note - RS485_RE and RS485_DE should be different GPIO pins

RS485Class RS485(Serial1, RS485_TX, RS485_DE, RS485_RE);

int counter = 0;

void setup() {
  RS485.begin(9600);
}

void loop() {
  RS485.beginTransmission();
  RS485.print("hello ");
  RS485.println(counter);
  RS485.endTransmission();

  counter++;

  delay(1000);
}
