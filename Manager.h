#ifndef MANAGER_H_
#define MANAGER_H_

#include "Plans/Plan.h"
#include "Behaviours/Behavior.h"
#include "Robot.h"
#include "LocalizationManager.h"
#include "Plans/PathFinder.h"
#include "Plans/MapToGraphConverter.h"
#include "ConfigurationManager.h"
#include "Plans/GoToPointPlan.h"
#include "WaypointManager.h"
#include <math.h>


class Manager
{
private:
	Robot* _robot;
	GoToPointPlan* _plan;
	Behavior* _curr;
	LocalizationManager* _LocalizationManager;
	WaypointManager* _waypointsManager;
	ConfigurationManager* _config;
	float _laserScan[SCAN_SPAN];

public:
	Manager(Robot* robot, GoToPointPlan* plan, Map* map, ConfigurationManager* config,
			MapToGraphConverter* mapConverter, PathFinder* pathFinder);
	bool onTarget(Location* firstLoc, Location* secondLoc);
	void run();
	virtual ~Manager();
};

#endif /* MANAGER_H_ */
