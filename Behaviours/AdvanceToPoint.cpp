/*
 * AdvanceToPoint.cpp
 *
 *  Created on: Jun 6, 2015
 *      Author: colman
 */

#include "AdvanceToPoint.h"
#include "../Helper.h"

AdvanceToPoint::AdvanceToPoint(Robot* robot, Location* currentLocation,
		Location* targetLocation) :
		WayPointsBehaviour(robot) {
	_currentLocation = currentLocation;
	_targetLocation = targetLocation;

}

bool AdvanceToPoint::startCond() {
	return true;
}

bool AdvanceToPoint::stopCond() {
	if (Helper::distanceBetweenTwoLocations(_currentLocation, _targetLocation) < 0.2)
		return true;
	return false;

	bool rotateIsRequired = false;

	double targetYaw = _targetLocation->getYaw();
	double delta = DTOR(targetYaw) - _currentLocation->getYaw();

	if (abs(delta) > (double)DTOR(5)) {
		cout << "delta Yaw bigger than " << RTOD(5) << endl;
		rotateIsRequired = true;
	}

	return (rotateIsRequired);
}

void AdvanceToPoint::action() {
	_robot->setSpeed(0.6, 0.0);
}

