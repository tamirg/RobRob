#include "Manager.h"

Manager::Manager(Robot* robot, GoToPointPlan* plan, Map* map,
		ConfigurationManager* config, MapToGraphConverter* mapConverter,
		PathFinder* pathFinder) {
	_robot = robot;
	_plan = plan;
	_LocalizationManager = new LocalizationManager(_robot->_location->getX(),
			_robot->_location->getY(), map);

	Graph* graph = mapConverter->matrixToGraph(map);

	GraphLocation startLocation(config->GetStartLocationX(),
			config->GetStartLocationY());
	GraphLocation targetLocation(config->GetGoalX(), config->GetGoalY());

	vector<GraphLocation> movementPath = pathFinder->aStarSearch(*graph,
			startLocation, targetLocation);

	_waypointsManager = new WaypointManager(movementPath);

	delete graph;
}

Manager::~Manager() {
	delete _waypointsManager;
}

void Manager::run() {
	double dX, dY, dYaw;
	_robot->read();

	bool isReachedGoal = false;

	while (!isReachedGoal) {
		_curr = _plan->getStartingBehavior();
		_plan->SetDestLocation(_waypointsManager->nextWaypoint());
		// not good, need to update current location for plan from particles.
		// do go to point on this loop
		_plan->goToPoint();

		_robot->getDelta(dX, dY, dYaw);
		for (int i = 0; i < SCAN_SPAN; i++)
			_laserScan[i] = _robot->getLaserDistance(i);
		_LocalizationManager->UpdateParticles(dX, dY, dYaw, _laserScan);

		bool isOnTarget = onTarget();
		if (isOnTarget) {
			// update target location
			_targetLocation = _waypointsManager->nextWaypoint();
		}

	}

	if (_waypointsManager->isFinished()) {
		cout << "reached final target" << endl;
	}

//	if (_curr->startCond() == false) {
//		return;
//	}
//
//	_curr->action();
//	while (true) {
//		_robot->read();
//		if (_curr->stopCond()) {
//			_curr = _curr->selectNext();
//			_curr->action();
//			if (!_curr) {
//				break;
//			}
//		}
//
//		_robot->getDelta(dX,dY,dYaw);
//		for (int i = 0; i < SCAN_SPAN; i++)
//			_laserScan[i] = _robot->getLaserDistance(i);
//		_LocalizationManager->UpdateParticles(dX, dY, dYaw, _laserScan);
//
//	}

}

bool Manager::onTarget(Location* firstLoc, Location* secondLoc) {
	if (distanceBetweenTwoLocations(firstLoc, secondLoc) < 0.2)
		return true;
	return false;
}
