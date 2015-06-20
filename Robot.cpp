#include "Robot.h"

Robot::Robot(char* ip, int port, ConfigurationManager* config)
{
	_height = config -> GetRobotLength();
	_width = config -> GetRobotWidth();

	_pc = new PlayerClient(ip,port);
	_pp = new Position2dProxy(_pc);
	_lp = new LaserProxy(_pc);
	_location = new Location(config->GetStartLocationX(), config->GetStartLocationY(), config->GetStartLocationYaw());
	_pp->SetOdometry(_location->getX(), _location->getY(), _location->getYaw());

	_pp->SetMotorEnable(true);
	
	for(int i=0;i<15;i++)
		_pc->Read();
}

void Robot::read()
{
	_pc->Read();
}

void Robot::getDelta(double &dX,double &dY,double &dYaw)
{
	double xNew = _pp->GetXPos();
	double yNew = _pp->GetYPos();
	double yawNew = _pp->GetYaw();

	dX = xNew - _location->getX();
	dY = yNew - _location->getY();
	dYaw = yawNew - _location->getYaw();

	_location->setX(xNew);
	_location->setY(yNew);
	_location->setYaw(yawNew);
}

void Robot::setSpeed(float speed, float angularSpeed)
{
	_pp->SetSpeed(speed,angularSpeed);
}

float Robot::getLaserDistance(int index)
{
	return _lp->GetRange(index);
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
