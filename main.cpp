#include <iostream>
#include "Robot.h"
#include "Manager.h"
#include "MapLibraries/pngUtil.h"
#include "ConfigurationManager.h"

using namespace std;

int main(int argc, char** argv)
{
	ConfigurationManager configManager;
	Helper::setMapResolutionCM(configManager.GetMapResolutionCM());
//  Real Robot
//	Robot robot("10.10.245.64",6665, &configManager);

//  Simulator
	Robot robot("localhost",6665, &configManager);
	Map map(&configManager, &robot);

	GoToPointPlan pln(&robot);
	MapToGraphConverter mapToGraphConverter;
	PathFinder pathFinder;
	Manager manager(&robot,&pln, &map, &configManager ,&mapToGraphConverter, &pathFinder);
	manager.run();
}
