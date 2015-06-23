/*
 * AdvanceToPoint.h
 *
 *  Created on: Jun 6, 2015
 *      Author: colman
 */

#ifndef ADVANCETOPOINT_H_
#define ADVANCETOPOINT_H_

#include "Behavior.h"

class AdvanceToPoint: public Behavior {
private:
    Location* _currentLocation;
    Location* _targetLocation;
public:
    AdvanceToPoint(Robot* robot, Location* currentLocation, Location* targetLocation);
    bool startCond();
    bool stopCond();
    void action();
    void SetDestLocation(Location destLoc);
    // his stop condition is that the angle is too far of a treshhold (30 degreee)
};

#endif /* ADVANCETOPOINT_H_ */
