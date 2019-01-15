#include <pathfinder.h>
#include <vector>

int main() {
		// First thing to do is to pick a base unit for all of our distances.
		// As long as we're consistent, the physics is the same.
		// Feet is probably a good base unit for us.

		// Create a list of points that the robot will pass through.
		// Each position x, y is a 2-d point.
		// Each angle is an angle in radians (use d2r to convert degrees into radians)
		// The angle 0 is the +x direction
		// The angle 90 is the +y direction
		// The angle 180 is the -x direction
		// The angle 270 is the -y direction
		//
		// The first point will be the starting position and angle of the robot.
		std::vector<Waypoint> points;
    points.push_back({ .x=-4, .y=-1, .angle= d2r(45) });
		points.push_back({ .x=-1, .y= 2, .angle= d2r(0)  });
    points.push_back({ .x= 2, .y= 4, .angle= d2r(0)  });
    
		// Generate a trajectory to follow. This just makes a smooth curve connecting each point.
    TrajectoryCandidate candidate;

		// You'll need to change these constants for the robot.
		// Look up the documentation to see what each one does.
		// Right now, I'm assuming 20ms of time between each point,
		// because that's the normal rate of a robot loop.
		float max_velocity = 15.0;
    pathfinder_prepare(points.data(), points.size(), FIT_HERMITE_CUBIC, PATHFINDER_SAMPLES_LOW, 0.02, max_velocity, 10.0, 60.0, &candidate);

    int length = candidate.length;
		std::vector<Segment> trajectory(length);
    pathfinder_generate(&candidate, trajectory.data());
    
		// Generate trajectories for each side of the drivetrain.
		// We'll use these later to move along the planned path.
		std::vector<Segment> leftTrajectory(length);
		std::vector<Segment> rightTrajectory(length);
    
		// This will need to be tuned to the robot as well.
		// This is the distance from one side of the robot's
		// wheels to the other set of wheels.
    double wheelbase_width = 0.635;

    pathfinder_modify_tank(trajectory.data(), length, leftTrajectory.data(), rightTrajectory.data(), wheelbase_width);

    // Everything above should be run only once each time the robot starts.
		// The constructor would be a good place.
		// You'll need to save {leftTrajectory, rightTrajectory}
		// as variables in the command for use in the Execute() function.

		// Everything here needs to be reset when the command starts.
		// This stuff should probably go in Initialize()

		// Create a new follower that will keep track of the encoders
		EncoderFollower leftFollower;
		leftFollower.last_error = 0; leftFollower.segment = 0; leftFollower.finished = 0;
		EncoderFollower rightFollower;
		rightFollower.last_error = 0; rightFollower.segment = 0; rightFollower.finished = 0;
		
		EncoderConfig leftConfig;
		leftConfig.ticks_per_revolution = 128; // Double check
		leftConfig.wheel_circumference = 0.5; // Double check
		leftConfig.kp = 1.0; // From example; probably needs tuning
		leftConfig.ki = 0.0;
		leftConfig.kd = 0.0;
		leftConfig.kv = 1.0 / max_velocity;
		leftConfig.ka = 0.0;
		leftConfig.initial_position = 0.0; // Make this the actual starting encoder value

		EncoderConfig rightConfig = leftConfig; // Copy all of the values above for the right side as well
		rightConfig.initial_position = 0.0; // This will be different from the left side.


		// Save both followers and configs in the command so that Execute() can use them


		// Everything inside the while loop needs to happen each time Execute()
		// is called.
		
		while(true) {
				// Calculate the motor outputs for both the left and right sides
				// Replace with the reading of the actual encoder value
				// Note that this is raw ticks, not rotations. So the /128 thing that DriveSubsystem does won't work.
				int leftEncoderValue = 0;
				double l = pathfinder_follow_encoder(leftConfig, &leftFollower, leftTrajectory.data(), leftTrajectory.size(), leftEncoderValue);
				int rightEncoderValue = 0; // Replace with the reading of the actual encoder value
				double r = pathfinder_follow_encoder(rightConfig, &rightFollower, rightTrajectory.data(), rightTrajectory.size(), rightEncoderValue);

				// Then call a function that will set the motors, this is just for testing
				printf("Driving left: %f, right: %f\n", l, r);
		}
}
