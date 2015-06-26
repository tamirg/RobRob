#ifndef PARTICLE_H_
#define PARTICLE_H_
#include "Location.h"
#include "Map.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <time.h>

#define MAX_ACCURATE_ANGLE_TO_MOVE 1.0
#define NORMAL_ACCURATE_ANGLE_TO_MOVE 0.5
#define SAFE_DISTANCE_TO_MOVE 0.3
#define NORMALIZEDFACTOR 2
#define LASER_MAX_RANGE 4
#define LASER_ANGLE_RANGE 240
#define OPEN_PATH_RANGE 0.75
#define RTOD(r) ((r) * 180 / M_PI)
#define DTOR(d) ((d) * M_PI / 180)
#define NORMALIZE(z) atan2(sin(z), cos(z))
#define M_TO_CM(m) (m * 100)
#define CM_TO_M(m) (m / 100)
#define ROBOT_DIMENTION_ON_MAP 3
#define SENSOR_FROM_END 15
#define SENSOR_DETECTION_RANGE 60
#define PARTICLE_CLOUD_RADIUS 15
#define INDEX_PER_DEGREE 6

class Particle
{

private:
	Location _location;
	Map* _map;
	double _belief;

public:
	Particle(double x, double y, Map* map);
	void update(double deltaX, double deltaY, double deltaYaw, float laserScan[], int laserCount);
	double probByMov(double deltaX, double deltaY, double deltaYaw);
	double probByMeasurement(float laserScan[], int laserCount);
	void setMap(Map* map);
	Map* getMap();
	double getBelief();
	double getX();
	double getY();
	double getYaw();
	double convertIndexToAngle(int i, int x, int r);
	void printMap();
	void setYaw(double yaw);
	Location* getLocation();
	~Particle();
};

#endif /* PARTICLE_H_ */
