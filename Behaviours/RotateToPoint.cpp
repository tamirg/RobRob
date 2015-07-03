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

	cout << "delta yaw is: " << abs(delta) << endl << "targetYaw is: "
			<< targetYaw << endl;
	if (abs(delta) < DTOR(2) || abs(M_PI * 2 - delta) < DTOR(2)) {
		cout << "delta Yaw smaller than " << DTOR(2) << endl;
		isInDirection = true;
	}

	return (isInDirection);
}

void RotateToPoint::action() {
	double targetYaw = _targetLocation->getYaw();
	double delta = targetYaw - _currentLocation->getYaw();
	double leftDelta = abs(M_PI * 2 - delta);
	double rightDelta = abs(delta);
	cout << "leftDelta: " << RTOD(leftDelta) << "Right delta " << RTOD(rightDelta) << endl;

	if (leftDelta < rightDelta) {
		_robot->setSpeed(0.0, -0.2);
	} else {
		_robot->setSpeed(0.0, 0.2);
	}
}

