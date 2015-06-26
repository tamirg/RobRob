#ifndef HELPER_H_
#define HELPER_H_
#include <vector>
#include "Location.h"
#include <math.h>

#define SCAN_SPAN  666
#define DEGREES 270


class Helper
{

public:
	static const float MINIMUM_WALL_RANGE_SIDES = 0.6;
	static const float MINIMUM_WALL_RANGE = 0.8;
	static const float TOTAL_SCAN_SPAN = SCAN_SPAN;
	static const float HALF_SCAN_SPAN = SCAN_SPAN / 2;
	static const float TOTAL_DEGREES = DEGREES;
	static const float DEGREES_INDEX_RATIO = SCAN_SPAN / DEGREES;

	static const int FREE_CELL = 0;
	static const int OCCUPIED_CELL = 1;
	static const int UNKNOWN_CELL = 2;

	static const int MAP_HEIGHT = 380;
	static const int MAP_WIDTH = 550;
	static const int MAP_RESOLUTION = 10;
	static const int BLOWN_MAP_PIXEL_RESOLUTION = 2.5;

	static int IndexToDegrees(int index);
	static int DegreesToIndex(int degrees);
	static double distanceBetweenTwoLocations(Location* firstLoc, Location* secondLoc);
};

#endif /* HELPER_H_ */
