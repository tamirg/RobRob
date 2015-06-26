/*
 * AdvanceToPoint.h
 *
 *  Created on: Jun 6, 2015
 *      Author: colman
 */

#ifndef ADVANCETOPOINT_H_
#define ADVANCETOPOINT_H_

#include <math.h>
#include <cmath>
#include "Behavior.h"
#include "WayPointsBehaviour.h"

class AdvanceToPoint: public WayPointsBehaviour {

public:
    AdvanceToPoint(Robot* robot, Location* currentLocation, Location* targetLocation);
    bool startCond();
    bool stopCond();
    void action();
    // his stop condition is that the angle is too far of a treshhold (30 degreee)
};

#endif /* ADVANCETOPOINT_H_ */
