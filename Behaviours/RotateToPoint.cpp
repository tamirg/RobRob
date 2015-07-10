/*
 * rotate_to_point.cpp
 *
 *  Created on: Jun 6, 2015
 *      Author: colman
 */

#include "RotateToPoint.h"
#include <algorithm>

RotateToPoint::RotateToPoint(Robot* robot, Location* currentLocation,
		Location* targetLocation) :
		WayPointsBehaviour(robot) {
	_currentLocation = currentLocation;
	_targetLocation = targetLocation;
}

bool RotateToPoint::startCond() {
	return true;
}

bool RotateToPoint::stopCond() {
	bool isInDirection = false;

	double targetYaw = _targetLocation->getYaw();
	double delta = targetYaw - _currentLocation->getYaw();

	double targetYawDeg = RTOD(_targetLocation->getYaw());
	double currYawDeg = RTOD(_currentLocation->getYaw());

	if (targetYawDeg < 0) {
		targetYawDeg += 360;
	}

	if (currYawDeg < 0) {
		currYawDeg += 360;
	}

	double deltaDeg = targetYawDeg - currYawDeg;

	if (abs(deltaDeg) < 4) {
		isInDirection = true;
	}

	return isInDirection;

	cout << "delta yaw is: " << abs(delta) << endl << "targetYaw is: "
			<< targetYaw << endl;
	if (abs(delta) < DTOR(4) || abs(M_PI - abs(delta)) < DTOR(2)) {
		cout << "delta Yaw smaller than " << DTOR(2) << endl;
		isInDirection = true;
	}

	return (isInDirection);
}

void RotateToPoint::action() {
	double targetYawDeg = RTOD(_targetLocation->getYaw());
	double currYawDeg = RTOD(_currentLocation->getYaw());

	if (targetYawDeg < 0) {
		targetYawDeg += 360;
	}

	if (currYawDeg < 0) {
		currYawDeg += 360;
	}

	double leftDelta = abs(targetYawDeg - currYawDeg);
	double rightDelta = 360 - (targetYawDeg + currYawDeg);

	if (targetYawDeg < currYawDeg) {
		if (currYawDeg - targetYawDeg < 180) {
			cout << "turning right " << endl;
			_robot->setSpeed(0.0, -0.2);
		}
		else {
			cout << "turning left " << endl;
			_robot->setSpeed(0.0, 0.2);
		}
	}
	else {
		if (targetYawDeg - currYawDeg < 180) {
			cout << "turning left " << endl;
			_robot->setSpeed(0.0, 0.2);
		}
		else {

			cout << "turning right " << endl;
			_robot->setSpeed(0.0, -0.2);
		}
	}

	return;

	cout << "leftDelta: " << leftDelta << " Right delta " << rightDelta << endl;

	if (leftDelta < rightDelta) {
	     cout << "turning left " << endl;
		_robot->setSpeed(0.0, 0.2);
	} else {
		cout << "turning right " << endl;
		_robot->setSpeed(0.0, -0.2);
	}

//	double targetYaw = _targetLocation->getYaw();
//	double delta = targetYaw - _currentLocation->getYaw();
//	double leftDelta = abs(M_PI - abs(delta));
//	double rightDelta = abs(delta);
//	cout << "leftDelta: " << RTOD(leftDelta) << "Right delta " << RTOD(rightDelta) << endl;
//
//	if (leftDelta < rightDelta) {
//		_robot->setSpeed(0.0, 0.2);
//	} else {
//		_robot->setSpeed(0.0, -0.2);
//	}
}

