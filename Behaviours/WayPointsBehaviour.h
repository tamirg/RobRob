/*
 * WayPointsBehaviour.h
 *
 *  Created on: Jun 26, 2015
 *      Author: colman
 */

#ifndef WAYPOINTSBEHAVIOUR_H_
#define WAYPOINTSBEHAVIOUR_H_

#include "../Robot.h"
#include "Behavior.h"

class WayPointsBehaviour: public Behavior {
protected:
    Location* _targetLocation;
    Location* _currentLocation;

public:
	WayPointsBehaviour(Robot* robot);
	virtual ~WayPointsBehaviour();
    void SetDestLocation(Location* destLoc);
    void SetCurrLocation(Location* currLoc);
};

#endif /* WAYPOINTSBEHAVIOUR_H_ */
