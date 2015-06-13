#ifndef MAP_H_
#define MAP_H_

#include <iostream>
#include "Helper.h"
#include "MapLibraries/pngUtil.h"
#include "ConfigurationManager.h"
#include "Robot.h"

using namespace std;

class Map
{
	int _map[Helper::MAP_HEIGHT][Helper::MAP_WIDTH];
	int _blownMap[Helper::MAP_HEIGHT][Helper::MAP_WIDTH];
	string _mapPath;
	double _mapResolutionCM;
	double _gridResolutionCM;
	Robot* _robot;

	int calculateXIndex(int x);
	int calculateYIndex(int y);
	void constructBlownMap(vector<vector<int> > mapPixelGrid);

public:
	Map();
	Map(ConfigurationManager* configurationManager, Robot* robot);
	void getMapCoordinates(double realX,double realY,int &mapX,int &mapY);
	int getCellValue(int x, int y);
	void setCellValue(int x, int y, int value);
	void printMap();
	void printBlownMap();
	void reloadMapFromFile();

};

#endif /* MAP_H_ */
