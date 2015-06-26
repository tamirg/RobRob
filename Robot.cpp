#include "Robot.h"

Robot::Robot(char* ip, int port, ConfigurationManager* config)
{
	_height = config -> GetRobotLength();
	_width = config -> GetRobotWidth();

	_pc = new PlayerClient(ip,port);
	_pp = new Position2dProxy(_pc);
	_lp = new LaserProxy(_pc);
	double matrixToMeterRatio = config->GetMapResolutionCM() / 100;
	_location = new Location(config->GetStartLocationX() * matrixToMeterRatio, config->GetStartLocationY() * matrixToMeterRatio, config->GetStartLocationYaw());
	_pp->SetOdometry(_location->getX(), _location->getY(), DTOR(_location->getYaw()));

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

	dX = xNew - _location->getX();
	dY = yNew - _location->getY();
	dYaw = yawNew - _location->getYaw();
	//cout<< xNew << " " << yNew << " " << yawNew << endl;

	_location->setX(xNew);
	_location->setY(yNew);
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
	return new Location(_pp->GetXPos(), _pp->GetYPos(), _pp->GetYaw());
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
