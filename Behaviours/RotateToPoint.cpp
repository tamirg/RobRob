/*
 * rotate_to_point.cpp
 *
 *  Created on: Jun 6, 2015
 *      Author: colman
 */

#include "RotateToPoint.h"

RotateToPoint::RotateToPoint(Robot* robot, Location* currentLocation, Location* targetLocation)
: WayPointsBehaviour(robot)
{
    _currentLocation = currentLocation;
    _targetLocation = targetLocation;
}

bool RotateToPoint::startCond()
{
	return true;
}

bool RotateToPoint::stopCond()
{
	bool isInDirection = false;

	double targetYaw = _targetLocation->getYaw();
	double delta = DTOR(targetYaw) - _currentLocation->getYaw();

	if (abs(delta) < DTOR(5)) {
		cout << "delta Yaw bigger than " << RTOD(5) << endl;
		isInDirection = true;
	}

	cout << "Delta angle:" << RTOD(delta) << endl;
	cout << "Target angle:" << targetYaw << endl;

	return (isInDirection);
}

void RotateToPoint::action() {
	_robot->setSpeed(0, 0.3);
}

