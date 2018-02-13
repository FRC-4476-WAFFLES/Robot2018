#pragma once
#include <Point2.h>
#include <Motion.h>
#include <iostream>

class Pid {
private:
	float kP;
	float kI;
	float kD;
	float iAcc;
	float lastD;

public:
	Pid(float _kP, float _kI, float _kD):
		kP(_kP),
		kI(_kI),
		kD(_kD)
	{ }

	float Calc(float value, float target, float deltaTime) {
		float error = target - value;
		float pk = kP * error / deltaTime;
		float ik = kI * iAcc / deltaTime;
		float dk = kD * (lastD - error) / deltaTime;
		iAcc += error*deltaTime;
		lastD = error;
		return pk + ik + dk;
	}
};

class RobotSim {
private:
	float timeSinceLastUpdate = 0.0;
	float totalTime = 0.0;

	float leftSpeed = 0.0;
	float rightSpeed = 0.0;
	float leftEncoder = 0.0;
	float rightEncoder = 0.0;
	float lastLeftEncoder = 0.0;
	float lastRightEncoder = 0.0;
	Pid leftPid;
	Pid rightPid;

	Point2 predictedCentre;
	float width;
	Point2 leftPosition;
	Point2 rightPosition;

public:
	RobotSim(Point2 centre, float angle, float _width):
		predictedCentre(0.0, 0.0),
		leftPosition(0.0, 0.0),
		rightPosition(0.0, 0.0),
		leftPid(5.0, 0.0, 1.0),
		rightPid(5.0, 0.0, 1.0)
	{
		width = _width;
		predictedCentre = centre;
		leftPosition = centre + width/2*Point2(angle-r(90));
		rightPosition = centre - width/2*Point2(angle-r(90));
	}

	void SimPos(Motion motion, float deltaTime) {
		const float step = 0.001;
		float rem = deltaTime;
		for(; rem>=0.0; rem-=step) {
			SimStep(motion, step);
		} 

		SimStep(motion, rem+step);
	}

	Point2 PredictedCentre() {
		return predictedCentre;
	}

	Point2 RealCentre() {
		return 0.5*(leftPosition + rightPosition);
	}

	void ApplyAccel(float impulse, float& vel, float step, float accel, float decel) {
		float targetAccel = clamp(impulse, -1.0, 1.0);

		if((targetAccel > 0 && vel > 0) || (targetAccel < 0 && vel < 0)) {
			targetAccel *= accel;
		} else {
			targetAccel *= decel;
		}

		vel += step * targetAccel;
	}

	void SimStep(Motion motion, float step) {
		Point2 forwards = Direction();

		Point2 oldLeft = leftPosition;
		Point2 oldRight = rightPosition;

		float leftTarget = motion.GetLeftSpeed(width);
		float rightTarget = motion.GetRightSpeed(width);
		float leftAccel = leftPid.Calc(leftSpeed, leftTarget, step);
		ApplyAccel(leftAccel, leftSpeed, step, 1000.0, 1000.0);
		float rightAccel = rightPid.Calc(rightSpeed, rightTarget, step);
		ApplyAccel(rightAccel, rightSpeed, step, 1000.0, 1000.0);

		leftPosition = leftPosition + step*leftSpeed*forwards;
		rightPosition = rightPosition + step*rightSpeed*forwards;

		Point2 midpoint = RealCentre();
		Point2 sideways = (leftPosition - rightPosition).normalize();

		leftPosition = midpoint + (width/2)*sideways;
		rightPosition = midpoint - (width/2)*sideways;

		if(leftSpeed > 0.0) {
			leftEncoder += (leftPosition - oldLeft).length();
		} else {
			leftEncoder -= (leftPosition - oldLeft).length();
		}
		if(rightSpeed > 0.0) {
			rightEncoder += (rightPosition - oldRight).length();
		} else {
			rightEncoder -= (rightPosition - oldRight).length();
		}

		timeSinceLastUpdate += step;
		totalTime += step;
		if(timeSinceLastUpdate > 0.01) {
			float newDistance = ((leftEncoder - lastLeftEncoder) + (rightEncoder - lastRightEncoder))/2.0 ;
			float newDirection = Direction();
			predictedCentre = predictedCentre + 
				newDistance*Point2(newDirection);

			lastLeftEncoder = leftEncoder;
			lastRightEncoder = rightEncoder;
			timeSinceLastUpdate = 0.0;
		}
	}

	float Direction() {
		Point2 sideways = leftPosition - rightPosition;
		float sidewaysDir = atan2(sideways.y, sideways.x);
		return sidewaysDir + r(90);
	}

	void PrintState() {
		std::cout << "{left: {x: " << leftPosition.x << ", y: " << leftPosition.y << "}, right: {x: " << rightPosition.x << ", y: " << rightPosition.y << "}, centre: {x: " << predictedCentre.x << ", y: " << predictedCentre.y << "}},\n";
	}
};
