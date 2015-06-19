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
	int _blownMapWidth;
	int _blownMapHeight;
	int _navMapWidth;
	int _navMapHeight;
	int* _navMap;
	int* _blownMap;
	string _mapPath;
	double _mapResolutionCM;
	double _gridResolutionCM;
	Robot* _robot;

public:
	Map(ConfigurationManager* configurationManager, Robot* robot);
	virtual ~Map();
	void getMapCoordinates(double realX,double realY,int &mapX,int &mapY);
	int getNavMapCellValue(int x, int y);
	void setNavMapCellValue(int x, int y, int value);
	void printMap();
	void printBlownMap();
	int calculateXIndex(int x);
	int calculateYIndex(int y);
	void constructBlownMap(vector<vector<int> > mapPixelGrid);
	void constructNavMap(vector<vector<int> > mapPixelGrid);
	int* getBlownMap();
	int getBlownMapWidth();
	int getBlownMapHeight();
	int getNavMapWidth();
	int getNavMapHeight();
private:
	int innerGridScanForObstacles(int row, int col, vector<vector<int> > mapPixelGrid);
	void reloadMapFromFile();
};

#endif /* MAP_H_ */
