#include "DriveAutoLines.h"
#include "Subsystems/DriveSubsystem.h"
#include <SmartDashboard/SmartDashboard.h>
#include "Utils/PIDPreferences.h"

double clamp(double value, double min, double max) {
	if(value < min) {
		return min;
	} else if(value > max) {
		return max;
	} else {
		return value;
	}
}

DriveAutoLines::DriveAutoLines(double distance, double angle, double epsilon, double speed_max):
		CommandBase("DriveAutoLines"),
		distance(distance * 614),
		angle(angle),
		epsilon(epsilon),
		max_speed(speed_max)
{
	Requires(&Drive());
}

// Called just before this Command runs the first time
void DriveAutoLines::Initialize() {
	Drive().target_distance += distance;
	Drive().target_angle += angle;

	double distance_error = Drive().target_distance - (Drive().Left() + Drive().Right()) / 2.0;
	double angle_error = Drive().target_angle - Drive().Gyro();

	last_distance_error = distance_error;
	last_angle_error = angle_error;
	last_time.Reset();
	last_time.Start();
}

// Called repeatedly when this Command is scheduled to run
void DriveAutoLines::Execute() {
	double distance_error = Drive().target_distance - (Drive().Left() + Drive().Right()) / 2.0;
	double angle_error = Drive().target_angle - Drive().Gyro();
	double time = last_time.Get();
	last_time.Reset();
	last_time.Start();

	SmartDashboard::PutNumber("Drive Error", distance_error);
	SmartDashboard::PutNumber("Angle Error", angle_error);

	double distance_p = GetP("drive_distance", 0.005) * distance_error;
	double angle_p = GetP("drive_angle", 0.01) * angle_error;

	double distance_d = GetD("drive_distance", 0.0005) * ((distance_error - last_distance_error) / time);
	double angle_d = GetD("drive_angle", 0.0) * ((angle_error - last_angle_error) / time);

	double distance_out = clamp(distance_p - distance_d, -max_speed, max_speed);
	double angle_out = clamp(angle_p - angle_d, -0.45, 0.45);

	Drive().drive(-distance_out - angle_out, -distance_out + angle_out);

	last_angle_error = angle_error;
	last_distance_error = distance_error;
}

// Make this return true when this Command no longer needs to run execute()
bool DriveAutoLines::IsFinished() {
	double distance_error = Drive().target_distance - (Drive().Left() + Drive().Right()) / 2.0;
	double angle_error = Drive().target_angle - Drive().Gyro();

	return fabs(distance_error) < epsilon && fabs(angle_error) < epsilon/5;
}

// Called once after isFinished returns true
void DriveAutoLines::End() {
	Drive().drive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveAutoLines::Interrupted() {
	Drive().drive(0,0);
}