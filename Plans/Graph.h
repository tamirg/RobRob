/* 
 * File:   Graph.h
 * Author: Ido
 *
 * Created on 16 יוני 2015, 19:54
 */

#ifndef GRAPH_H
#define	GRAPH_H

#include "GraphLocation.h"
#include <vector>
#include <map>

using namespace std;

struct Graph
{
	GraphLocation location;
    vector<GraphLocation>::iterator iterator;
    map<GraphLocation, vector<GraphLocation> > edges;
    
    inline const vector<GraphLocation> neighbors(GraphLocation id) {
        return edges[id];
    }
};

#endif	/* GRAPH_H */

