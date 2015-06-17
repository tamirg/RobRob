///*
// * File:   PathFinder.cpp
// * Author: Ido
// *
// * Created on 16 יוני 2015, 19:19
// */
//
//#include <stdlib.h>
//#include <math.h>
//#include <set>
//#include "PathFinder.h"
//#include "PriorityQueue.h"
//
//using namespace std;
//
//PathFinder::PathFinder() {
//}
//
//PathFinder::PathFinder(const PathFinder& orig) {
//}
//
//PathFinder::~PathFinder() {
//}
//
//static const int directionsNum = 4;
//static const Location directions[4] = {Location(1,0), Location(0,-1), Location(-1,0), Location(0,1)};
//
//void PathFinder::add_neighbor(int cellVal, int cellRow, int cellCol, vector<Location>* neighbors) {
//    switch (cellVal)
//    {
//        case EMPTY_CELL:
//            neighbors->insert(neighbors->begin(), Location(cellCol, cellRow));
//            break;
//    }
//}
//
//vector<Location>* PathFinder::find_neighbors(int* map, int width, int height, int row, int col)
//{
//    int minRow = row>0 ? row-1 : 0;
//    int minCol = col>0 ? col-1 : 0;
//    int maxRow = row<(height-1) ? row+1 : height;
//    int maxCol = col<(width-1) ? col+1 : width;
//
//    vector<Location>* neighbors = new vector<Location>();
//
//    for (int i = 0; i < directionsNum; ++i) {
//        int curRow = row + directions[i].y;
//        int curCol = col + directions[i].x;
//
//        // Checks if the location is within the boundaries
//        if (curRow > 0 && curCol > 0 && curRow < height && curCol <width) {
//            int cellVal = getValueFromArray(map, width, curRow, curCol);
//            add_neighbor(cellVal, curRow, curCol, neighbors);
//        }
//    }
//
//    return neighbors;
//}
//
//Graph* PathFinder::matrix_to_graph(int* map, int width, int height) {
//    Graph* graph = new Graph();
//
//    for (int row = 0; row < height; ++row) {
//        for (int col = 0; col < width; ++col) {
//            switch (this->getValueFromArray(map, width, row, col)) {
//                case EMPTY_CELL:
//                    Location current(col, row);
//                    graph->edges[current] = *find_neighbors(map, width, height, row, col);
//                    break;
//            }
//        }
//    }
//
//    return graph;
//}
//
//inline int heuristic(Location a, Location b) {
//    return abs(a.x - b.x) + abs(a.y - b.y);
//}
//
//void PathFinder::a_star_search
//        (Graph graph,
//         Location start,
//         Location goal,
//         map<Location, Location>& came_from,
//         map<Location, int>& cost_so_far) {
//    PriorityQueue<Location> frontier;
//    frontier.put(start, 0);
//
//    came_from[start] = start;
//    cost_so_far[start] = 0;
//
//    while (!frontier.empty()) {
//        Location current = frontier.get();
//
//        if (current == goal) {
//          break;
//        }
//
//        vector<Location> neighbors = graph.neighbors(current);
//        for(std::vector<Location>::iterator it = neighbors.begin(); it != neighbors.end(); ++it) {
//            Location next = *it;
//            // Calculates the new cost.
//            // Ideally, we would call graph.cost to calculate the cost of the movement.
//            // Since each step in every direction has the same cost, we use 1 as the cost.
//            int new_cost = cost_so_far[current] + 1;
//
//            if (!cost_so_far.count(next) || new_cost < cost_so_far[next]) {
//                cost_so_far[next] = new_cost;
//                int priority = new_cost + heuristic(next, goal);
//                frontier.put(next, priority);
//                came_from[next] = current;
//            }
//        }
//    }
//}
//
//int PathFinder::getValueFromArray(int* arr, int arrWidth, int row, int col) {
//    return arr[(arrWidth * row) + col];
//}
