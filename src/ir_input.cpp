#include "ir_input.h"
#include "config.h"
#include <IRremote.hpp>

void irBegin() {
  IrReceiver.begin(PIN_IR_RECEIVE, ENABLE_LED_FEEDBACK);

  Serial.println(F("IR receiver ready"));
  Serial.print(F("Using IRremote v"));
  Serial.println(VERSION_IRREMOTE);
}

bool irReadCommand(uint8_t &outCmd) {
  if (!IrReceiver.decode()) return false;

  IrReceiver.printIRResultShort(&Serial);
  Serial.println();

  outCmd = IrReceiver.decodedIRData.command;
  IrReceiver.resume();
  return true;
}
