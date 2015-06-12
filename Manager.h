#ifndef MANAGER_H_
#define MANAGER_H_

#include "Plans/Plan.h"
#include "Behaviours/Behavior.h"
#include "Robot.h"
#include "LocalizaionManager.h"

class Manager
{
private:
	Robot* _robot;
	Plan* _plan;
	Behavior* _curr;
	LocalizaionManager* _LocalizationManager;
	float _laserScan[SCAN_SPAN];

public:
	Manager(Robot* robot, Plan* plan);
	void run();
	virtual ~Manager();
};

#endif /* MANAGER_H_ */
