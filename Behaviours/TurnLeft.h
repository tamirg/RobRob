#ifndef TURNLEFT_H_
#define TURNLEFT_H_

#include <iostream>
#include "Behavior.h"
#include "GoForward.h"
#include "../Robot.h"

class TurnLeft: public Behavior
{
public:
	TurnLeft(Robot* robot);
	bool startCond();
	bool stopCond();
	void action();
	virtual ~TurnLeft();

};

#endif /* TurnLeft_H_ */
