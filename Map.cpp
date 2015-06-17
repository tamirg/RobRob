#include "Map.h"
#include "MapLibraries/lodepng.h"

Map::Map(ConfigurationManager* configurationManager, Robot* robot) {
	_mapPath = configurationManager->GetMapPath();
	_mapResolutionCM = configurationManager->GetMapResolutionCM();
	_gridResolutionCM = configurationManager->GetGridResolutionCM();
	_robot = robot;

	reloadMapFromFile();
}

void Map::printMap() {
	cout << "Printing Map: " << endl;
	for (int i = 0; i < Helper::MAP_HEIGHT; i++) {
		for (int j = 0; j < Helper::MAP_WIDTH; j++) {
			cout << _map[i][j];
		}
		cout << endl;
	}
}

void Map::printBlownMap() {
	cout << "Printing Blown Map: " << endl;
	for (int i = 0; i < Helper::MAP_HEIGHT; i++) {
		for (int j = 0; j < Helper::MAP_WIDTH; j++) {
			cout << _blownMap[i][j];
		}
		cout << endl;
	}
}

int Map::calculateXIndex(int x) {
	return (x / Helper::MAP_RESOLUTION) + (Helper::MAP_WIDTH / 2);
}

int Map::calculateYIndex(int y) {
	return (y / Helper::MAP_RESOLUTION) - (Helper::MAP_HEIGHT / 2);
}

void Map::getMapCoordinates(double realX, double realY, int &mapX, int &mapY) {
	mapX = calculateXIndex(realX);
	mapY = calculateYIndex(realY);
}

void Map::setCellValue(int x, int y, int value) {
	int xIndex = calculateXIndex(x);
	int yIndex = calculateYIndex(y);
	_map[xIndex][yIndex] = value;
}

int Map::getCellValue(int x, int y) {
	int xIndex = calculateXIndex(x);
	int yIndex = calculateYIndex(y);
	return _map[xIndex][yIndex];
}

void Map::constructBlownMap(vector<vector<int> > mapPixelGrid) {
	for (int row = 0; row < Helper::MAP_HEIGHT; row++) {
		for (int column = 0; column < Helper::MAP_WIDTH; column++) {
			if (mapPixelGrid[row][column] == Helper::FREE_CELL) {
				_blownMap[row][column] = Helper::FREE_CELL;
				_map[row][column] = Helper::FREE_CELL;
			} else {
				_map[row][column] = Helper::OCCUPIED_CELL;
				for (int i = 1;
						i <= (_robot->getWidth() / 2) / _mapResolutionCM; i++) {
					if (column + i <= Helper::MAP_WIDTH) {
						_blownMap[row][column + i] = Helper::OCCUPIED_CELL;
					}
					if (column - i >= 0) {
						_blownMap[row][column - i] = Helper::OCCUPIED_CELL;
					}
					if (row + i <= Helper::MAP_HEIGHT) {
						_blownMap[row + i][column] = Helper::OCCUPIED_CELL;
					}
					if (row - i >= 0) {
						_blownMap[row - i][column] = Helper::OCCUPIED_CELL;
					}
				}
			}
		}
	}
}

void Map::reloadMapFromFile() {
	vector<vector<int> > mapPixelGrid = convertPngToPixels(MAP_FILE_PATH);
	constructBlownMap(mapPixelGrid);
}
