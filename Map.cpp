#include "Map.h"
#include "MapLibraries/lodepng.h"
#include <math.h>

Map::Map(ConfigurationManager* configurationManager, Robot* robot) {
	_mapPath = configurationManager->GetMapPath();
	_mapResolutionCM = configurationManager->GetMapResolutionCM();
	_gridResolutionCM = configurationManager->GetGridResolutionCM();
	_robot = robot;

	reloadMapFromFile();
}

Map::~Map() {
	delete[] _blownMap;
	delete[] _navMap;
}

void Map::printMap() {
	cout << "Printing Map: " << endl;
	for (int i = 0; i < _blownMapHeight; i++) {
		for (int j = 0; j < _blownMapWidth; j++) {
			cout << _navMap[i * _navMapWidth + j];
		}
		cout << endl;
	}
}

void Map::printBlownMap() {
	cout << "Printing Blown Map: " << endl;
	for (int i = 0; i < _blownMapHeight; i++) {
		for (int j = 0; j < _blownMapWidth; j++) {
			cout << _blownMap[i * _blownMapWidth + j];
		}
		cout << endl;
	}
}

int Map::calculateXIndex(int x) {
	return (x / _mapResolutionCM);
}

int Map::calculateYIndex(int y) {
	return (y / _mapResolutionCM);
}

void Map::getNavMapCoordinates(double realX, double realY, int &mapX, int &mapY) {
	mapX = calculateXIndex(realX);
	mapY = calculateYIndex(realY);
}

void Map::setNavMapCellValue(int x, int y, int value) {
	int xIndex = calculateXIndex(x);
	int yIndex = calculateYIndex(y);
	_navMap[yIndex * _navMapWidth + xIndex] = value;
}

int Map::getNavMapCellValue(int x, int y) {
	int xIndex = calculateXIndex(x);
	int yIndex = calculateYIndex(y);
	return _navMap[yIndex * _navMapWidth + xIndex];
}

void Map::constructBlownMap(vector<vector<int> > mapPixelGrid) {
	for (int row = 0; row < _blownMapHeight; row++) {
		for (int column = 0; column < _blownMapWidth; column++) {
			if (mapPixelGrid[row][column] == Helper::FREE_CELL) {
				_blownMap[row * _blownMapWidth + column] = Helper::FREE_CELL;
			} else {
				for (int i = 1;i <= (_robot->getWidth() / 2) / _mapResolutionCM; i++) {
					if (column + i <= _blownMapWidth) {
						_blownMap[row * _blownMapWidth + column + i] = Helper::OCCUPIED_CELL;
					}
					if (column - i >= 0) {
						_blownMap[row * _blownMapWidth + column - i] = Helper::OCCUPIED_CELL;
					}
					if (row + i <= _blownMapHeight) {
						_blownMap[(row + i) * _blownMapWidth + column] = Helper::OCCUPIED_CELL;
					}
					if (row - i >= 0) {
						_blownMap[(row - i) * _blownMapWidth + column] = Helper::OCCUPIED_CELL;
					}
				}
			}
		}
	}
}

void Map::constructNavMap(vector<vector<int> > mapPixelGrid) {
	for (int row = 0; row < _blownMapHeight; row+=4) {
		for (int column = 0; column < _blownMapWidth; column+=4) {
			_navMap[(row / 4) * _navMapWidth + (column / 4)] =
					innerGridScanForObstacles(row, column, mapPixelGrid);
		}
	}
}

int Map::innerGridScanForObstacles(int row, int col, vector<vector<int> > mapPixelGrid) {
	for (int i=row; i < row + 4 && row < _blownMapHeight; i++ ) {
		for (int j=col; j < col + 4 && col < _blownMapWidth; j++ ) {
			if (mapPixelGrid[i][j] == Helper::OCCUPIED_CELL) {
				return Helper::OCCUPIED_CELL;
			}
		}
	}
	return Helper::FREE_CELL;
}


void Map::reloadMapFromFile() {
	vector<vector<int> > mapPixelGrid = convertPngToPixels(_mapPath.c_str());

	_blownMapWidth = mapPixelGrid[0].size();
	_blownMapHeight = mapPixelGrid.size();

	_blownMap = new int[_blownMapHeight * _blownMapWidth];

	_navMapWidth = ceil((double)_blownMapWidth / 4.0);
	_navMapHeight = ceil((double)_blownMapHeight / 4.0);

	_navMap = new int[_navMapHeight * _navMapWidth];

	constructBlownMap(mapPixelGrid);
}

int* Map::getBlownMap() {
	return this->_blownMap;
}

int Map::getBlownMapWidth() {
	return this->_blownMapWidth;
}

int Map::getBlownMapHeight() {
	return this->_blownMapHeight;
}

int Map::getNavMapWidth() {
	return this->_navMapWidth;
}

int Map::getNavMapHeight() {
	return this->_navMapHeight;
}
