#ifndef ROBOT_H_
#define ROBOT_H_

#include <libplayerc++/playerc++.h>
#include "Location.h"
#include "ConfigurationManager.h"

using namespace PlayerCc;

class Robot
{
private:
	double _height;
	double _width;
	PlayerClient* _pc;
	Position2dProxy* _pp;
	LaserProxy* _lp;
public:
	// This location is in meters
	Location* _location;
	Robot(char* ip, int port, ConfigurationManager* config);
	void read();
	void setSpeed(float speed, float angularSpeed);
	void getDelta(double &dX,double &dY,double &dYaw);
	double getLaserDistance(int index);
	Location* getCurrLocation();
	double getWidth();
	double getHeight();
	virtual ~Robot();
};

#endif /* ROBOT_H_ */
