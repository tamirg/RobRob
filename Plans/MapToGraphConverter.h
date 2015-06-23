/*
 * MapToGraphConverter.h
 *
 *  Created on: Jun 19, 2015
 *      Author: colman
 */

#ifndef MAPTOGRAPHCONVERTER_H_
#define MAPTOGRAPHCONVERTER_H_
#include "Graph.h"
#include "GraphLocation.h"
#include "../Map.h"
#include <vector>

using namespace std;

class MapToGraphConverter {
public:
	MapToGraphConverter();
	virtual ~MapToGraphConverter();
	Graph* matrixToGraph(Map* map);
private:
	vector<GraphLocation>* findNeighbors(int* map, int width, int height, int row, int col);
	void addNeighbor(int cellVal, int cellRow, int cellCol, vector<GraphLocation>* neighbors);
	int getValueFromArray(int* arr, int arrWidth, int row, int col);
};

#endif /* MAPTOGRAPHCONVERTER_H_ */
