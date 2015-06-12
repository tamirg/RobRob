#include "Map.h"
#include "MapLibraries/lodepng.h"

Map::Map() {
	for (int i = 0; i < Helper::MAP_ROWS; i++) {
		for (int j = 0; j < Helper::MAP_COLUMNS; j++) {
			_map[i][j] = Helper::UNKNOWN_CELL;
		}
	}
}

void Map::printMap() {
	cout << "Printing Map: " << endl;
	for (int i = 0; i < Helper::MAP_ROWS; i++) {
		for (int j = 0; j < Helper::MAP_COLUMNS; j++) {
			cout << _map[i][j];
		}
		cout << endl;
	}
}

int Map::calculateXIndex(int x) {
	return (x / Helper::MAP_RESOLUTION) + (Helper::MAP_COLUMNS / 2);
}

int Map::calculateYIndex(int y) {
	return (y / Helper::MAP_RESOLUTION) - (Helper::MAP_ROWS / 2);
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

/*
 * Tamir added
 *
 */
void Map::reloadMapFromFile() {
	std::vector<unsigned char> png;
	std::vector<unsigned char> image; //the raw pixels
	unsigned width, height;

	//load and decode
	lodepng::load_file(png, MAP_FILE_PATH);
	unsigned error = lodepng::decode(image, width, height, png);

	//if there's an error, display it
	if (error)
		std::cout << "decoder error " << error << ": "
				<< lodepng_error_text(error) << std::endl;
}
