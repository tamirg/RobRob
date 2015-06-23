/*
 * MapToGraphConverter.cpp
 *
 *  Created on: Jun 19, 2015
 *      Author: colman
 */

#include "MapToGraphConverter.h"
#include "Direction.h"

MapToGraphConverter::MapToGraphConverter() {
}

MapToGraphConverter::~MapToGraphConverter() {
}

static const int directionsNum = 8;
static const Direction directions[8] = { Direction(1, 0),
										 Direction(1, 1),
										 Direction(0, 1),
										 Direction(-1, 1),
										 Direction(-1, 0),
										 Direction(-1, -1),
										 Direction(0, -1),
										 Direction(1, -1) };

Graph* MapToGraphConverter::matrixToGraph(Map* map) {
	Graph* graph = new Graph();
	int* mapGrid = map->getBlownMap();
	int height = map->getBlownMapHeight();
	int width = map->getBlownMapWidth();
	for (int row = 0; row < height; ++row) {
		for (int col = 0; col < width; ++col) {
			switch (this->getValueFromArray(mapGrid, width, row, col)) {
			case Helper::FREE_CELL:
				GraphLocation current(col, row);
				graph->edges[current] = *findNeighbors(mapGrid, width, height,
						row, col);
				break;
			}
		}
	}

	return graph;
}

void MapToGraphConverter::addNeighbor(int cellVal, int cellRow, int cellCol,
		vector<GraphLocation>* neighbors) {
	switch (cellVal) {
	case Helper::FREE_CELL:
		neighbors->insert(neighbors->begin(), GraphLocation(cellCol, cellRow));
		break;
	}
}

vector<GraphLocation>* MapToGraphConverter::findNeighbors(int* map, int width,
		int height, int row, int col) {
	int minRow = row > 0 ? row - 1 : 0;
	int minCol = col > 0 ? col - 1 : 0;
	int maxRow = row < (height - 1) ? row + 1 : height;
	int maxCol = col < (width - 1) ? col + 1 : width;

	vector<GraphLocation>* neighbors = new vector<GraphLocation>();

	for (int i = 0; i < directionsNum; ++i) {
		int curRow = row + directions[i].y;
		int curCol = col + directions[i].x;

		// Checks if the GraphLocation is within the boundaries
		if (curRow > 0 && curCol > 0 && curRow < height && curCol < width) {
			int cellVal = getValueFromArray(map, width, curRow, curCol);
			addNeighbor(cellVal, curRow, curCol, neighbors);
		}
	}

	return neighbors;
}

int MapToGraphConverter::getValueFromArray(int* arr, int arrWidth, int row,
		int col) {
	return arr[(arrWidth * row) + col];
}

