#include "commands.h"
#include "config.h"

void handleCommand(uint8_t cmd, Turret& turret) {
  switch (cmd) {
    case IR_UP:    turret.up(1); break;
    case IR_DOWN:  turret.down(1); break;
    case IR_LEFT:  turret.left(1); break;
    case IR_RIGHT: turret.right(1); break;
    case IR_OK:    turret.fire(); break;
    case IR_STAR:  turret.fireAll(); delay(50); break;
    case IR_CMD1:  turret.nodYes(3); break;
    case IR_CMD2:  turret.shakeNo(3); break;
    default:
      // unknown command: ignore or print
      break;
  }
}
