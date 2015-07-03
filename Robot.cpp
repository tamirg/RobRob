#include "Robot.h"
#include "Helper.h"

Robot::Robot(char* ip, int port, ConfigurationManager* config)
{
	_height = config -> GetRobotLength();
	_width = config -> GetRobotWidth();

	_pc = new PlayerClient(ip,port);
	_pp = new Position2dProxy(_pc);
	_lp = new LaserProxy(_pc);

	Location startLoc = Helper::MapCellToMetersLocation(config->GetStartLocationX(), config->GetStartLocationY());
	_location = new Location(startLoc.getX(), startLoc.getY(), DTOR(config->GetStartLocationYaw()));
	_prevRobotLoc = new Location(_location->getX(), _location->getY(), _location->getYaw());
	_pp->SetOdometry(_location->getX(), _location->getY(), _location->getYaw());

	_pp->SetMotorEnable(true);
	
	for(int i=0;i<15;i++)
		_pc->Read();
}

void Robot::read()
{
	_pc->Read();
}

// Gets the robot location delta in meters
void Robot::getDelta(double &dX,double &dY,double &dYaw)
{
	double xNew = _pp->GetXPos();
	double yNew = _pp->GetYPos();
	double yawNew = _pp->GetYaw();

	dX = xNew - _prevRobotLoc->getX();
	dY = yNew - _prevRobotLoc->getY();
	dYaw = yawNew - _prevRobotLoc->getYaw();

	// Saves the robot's last location. The robots [0,0] is the map center
	_prevRobotLoc->setX(xNew);
	_prevRobotLoc->setY(yNew);
	_prevRobotLoc->setYaw(yawNew);

	// Sets our location. [0,0] is top left
	_location->setX(xNew);
	_location->setY(_location->getY() - dY);
	_location->setYaw(yawNew);
}

void Robot::setSpeed(float speed, float angularSpeed)
{
	_pp->SetSpeed(speed,angularSpeed);
}

double Robot::getLaserDistance(int index)
{
	return _lp->GetRange(index);
	//return _lp->GetRange((uint)index);
}

Location* Robot::getCurrLocation() {
	return new Location(_location->getX(), _location->getY(), _location->getYaw());
}

double Robot::getWidth()
{
	return _width;
}

double Robot::getHeight()
{
	return _height;
}

Robot::~Robot()
{
	delete _location;
	delete _lp;
	delete _pp;
	delete _pc;
}
