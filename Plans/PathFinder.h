/* 
 * File:   PathFinder.h
 * Author: Ido
 *
 * Created on 16 יוני 2015, 19:19
 */

#ifndef PATHFINDER_H
#define	PATHFINDER_H

#include "Location.h"
#include "Graph.h"

class PathFinder {
public:
    PathFinder();
    PathFinder(const PathFinder& orig);
    virtual ~PathFinder();
    Graph* matrix_to_graph(int* map, int width, int height); 
    void a_star_search
        (Graph graph,
         Location start,
         Location goal,
         std::map<Location, Location>& came_from,
         std::map<Location, int>& cost_so_far);
private:    
    int getValueFromArray(int* arr, int arrWidth, int row, int col);
    std::vector<Location>* find_neighbors(int* map, int width, int height, int row, int col);
    void add_neighbor(int cellVal, int cellX, int cellY, std::vector<Location>* neighbors);
};

#endif	/* PATHFINDER_H */

