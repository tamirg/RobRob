/*
 * GoToPointPlan.cpp
 *
 *  Created on: Jun 6, 2015
 *      Author: colman
 */

#include "GoToPointPlan.h"

GoToPointPlan::GoToPointPlan(Robot* robot) :
		Plan(robot) {
	_currLocation = robot->getCurrLocation();
	_dstLocation = new Location(0, 0, 0);
	_rotateToPointBeh = new RotateToPoint(_robot, _currLocation, _dstLocation);
	_advanceToPointBeh = new AdvanceToPoint(_robot, _currLocation,
			_dstLocation);

	_rotateToPointBeh->addNext(_advanceToPointBeh);
	_advanceToPointBeh->addNext(_rotateToPointBeh);

	_starBeh = _rotateToPointBeh;
	_currBeh = _rotateToPointBeh;
}

void GoToPointPlan::SetCurrentLocation(Location* loc) {
	_currLocation = loc;
	_rotateToPointBeh->SetCurrLocation(loc);
	_advanceToPointBeh->SetCurrLocation(loc);
}

void GoToPointPlan::SetDestLocation(Location* destLoc) {
	_dstLocation = destLoc;
	_rotateToPointBeh->SetDestLocation(destLoc);
	_advanceToPointBeh->SetDestLocation(destLoc);
}

Location* GoToPointPlan::getCurrentLocation()
{
	return _currLocation;
}

GoToPointPlan::~GoToPointPlan() {
	delete _currLocation;
	delete _dstLocation;
	delete _rotateToPointBeh;
	delete _advanceToPointBeh;
}
