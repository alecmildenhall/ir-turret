#include <Arduino.h>
#include "turret.h"
#include "ir_input.h"
#include "commands.h"

static Turret turret;

void setup() {
  Serial.begin(9600);
  turret.begin();
  irBegin();
}

void loop() {
  uint8_t cmd;
  if (irReadCommand(cmd)) {
    handleCommand(cmd, turret);
  }
  delay(5);
}
