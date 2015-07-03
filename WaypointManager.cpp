/*
 * WaypointManager.cpp
 *
 *  Created on: Jun 23, 2015
 *      Author: colman
 */

#include <math.h>
#include "WaypointManager.h"
#include "Location.h"
#include "Helper.h"

WaypointManager::WaypointManager(std::vector<GraphLocation> const &path) {
	constructWayPoints(path);
}

WaypointManager::~WaypointManager() {
	// TODO Auto-generated destructor stub
}

Location WaypointManager::nextWaypoint() {
	return _waypoints[_waypointIndex++];
}

bool WaypointManager::isFinished() {
	return _waypointIndex >= _waypoints.size();
}

void WaypointManager::constructWayPoints(std::vector<GraphLocation> const &path) {
	GraphLocation currLocation = path.front();

	Location lastGraphLoc = Helper::MapCellToMetersLocation(path[0].x, path[0].y);
	Location nextGraphLoc;

	for (std::vector<GraphLocation>::const_iterator it = (path.begin() + 1); it != path.end(); ++it) {
		nextGraphLoc = Helper::MapCellToMetersLocation(it->x, it->y);

		if (Helper::distanceBetweenTwoLocations(&lastGraphLoc, &nextGraphLoc) > 0.2) {
			_waypoints.push_back(constructLocation(currLocation, *it));

			currLocation = *it;
			lastGraphLoc = Helper::MapCellToMetersLocation(currLocation.x, currLocation.y);
		}
	}

	GraphLocation lastLocation = path.back();

	if (lastLocation.x != currLocation.x || lastLocation.y != currLocation.y) {
		_waypoints.push_back(constructLocation(currLocation, lastLocation));
	}
}

Location WaypointManager::constructLocation(GraphLocation const &from, GraphLocation const &to) {
	// This relies on the fact that (0,0) is top left
	int a = from.y - to.y;
	int b = to.x - from.x;

	double angel = atan2(a, b);
	angel = (angel > 0 ? angel : (2*M_PI + angel)) * 360 / (2*M_PI);
	angel = angel == 360 ? 0 : angel;

	Location destination;
	destination.setX(to.x);
	destination.setY(to.y);
	destination.setYaw(angel);

	return destination;
}
