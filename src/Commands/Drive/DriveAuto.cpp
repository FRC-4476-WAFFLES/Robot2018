#include "DriveAuto.h"
#include "Subsystems/DriveSubsystem.h"

DriveAuto::DriveAuto(std::vector<Waypoint> target):
		CommandBase("DriveAuto"),
		waypoints(target)
{
	Requires(&Drive());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());

	TrajectoryCandidate candidate;
	pathfinder_prepare(waypoints.data(), waypoints.size(), FIT_HERMITE_CUBIC, PATHFINDER_SAMPLES_LOW, 0.001, DriveSubsystem::MAX_SPEED, DriveSubsystem::MAX_ACCEL, DriveSubsystem::MAX_JERK, &candidate);
	std::vector<Segment> trajectory(candidate.length);
	left_trajectory = std::vector<Segment>(candidate.length);
	right_trajectory = std::vector<Segment>(candidate.length);
	int result = pathfinder_generate(&candidate, trajectory.data());
	if(result < 0.0) {
		fprintf(stderr, "Error generating trajectory\n");
		trajectory = std::vector<Segment>(0);
	}
	pathfinder_modify_tank(trajectory.data(), candidate.length, left_trajectory.data(), right_trajectory.data(), 25.5/12.0);
}

// Called just before this Command runs the first time
void DriveAuto::Initialize() {
	left_follower.last_error = 0;
	left_follower.segment = 0;
	left_follower.finished = 0;
	right_follower.last_error = 0;
	right_follower.segment = 0;
	right_follower.finished = 0;
	Drive().left_config.initial_position = Drive().Left();
	Drive().right_config.initial_position = Drive().Right();
}

// Called repeatedly when this Command is scheduled to run
void DriveAuto::Execute() {
	float l = pathfinder_follow_encoder(Drive().left_config, &left_follower, left_trajectory.data(), left_trajectory.size(), Drive().Left());
	float r = pathfinder_follow_encoder(Drive().right_config, &right_follower, right_trajectory.data(), right_trajectory.size(), Drive().Right());
	float angle = Drive().Gyro();

	float angle_difference = r2d(left_follower.heading) - angle;
	float turn = 0.8 * angle_difference;

	Drive().drive(l + turn, r - turn);
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
