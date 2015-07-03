/*
 * rotatebehavior.h
 *
 *  Created on: Jun 6, 2015
 *      Author: colman
 */

#ifndef ROTATETOPOINT_H_
#define ROTATETOPOINT_H_

#include "Behavior.h"
#include "../Behaviours/WayPointsBehaviour.h"
#include <cmath>

#define TURN_SPEED DTOR(20)

class RotateToPoint: public WayPointsBehaviour {

public:
    RotateToPoint(Robot* , Location* , Location* );
    bool startCond();
    bool stopCond();
    void action();
    // Needs to set the robot yaw until it's reached to the targetRadianDegree

};

#endif /* ROTATETOPOINT_H_ */
