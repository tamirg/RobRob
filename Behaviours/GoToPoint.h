/*
 * GoToPoint.h
 *
 *  Created on: Jun 6, 2015
 *      Author: colman
 */

#ifndef GOTOPOINT_H_
#define GOTOPOINT_H_

#include "Behavior.h"
#include "../Location.h"
#include "../Helper.h"
#include <math.h>

class GoToPoint: public Behavior {
private:
	int _currentWaypointIndex;
    Location* _currentLocation;
    Location* _targetLocation;
    WaypointManager* _waypointsManager;

    bool onTarget();
public:
	GoToPoint(Robot* robot, Location* currentLocation, Location* targetLocation);
    bool startCond();
    bool stopCond();
    void action();
    void initWaypointsManager(WaypointManager* waypointManager);
	virtual ~GoToPoint();
};

#endif /* GOTOPOINT_H_ */
