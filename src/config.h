#pragma once

#include <Arduino.h>

// ---------- Pins ----------
constexpr uint8_t PIN_IR_RECEIVE = 9;
constexpr uint8_t PIN_YAW_SERVO  = 10;
constexpr uint8_t PIN_PITCH_SERVO = 11;
constexpr uint8_t PIN_ROLL_SERVO = 12;

// ---------- IR Commands (your NEC command values) ----------
constexpr uint8_t IR_LEFT  = 0x8;
constexpr uint8_t IR_RIGHT = 0x5A;
constexpr uint8_t IR_UP    = 0x18;
constexpr uint8_t IR_DOWN  = 0x52;
constexpr uint8_t IR_OK    = 0x1C;

constexpr uint8_t IR_STAR     = 0x16;
constexpr uint8_t IR_HASHTAG  = 0x0D;

constexpr uint8_t IR_CMD1 = 0x45; // nod
constexpr uint8_t IR_CMD2 = 0x46; // shake
constexpr uint8_t IR_CMD3 = 0x47;
constexpr uint8_t IR_CMD4 = 0x44;
constexpr uint8_t IR_CMD5 = 0x40;
constexpr uint8_t IR_CMD6 = 0x43;
constexpr uint8_t IR_CMD7 = 0x7;
constexpr uint8_t IR_CMD8 = 0x15;
constexpr uint8_t IR_CMD9 = 0x9;
constexpr uint8_t IR_CMD0 = 0x19;

// ---------- Motion tuning ----------
constexpr int PITCH_DEFAULT = 100;
constexpr int PITCH_MAX = 150;
constexpr int PITCH_MIN = 33;

constexpr int PITCH_MOVE_SPEED = 8; // this variable is the angle added to the pitch servo to control how quickly the PITCH servo moves - try values between 3 and 10

constexpr int YAW_STOP = 90; // value to stop the yaw motor - keep this at 90
constexpr int YAW_MOVE = 90; // this variable is the speed controller for the continuous movement of the YAW servo motor. It is added or subtracted from the yawStopSpeed, so 0 would mean full speed rotation in one direction, and 180 means full rotation in the other. Try values between 10 and 90;
constexpr int YAW_PRECISION_MS = 150; // this variable represents the time in milliseconds that the YAW motor will remain at it's set movement speed. Try values between 50 and 500 to start (500 milliseconds = 1/2 second)

constexpr int ROLL_STOP = 90; // value to stop the roll motor - keep this at 90
constexpr int ROLL_MOVE = 90; // this variable is the speed controller for the continuous movement of the ROLL servo motor. It is added or subtracted from the rollStopSpeed, so 0 would mean full speed rotation in one direction, and 180 means full rotation in the other. Keep this at 90 for best performance / highest torque from the roll motor when firing.
constexpr int ROLL_PRECISION_MS = 158;
