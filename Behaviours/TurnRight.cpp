#include "TurnRight.h"

TurnRight::TurnRight(Robot* robot) :
		Behavior(robot) {
}

bool TurnRight::startCond() {
	cout<< "Right mothafuka";
	for (int j = Helper::DegreesToIndex(-30); j < Helper::DegreesToIndex(0);
				j++) {
			if (_robot->getLaserDistance(j) <= (Helper::MINIMUM_WALL_RANGE * 1.2)) {
				return false;
			}
		}
		cout << "TurnRight start cond triggered" << endl;
		return true;
}

bool TurnRight::stopCond() {
	cout<<"stop right";
	for (int i = Helper::DegreesToIndex(-30); i < (Helper::DegreesToIndex(30));
				i++) {
			if (_robot->getLaserDistance(i) < Helper::MINIMUM_WALL_RANGE * 1.2) {
				return !(startCond());
			}
		}
		cout << "TurnRight stop cond triggered" << endl;
		return true;
}

void TurnRight::action() {
	_robot->setSpeed(0.5, -1.2);
}

TurnRight::~TurnRight() {
}
