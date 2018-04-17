#include "WaitForCube.h"
#include "Subsystems/ArmSubsystem.h"
#include "Commands/Drive/DriveAutoLines.h"
#include "Subsystems/DriveSubsystem.h"

WaitForCube::WaitForCube() :
		CommandBase("WaitForPosition")
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void WaitForCube::Initialize() {
	drive_at_start = (Drive().Left() + Drive().Right()) / 2.0;
}

// Called repeatedly when this Command is scheduled to run
void WaitForCube::Execute() {
	if(Arm().hasCUBE){
		Drive().drive(0, 0);
		/////////////////////////TODO:add drive back to original position

	}else{
		Drive().drive(0.4, 0.4);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool WaitForCube::IsFinished() {
	return Arm().hasCUBE;
}

// Called once after isFinished returns true
void WaitForCube::End() {
	Drive().drive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WaitForCube::Interrupted() {
	Drive().drive(0, 0);
}
