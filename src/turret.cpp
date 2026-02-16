#include "turret.h"
#include "config.h"
#include <Servo.h>

static Servo yawServo;
static Servo pitchServo;
static Servo rollServo;

void Turret::begin() {
  yawServo.attach(PIN_YAW_SERVO);
  pitchServo.attach(PIN_PITCH_SERVO);
  rollServo.attach(PIN_ROLL_SERVO);

  pitchVal_ = PITCH_DEFAULT;
  home();
}

void Turret::home() {
  yawServo.write(YAW_STOP); // Q: what happens if change this?
  delay(20);
  rollServo.write(ROLL_STOP);
  delay(100);
  pitchServo.write(PITCH_DEFAULT);
  delay(100);
  pitchVal_ = PITCH_DEFAULT;

  Serial.println("HOMING");
}

void Turret::left(int moves) {
  for (int i = 0; i < moves; i++) {
    yawServo.write(YAW_STOP + YAW_MOVE);
    delay(YAW_PRECISION_MS);
    yawServo.write(YAW_STOP);
    delay(5);
    Serial.println("LEFT");
  }
}

void Turret::right(int moves) {
  for (int i = 0; i < moves; i++) {
    yawServo.write(YAW_STOP - YAW_MOVE);
    delay(YAW_PRECISION_MS);
    yawServo.write(YAW_STOP);
    delay(5);
    Serial.println("RIGHT");
  }
}

void Turret::up(int moves) {
  for (int i = 0; i < moves; i++) {
    if ((pitchVal_ + PITCH_MOVE_SPEED) < PITCH_MAX) {
      pitchVal_ += PITCH_MOVE_SPEED;
      pitchServo.write(pitchVal_);
      delay(50);
      Serial.println("UP");
    }
  }
}

void Turret::down(int moves) {
  for (int i = 0; i < moves; i++) {
    if ((pitchVal_ - PITCH_MOVE_SPEED) > PITCH_MIN) {
      pitchVal_ -= PITCH_MOVE_SPEED;
      pitchServo.write(pitchVal_);
      delay(50);
      Serial.println("DOWN");
    }
  }
}

void Turret::fire() {
  rollServo.write(ROLL_STOP + ROLL_MOVE);
  delay(ROLL_PRECISION_MS);
  rollServo.write(ROLL_STOP);
  delay(5);
  Serial.println("FIRING");
}

void Turret::fireAll() {
  rollServo.write(ROLL_STOP + ROLL_MOVE);
  delay(ROLL_PRECISION_MS * 6);
  rollServo.write(ROLL_STOP);
  delay(5);
  Serial.println("FIRING ALL");
}

void Turret::nodYes(int moves) {
  Serial.println("YES");

  // Keep nod within bounds by shifting start if near limits
  if ((PITCH_MAX - pitchVal_) < 15) pitchVal_ -= 15;
  else if ((pitchVal_ - PITCH_MIN) < 15) pitchVal_ += 15;

  pitchServo.write(pitchVal_);
  int startAngle = pitchVal_;
  int nodAngle = startAngle + 15;

  for (int i = 0; i < moves; i++) {
    for (int a = startAngle; a <= nodAngle; a++) { pitchServo.write(a); delay(7); }
    delay(50);
    for (int a = nodAngle; a >= startAngle; a--) { pitchServo.write(a); delay(7); }
    delay(50);
  }
}

void Turret::shakeNo(int moves) {
  Serial.println("NO");

  for (int i = 0; i < moves; i++) {
    yawServo.write(140);
    delay(190);
    yawServo.write(YAW_STOP);
    delay(50);
    yawServo.write(40);
    delay(190);
    yawServo.write(YAW_STOP);
    delay(50);
  }
}
