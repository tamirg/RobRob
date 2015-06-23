/*
 * rotate_to_point.cpp
 *
 *  Created on: Jun 6, 2015
 *      Author: colman
 */

#include "RotateToPoint.h"

RotateToPoint::RotateToPoint(Robot* robot, Location* currentLocation, Location* targetLocation)
: Behavior(robot)
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
    double targetYaw = calcRadianAngleBetweenLocations(_currentLocation, _targetLocation);
    double delta = abs(targetYaw - _currentLocation->getYaw());

    if (delta < ROTATETOPOINT_ANGLE_EPSILON_R)
    {
        cout << "Reached to target yaw" << endl;
        return true;
    }

    cout << "Delta to target yaw: " << RadToDeg(delta) << "deg" << endl;
    return false;
}

void RotateToPoint::SetDestLocation(Location destLoc) {
	_targetLocation = destLoc;
}

void RotateToPoint::action() {

}

