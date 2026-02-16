#pragma once

#include <Arduino.h>

class Turret {
public:
  void begin();          // attach servos + home
  void home();

  void left(int moves = 1);
  void right(int moves = 1);
  void up(int moves = 1);
  void down(int moves = 1);

  void fire();
  void fireAll();

  void nodYes(int moves = 3);
  void shakeNo(int moves = 3);

private:
  int pitchVal_ = 100;   // current pitch angle
};
