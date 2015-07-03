#include "Manager.h"

Manager::Manager(Robot* robot, GoToPointPlan* plan, Map* map,
		ConfigurationManager* config, MapToGraphConverter* mapConverter,
		PathFinder* pathFinder) {
	_robot = robot;
	_plan = plan;
	_LocalizationManager = new LocalizationManager(
			M_TO_CM(_robot->_location->getX()),
			M_TO_CM(_robot->_location->getY()), map);

	_config = config;

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

	while (!_waypointsManager->isFinished()) {
		_curr = _plan->getStartingBehavior();
		Location nextLoc = _waypointsManager->nextWaypoint();
		cout << "Avarnu waypoint. Yay" << endl;
		Location* destLoc = new Location(
				CM_TO_M(nextLoc.getX() * _config->GetMapResolutionCM()),
				CM_TO_M(nextLoc.getY() * _config->GetMapResolutionCM()),
				DTOR(nextLoc.getYaw()));
		//	cout<<"Location: " << _robot->getCurrLocation()->getX() << ", "<< _robot->getCurrLocation()->getY() << ", "<< _robot->getCurrLocation()->getYaw()<<endl;
		//cout<<"Dest Location: " <<destLoc->getX() << ", "<< destLoc->getY() << ", "<< destLoc->getYaw()<<endl;
		_plan->SetDestLocation(destLoc);
		_curr->action();

		while (!onTarget(_plan->getCurrentLocation(), destLoc)) {
			if (_curr->stopCond()) {
				_curr = _curr->selectNext();

				if (_curr) {
					_curr->action();
				}
			}

			_robot->read();
			_robot->getDelta(dX, dY, dYaw);
			/*for (int i = 0; i < SCAN_SPAN; i++)
			 _laserScan[i] = _robot->getLaserDistance(i);
			 _LocalizationManager->UpdateParticles(dX, dY, dYaw, _laserScan);*/
			_plan->SetCurrentLocation(_robot->getCurrLocation());
			//cout<<"Location: " << _robot->getCurrLocation()->getX() << ", "<< _robot->getCurrLocation()->getY() << ", "<< _robot->getCurrLocation()->getYaw()<<endl;
		}
		_robot->read();
		_robot->getDelta(dX, dY, dYaw);
		//for (int i = 0; i < SCAN_SPAN; i++)
		//	_laserScan[i] = _robot->getLaserDistance(i);
		//_LocalizationManager->UpdateParticles(dX, dY, dYaw, _laserScan);
		_plan->SetCurrentLocation(_robot->getCurrLocation());

		_robot->setSpeed(0, 0);
	}

	_robot->setSpeed(0, 0);

	if (_waypointsManager->isFinished()) {
		cout << "reached final target" << endl;
	}
}

bool Manager::onTarget(Location* firstLoc, Location* secondLoc) {
//	cout << "Distance: "
//			<< Helper::distanceBetweenTwoLocations(firstLoc, secondLoc) << endl;
	//cout << "Distance between points: " << Helper::distanceBetweenTwoLocations(firstLoc, secondLoc) << endl;
	if (Helper::distanceBetweenTwoLocations(firstLoc, secondLoc) < 0.2)
		return true;
	return false;
}
