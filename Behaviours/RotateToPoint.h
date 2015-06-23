/*
 * rotatebehavior.h
 *
 *  Created on: Jun 6, 2015
 *      Author: colman
 */

#ifndef ROTATEBEHAVIOR_H_
#define ROTATEBEHAVIOR_H_

#include "behavior.h"

#define TURN_SPEED      DTOR(20)

class RotateToPoint: public Behavior {

private:
    Location* _targetLocation;
    Location* _currentLocation;

public:
    RotateToPoint(Robot* , Location* , Location* );
    bool startCond();
    bool stopCond();
    void action();
    void SetDestLocation(Location destLoc);
    // Needs to set the robot yaw until it's reached to the targetRadianDegree

};

#endif /* ROTATEBEHAVIOR_H_ */
