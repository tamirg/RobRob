#include "Helper.h"
#include "Particle.h"

static double MAP_RESOLUTION_CM = -1;

void Helper::setMapResolutionCM(double res) {
	MAP_RESOLUTION_CM = res;
}

double Helper::getMapResolutionCM() {
	return MAP_RESOLUTION_CM;
}

int Helper::DegreesToIndex(int degrees) {
	int indexDifference = degrees * Helper::DEGREES_INDEX_RATIO;
	return Helper::HALF_SCAN_SPAN + indexDifference;
}

int Helper::IndexToDegrees(int index) {
	int relativeIndex = index - Helper::HALF_SCAN_SPAN;
	return relativeIndex / Helper::DEGREES_INDEX_RATIO;
}

double Helper::distanceBetweenTwoLocations(Location* firstLoc,
		Location* secondLoc) {
	return sqrt(
			pow((firstLoc->getX() - secondLoc->getX()), 2.0)
					+ pow((firstLoc->getY() - secondLoc->getY()), 2.0));
}

Location Helper::MapCellToMetersLocation(int x, int y) {
	Location metersLocation(CM_TO_M(x * MAP_RESOLUTION_CM),
			CM_TO_M(y * MAP_RESOLUTION_CM), 0);
	return metersLocation;
}
