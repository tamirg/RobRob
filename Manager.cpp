#include "Manager.h"

Manager::Manager(Robot* robot, Plan* plan, Map* map,
		ConfigurationManager* config, MapToGraphConverter* mapConverter,
		PathFinder* pathFinder) {
	_robot = robot;
	_plan = plan;
	_curr = plan->startPoint();
	_LocalizationManager = new LocalizationManager(_robot->_location->getX(),
			_robot->_location->getY(), map);
	
	Graph* graph = mapConverter->matrixToGraph(map);

	GraphLocation* startLocation = new GraphLocation(config->GetStartLocationX(), config->GetStartLocationY());
	GraphLocation* targetLocation = new GraphLocation(config->GetGoalX(), config->GetGoalY());

	//TODO: doitch do your magic
//	pathFinder->aStarSearch(graph, startLocation, targetLocation,  )

	delete graph;
}

Manager::~Manager() {

}

void Manager::run() {
	double dX, dY, dYaw;
	_robot->read();
	if (_curr->startCond() == false) {
		return;
	}

	_curr->action();
	while (true) {
		_robot->read();
		if (_curr->stopCond()) {
			_curr = _curr->selectNext();
			_curr->action();
			if (!_curr) {
				break;
			}
		}

		_robot->getDelta(dX,dY,dYaw);
		for (int i = 0; i < SCAN_SPAN; i++)
			_laserScan[i] = _robot->getLaserDistance(i);
		_LocalizationManager->UpdateParticles(dX, dY, dYaw, _laserScan);

	}

}
