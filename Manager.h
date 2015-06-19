#ifndef MANAGER_H_
#define MANAGER_H_

#include "Plans/Plan.h"
#include "Behaviours/Behavior.h"
#include "Robot.h"
#include "LocalizationManager.h"
#include "Plans/PathFinder.h"
#include "Plans/MapToGraphConverter.h"
#include "ConfigurationManager.h"

class Manager
{
private:
	Robot* _robot;
	Plan* _plan;
	Behavior* _curr;
	LocalizationManager* _LocalizationManager;
	float _laserScan[SCAN_SPAN];

public:
	Manager(Robot* robot, Plan* plan, Map* map, ConfigurationManager* config,
			MapToGraphConverter* mapConverter, PathFinder* pathFinder);

	void run();
	virtual ~Manager();
};

#endif /* MANAGER_H_ */
