#include "Robot.h"

Robot::Robot(char* ip, int port, ConfigurationManager* config)
{
	_height = config -> GetRobotLength();
	_width = config -> GetRobotWidth();

	_pc = new PlayerClient(ip,port);
	_pp = new Position2dProxy(_pc);
	_lp = new LaserProxy(_pc);

	_location = new Location(config->GetStartLocationX(), config->GetStartLocationY(), config->GetStartLocationYaw());

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
	dX = _pp->GetXPos() - _location->getX();
	dY = _pp->GetYPos() - _location->getY();
	dYaw = _pp->GetYaw() - _location->getYaw();

	_location->setX(dX);
	_location->setY(dY);
	_location->setYaw(dYaw);
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
