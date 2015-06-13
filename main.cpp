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
	Robot robot("localhost",6665, &configManager);
	PlnObstacleAvoid pln(&robot);
	Manager m(&robot,&pln);
	m.run();
}
