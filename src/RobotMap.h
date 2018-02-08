#pragma once

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int LEFTMOTOR = 1;
// constexpr int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int RANGE_FINDER_PORT = 1;
// constexpr int RANGE_FINDER_MODULE = 1;
constexpr int drive_left1 = 8;
constexpr int drive_left2 = 9;
constexpr int drive_left3 = 7;
constexpr int drive_right3 = 6;
constexpr int drive_right2 = 5;
constexpr int drive_right1 = 4;
constexpr int drive_lift_turn = 3;
constexpr int arm_tilt = 2;
constexpr int intake_tilt = 1;

constexpr int intake1 = 1;
constexpr int intake2 = 2;

constexpr int drive_solenoid_extend = 1;
constexpr int drive_solenoid_retract = 2;
constexpr int intake_solenoid_extend_1 = 3;
constexpr int intake_solenoid_retract_1 = 4;
constexpr int intake_solenoid_extend_2 = 5;
constexpr int intake_solenoid_retract_2 = 6;

//digital input
constexpr int right_drive_encoder_a = 1;
constexpr int right_drive_encoder_b = 2;
constexpr int left_drive_encoder_a = 3;
constexpr int left_drive_encoder_b = 4;
constexpr int intake_tilt_encoder_a = 5;
constexpr int intake_tilt_encoder_b = 6;
constexpr int arm_tilt_encoder_a = 7;
constexpr int arm_tilt_encoder_b = 8;


