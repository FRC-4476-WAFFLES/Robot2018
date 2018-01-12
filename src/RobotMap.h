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
constexpr int drive_right1 = 4;
constexpr int drive_right2 = 5;
constexpr int drive_right3 = 6;
constexpr int drive_lift_turn = 3;
constexpr int solenoid_extend = 1;
constexpr int solenoid_retract = 2;
