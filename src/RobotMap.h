#pragma once

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// PWM
constexpr int DRIVE_LEFT1 = 8;
constexpr int DRIVE_LEFT2 = 9;
constexpr int DRIVE_LEFT3 = 7;
constexpr int DRIVE_RIGHT3 = 6;
constexpr int DRIVE_RIGHT2 = 5;
constexpr int DRIVE_RIGHT1 = 4;
constexpr int DRIVE_LIFT_TURN = 3;
constexpr int INTAKE1 = 1;
constexpr int INTAKE2 = 2;

// CAN
constexpr int ARM_TILT = 2;
constexpr int INTAKE_TILT = 1;

// PCM
constexpr int DRIVE_SOLENOID_EXTEND = 1;
constexpr int DRIVE_SOLENOID_RETRACT = 2;
constexpr int INTAKE_SOLENOID_EXTEND_1 = 3;
constexpr int INTAKE_SOLENOID_RETRACT_1 = 4;
constexpr int INTAKE_SOLENOID_EXTEND_2 = 5;
constexpr int INTAKE_SOLENOID_RETRACT_2 = 6;

//DIGITAL INPUT
constexpr int RIGHT_DRIVE_ENCODER_A = 1;
constexpr int RIGHT_DRIVE_ENCODER_B = 2;
constexpr int LEFT_DRIVE_ENCODER_A = 3;
constexpr int LEFT_DRIVE_ENCODER_B = 4;
constexpr int INTAKE_TILT_ENCODER_A = 5;
constexpr int INTAKE_TILT_ENCODER_B = 6;
constexpr int ARM_TILT_ENCODER_A = 7;
constexpr int ARM_TILT_ENCODER_B = 8;


