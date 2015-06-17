/* 
 * File:   Graph.h
 * Author: Ido
 *
 * Created on 16 יוני 2015, 19:54
 */

#ifndef GRAPH_H
#define	GRAPH_H

#include "Location.h"
#include <vector>
#include <map>

using namespace std;

struct Graph
{
    Location location;
    vector<Location>::iterator iterator;
    map<Location, vector<Location> > edges;
    
    inline const vector<Location> neighbors(Location id) {
        return edges[id];
    }
};

#endif	/* GRAPH_H */

