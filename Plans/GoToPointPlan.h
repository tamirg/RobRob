/*
 * GoToPointPlan.h
 *
 *  Created on: Jun 6, 2015
 *      Author: colman
 */

#ifndef GOTOPOINTPLAN_H_
#define GOTOPOINTPLAN_H_

#include <vector>
#include "Plan.h"
#include "../Location.h"
#include "../Behaviours/GoToPoint.h"
#include "../Behaviours/RotateToPoint.h"
#include "../Behaviours/AdvanceToPoint.h"
#include "../Behaviours/TurnInPlace.h"
#include "../Behaviours/WayPointsBehaviour.h"

class GoToPointPlan: public Plan {
private:
    std::vector<Location> _locations;
    Location* _currLocation;
    Location* _dstLocation;
    WayPointsBehaviour* _rotateToPointBeh;
    WayPointsBehaviour* _advanceToPointBeh;
    WayPointsBehaviour* _currBeh;

public:
    GoToPointPlan(Robot* robot);
    void SetCurrentLocation(Location* loc);
    void SetDestLocation(Location* destLoc);
    Location* getCurrentLocation();
    void goToPoint();
    void Init(WaypointManager* waypointManager);
    virtual ~GoToPointPlan();
};

#endif /* GOTOPOINTPLAN_H_ */
