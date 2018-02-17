#pragma once

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// PWM
constexpr int SPARE_1 = 6;
constexpr int SPARE_2 = 7;
constexpr int INTAKE1 = 8;
constexpr int INTAKE2 = 9;

// CAN
constexpr int DRIVE_LEFT1 = 1;//srx
constexpr int DRIVE_LEFT2 = 1;//spx
constexpr int DRIVE_LEFT3 = 2;//spx
constexpr int DRIVE_RIGHT1 = 2;//srx
constexpr int DRIVE_RIGHT2 = 3;//spx
constexpr int DRIVE_RIGHT3 = 4;//spx
//constexpr int DRIVE_LIFT_TURN = 3;
constexpr int ARM_TILT_SLAVE = 8;//spx
constexpr int ARM_TILT = 4;//srx
constexpr int INTAKE_TILT = 3;//srx
constexpr int SPARE_3 = 9;//spx

// PCM
//constexpr int DRIVE_SOLENOID_EXTEND = 1;
//constexpr int DRIVE_SOLENOID_RETRACT = 2;
constexpr int INTAKE_SOLENOID_EXTEND_1 = 3;
constexpr int INTAKE_SOLENOID_RETRACT_1 = 4;

//DIGITAL INPUT
constexpr int RIGHT_DRIVE_ENCODER_A = 1;
constexpr int RIGHT_DRIVE_ENCODER_B = 2;
constexpr int LEFT_DRIVE_ENCODER_A = 3;
constexpr int LEFT_DRIVE_ENCODER_B = 4;
constexpr int INTAKE_TILT_ENCODER_A = 5;
constexpr int INTAKE_TILT_ENCODER_B = 6;
constexpr int ARM_TILT_ENCODER_A = 7;
constexpr int ARM_TILT_ENCODER_B = 8;


