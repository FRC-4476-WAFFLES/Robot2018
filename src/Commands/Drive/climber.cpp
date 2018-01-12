#include "climber.h"
#include "Subsystems/DriveSubsystem.h"

climber::climber() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void climber::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void climber::Execute() {
 //todo fix assumptions
	double adjust;
	adjust = drive().drive_gyro->gety()*P;

	drive().drive(oi().left.GetY() + adjust, oi().right.GetY() - adjust);
	//todo check signs
}

// Make this return true when this Command no longer needs to run execute()
bool climber::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void climber::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void climber::Interrupted() {

}
