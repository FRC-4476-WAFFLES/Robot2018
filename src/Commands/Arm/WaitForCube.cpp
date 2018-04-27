#include "WaitForCube.h"
#include "Subsystems/ArmSubsystem.h"
#include "Commands/Drive/DriveAutoLines.h"
#include "Subsystems/DriveSubsystem.h"
#include "Commands/Scheduler.h"

WaitForCube::WaitForCube() :
		CommandBase("WaitForCube")
{

}

// Called just before this Command runs the first time
void WaitForCube::Initialize() {
	wait_for_intake.Reset();
}

// Called repeatedly when this Command is scheduled to run
void WaitForCube::Execute() {
	if(Arm().hasCUBE){
		wait_for_intake.Start();
	}else{
		wait_for_intake.Stop();
		wait_for_intake.Reset();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool WaitForCube::IsFinished() {
	return wait_for_intake.Get() > 0.2;
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
