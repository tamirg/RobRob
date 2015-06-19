/*
 * File:   PathFinder.cpp

 * Author: Ido
 *
 * Created on 16 יוני 2015, 19:19
 */

#include <stdlib.h>
#include <math.h>
#include <set>
#include "PathFinder.h"
#include "PriorityQueue.h"

using namespace std;

PathFinder::PathFinder() {
}


PathFinder::PathFinder(const PathFinder& orig) {
}


PathFinder::~PathFinder() {
}


inline int heuristic(GraphLocation a, GraphLocation b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}


void PathFinder::aStarSearch(Graph graph, GraphLocation start, GraphLocation goal,
		map<GraphLocation, GraphLocation>& came_from, map<GraphLocation, int>& cost_so_far) {
	PriorityQueue<GraphLocation> frontier;
	frontier.put(start, 0);

	came_from[start] = start;
	cost_so_far[start] = 0;

	while (!frontier.empty()) {
		GraphLocation current = frontier.get();

		if (current == goal) {
			break;
		}

		vector<GraphLocation> neighbors = graph.neighbors(current);
		for (std::vector<GraphLocation>::iterator it = neighbors.begin();
				it != neighbors.end(); ++it) {
			GraphLocation next = *it;
			// Calculates the new cost.
			// Ideally, we would call graph.cost to calculate the cost of the movement.
			// Since each step in every direction has the same cost, we use 1 as the cost.
			int new_cost = cost_so_far[current] + 1;

			if (!cost_so_far.count(next) || new_cost < cost_so_far[next]) {
				cost_so_far[next] = new_cost;
				int priority = new_cost + heuristic(next, goal);
				frontier.put(next, priority);
				came_from[next] = current;
			}
		}
	}
}

