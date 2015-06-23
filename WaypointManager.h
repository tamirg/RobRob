/*
 * WaypointManager.h
 *
 *  Created on: Jun 23, 2015
 *      Author: colman
 */

#ifndef WAYPOINTMANAGER_H_
#define WAYPOINTMANAGER_H_

#include <vector>
#include "Location.h"
#include "Plans/GraphLocation.h"

class WaypointManager {
private:
	std::vector<Location> _waypoints;
	int _waypointIndex;

	void constructWayPoints(std::vector<GraphLocation> const &path);
	Location constructLocation(GraphLocation const &from, GraphLocation const &to);

public:
	WaypointManager(std::vector<GraphLocation> const &path);
	virtual ~WaypointManager();
	Location nextWaypoint();
	bool isFinished();
};

#endif /* WAYPOINTMANAGER_H_ */
