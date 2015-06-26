/*
 * WayPointsBehaviour.cpp
 *
 *  Created on: Jun 26, 2015
 *      Author: colman
 */

#include "WayPointsBehaviour.h"

WayPointsBehaviour::WayPointsBehaviour(Robot* robot)
	:Behavior(robot)
{

}

WayPointsBehaviour::~WayPointsBehaviour() {
	// TODO Auto-generated destructor stub
}

void WayPointsBehaviour::SetDestLocation(Location* destLoc) {
	_targetLocation = destLoc;
}

void WayPointsBehaviour::SetCurrLocation(Location* currLoc) {
	_currentLocation = currLoc;
}
