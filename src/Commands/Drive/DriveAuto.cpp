#include "DriveAuto.h"
#include "Subsystems/DriveSubsystem.h"

DriveAuto::DriveAuto(const char* target):
		CommandBase("DriveAuto")
{
	Requires(&Drive());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void DriveAuto::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveAuto::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool DriveAuto::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveAuto::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveAuto::Interrupted() {

}
