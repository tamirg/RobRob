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

class PathFinder {
public:
    PathFinder();
    PathFinder(const PathFinder& orig);
    virtual ~PathFinder();
    void aStarSearch
        (Graph graph,
         GraphLocation start,
         GraphLocation goal,
         std::map<GraphLocation, GraphLocation>& came_from,
         std::map<GraphLocation, int>& cost_so_far);
};
#endif	/* PATHFINDER_H */

