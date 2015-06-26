#include "Helper.h"

int Helper::DegreesToIndex(int degrees) {
	int indexDifference = degrees * Helper::DEGREES_INDEX_RATIO;
	return Helper::HALF_SCAN_SPAN + indexDifference;
}

int Helper::IndexToDegrees(int index) {
	int relativeIndex = index - Helper::HALF_SCAN_SPAN;
	return relativeIndex / Helper::DEGREES_INDEX_RATIO;
}

double Helper::distanceBetweenTwoLocations(Location* firstLoc, Location* secondLoc) {
	return sqrt(
			pow((firstLoc->getX() - secondLoc->getX()), 2.0)
					+ pow((firstLoc->getY() - secondLoc->getY()), 2.0));
}

