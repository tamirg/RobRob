#include <iostream>
#include "Manager.h"
#include "Robot.h"
#include "Plans/PlnObstacleAvoid.h"
#include "MapLibraries/pngUtil.h"
#include "ConfigurationManager.h"

using namespace std;

int main(int argc, char** argv)
{
	ConfigurationManager configManager;
//  Real Robot
	Robot robot("10.10.245.64",6665, &configManager);

//  Simulator
//	Robot robot("localhost",6665, &configManager);
	Map map(&configManager, &robot);
	PlnObstacleAvoid pln(&robot);
	MapToGraphConverter mapToGraphConverter();
	PathFinder pathFinder();
	Manager manager(&robot,&pln, &map, &mapToGraphConverter, &pathFinder);
	manager.run();
}
