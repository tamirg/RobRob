#include <iostream>
#include "Manager.h"
#include "Robot.h"
#include "Plans/PlnObstacleAvoid.h"
#include "MapLibraries/pngUtil.h"
#include "ConfigurationManager.h"

using namespace std;

int main(int argc, char** argv)
{
	ConfigurationManager *cnfgmgrKaki = new ConfigurationManager();
	Robot robot("localhost",6665);
	PlnObstacleAvoid pln(&robot);
	Manager m(&robot,&pln);
	m.run();

}
