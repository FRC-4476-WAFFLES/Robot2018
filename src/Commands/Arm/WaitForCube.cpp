#include "WaitForCube.h"
#include "Subsystems/ArmSubsystem.h"
#include "Commands/Drive/DriveAutoLines.h"
#include "Subsystems/DriveSubsystem.h"
#include "Commands/Scheduler.h"

WaitForCube::WaitForCube() :
		CommandBase("WaitForCube")
//		drive(2, 0),
//		drive_back(-2, 0)
{

//	Requires(&Drive());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void WaitForCube::Initialize() {
//	drive_at_start = (Drive().Left() + Drive().Right()) / 2.0;
//	drive.Start();
//	state_thing = 0;
}

// Called repeatedly when this Command is scheduled to run
void WaitForCube::Execute() {
//	printf("st: %d\n", state_thing);
//	if(state_thing == 0){
//		if(drive.IsCompleted() || Arm().hasCUBE){
//			state_thing = 1;
//			drive.Cancel();
//			drive_back.Start();
//		}
//
//	}else if(state_thing == 1){
//		if(!drive_back.IsRunning()){
//			state_thing = 2;
//		}
//
//	}
}

// Make this return true when this Command no longer needs to run execute()
bool WaitForCube::IsFinished() {
//	return state_thing == 2;
	return Arm().hasCUBE;
}

// Called once after isFinished returns true
void WaitForCube::End() {
	Drive().drive(0, 0);
//	drive.Cancel();
//	drive_back.Cancel();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WaitForCube::Interrupted() {
	Drive().drive(0, 0);
//	drive.Cancel();
//	drive_back.Cancel();
}
