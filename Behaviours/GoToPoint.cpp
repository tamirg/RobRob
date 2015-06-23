/*
 * GoToPoint.cpp
 *
 *  Created on: Jun 6, 2015
 *      Author: colman
 */

#include "GoToPoint.h"

GoToPoint::GoToPoint(Robot* robot, Location* currentLocation, Location* targetLocation) :
		Behavior(robot) {
	_currentLocation = currentLocation;
	_targetLocation = targetLocation;
}

bool GoToPoint::startCond() {
	return true;
}
bool GoToPoint::stopCond() {
	if (!onTarget())
		return true;
	return false;
}
void GoToPoint::action() {
	if (_waypointsManager->isFinished()) {
		cout << "reached final target" << endl;
	} else {
		bool isOnTarget = onTarget();
		if (isOnTarget) {
			// update target location
			_targetLocation = _waypointsManager->nextWaypoint();
		}
	}
}



void GoToPoint::initWaypointsManager(WaypointManager* waypointManager) {
	_waypointsManager = waypointManager;
}

GoToPoint::~GoToPoint() {
}

