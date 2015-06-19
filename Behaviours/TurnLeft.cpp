#include "TurnLeft.h"

TurnLeft::TurnLeft(Robot* robot) :
		Behavior(robot) {
}

bool TurnLeft::startCond() {
	for (int j = Helper::DegreesToIndex(0); j < Helper::DegreesToIndex(30);
			j++) {
		if (_robot->getLaserDistance(j) <= (Helper::MINIMUM_WALL_RANGE * 1.2)) {
			return false;
		}
	}
	cout << "TurnLeft start cond triggered" << endl;
	return true;
}

bool TurnLeft::stopCond() {
	for (int i = Helper::DegreesToIndex(-30); i < (Helper::DegreesToIndex(30));
			i++) {
		if (_robot->getLaserDistance(i) < Helper::MINIMUM_WALL_RANGE * 1.2) {
			return !(startCond());
		}

	}
	cout << "TurnLeft stop cond triggered" << endl;
	return true;
}

void TurnLeft::action() {
	_robot->setSpeed(0.5, 1.2);
}

TurnLeft::~TurnLeft() {
}
