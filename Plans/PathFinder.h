/* 
 * File:   PathFinder.h
 * Author: Ido
 *
 * Created on 16 יוני 2015, 19:19
 */

#ifndef PATHFINDER_H
#define	PATHFINDER_H

#include "GraphLocation.h"
#include "Graph.h"
#include <vector>

class PathFinder {
private:
	std::vector<GraphLocation> reconstructPath(GraphLocation start,
										  	   GraphLocation goal,
										       std::map<GraphLocation, GraphLocation>& came_from);
public:
    PathFinder();
    PathFinder(const PathFinder& orig);
    virtual ~PathFinder();
    std::vector<GraphLocation> aStarSearch(Graph graph, GraphLocation start, GraphLocation goal);
};
#endif	/* PATHFINDER_H */

