#include "DriveAutoTime.h"
#include "Subsystems/DriveSubsystem.h"
#include <SmartDashboard/SmartDashboard.h>
#include "Utils/PIDPreferences.h"

DriveAutoTime::DriveAutoTime(double time, double percent_speed):
		CommandBase("DriveAutoTime"),
		drive_speed(percent_speed),
		drivetime(time)
{
	Requires(&Drive());
}


// Called just before this Command runs the first time
void DriveAutoTime::Initialize() {
	time_since_start.Reset();
	time_since_start.Start();
}

// Called repeatedly when this Command is scheduled to run
void DriveAutoTime::Execute() {
	keep_going = time_since_start.Get() < drivetime;
	if(keep_going){
		Drive().drive(drive_speed, drive_speed);
	}else{
		Drive().drive(0.0, 0.0);
	}

}

// Make this return true when this Command no longer needs to run execute()
bool DriveAutoTime::IsFinished() {

	return !keep_going;
}

// Called once after isFinished returns true
void DriveAutoTime::End() {
	Drive().drive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveAutoTime::Interrupted() {
	Drive().drive(0,0);
}
