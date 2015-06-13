

#include "Particle.h"

Particle::Particle(double x,double y, double belief)
{
	Location* _location = new Location();
	_location->setX((double)rand()/((double)RAND_MAX/30) - PARTICLE_CLOUD_RADIUS + x);
	_location->setY((double)rand()/((double)RAND_MAX/30) - PARTICLE_CLOUD_RADIUS + y);
	_location->setYaw(DTOR(rand() % 360));
	_belief = belief;

	int mapX,mapY;

	_map->getMapCoordinates(_location->getX(),_location->getY(),mapX,mapY);
	for (int i=-ROBOT_DIMENTION_ON_MAP; i<ROBOT_DIMENTION_ON_MAP; i++)
		for (int j=-ROBOT_DIMENTION_ON_MAP; j<ROBOT_DIMENTION_ON_MAP; j++)
			_map->setCellValue(mapX+i, mapY+j, Helper::FREE_CELL);
}

void Particle::update(double deltaX, double deltaY, double deltaYaw, float laserScan[], int laserCount)
{
	_location.setX(_location.getX()+M_TO_CM(deltaX));
	_location.setY(_location.getY()+M_TO_CM(deltaY));
	_location.setYaw(_location.getYaw()+deltaYaw);

	double predictionBelief = _belief * probByMov(deltaX, deltaY, deltaYaw);
	_belief =  predictionBelief * probByMeasurement(laserScan,laserCount);
}

double Particle::probByMeasurement(float laserScan[], int laserCount)
{
	int countMiss = 0;
	int countHit = 0;
	double objectX,objectY;
	int objectXOnMap,objectYOnMap;

	for (int i=0; i<laserCount; i = i+INDEX_PER_DEGREE)
	{
			if (laserScan[i] > OPEN_PATH_RANGE)
			{
				for (int j=SENSOR_FROM_END; j<=SENSOR_DETECTION_RANGE; j = j+ Helper::MAP_RESOLUTION)
				{
					objectX = (j * cos(DTOR(convertIndexToAngle(i,laserCount,LASER_ANGLE_RANGE)) + _location.getYaw())) + _location.getX();
					objectY = (j * sin(DTOR(convertIndexToAngle(i,laserCount,LASER_ANGLE_RANGE)) + _location.getYaw())) + _location.getY();
					_map->getMapCoordinates(objectX,objectY,objectXOnMap,objectYOnMap);

					if (_map->getCellValue(objectXOnMap,objectYOnMap) == Helper::UNKNOWN_CELL)
					{
						_map->setCellValue(objectXOnMap,objectYOnMap, Helper::FREE_CELL);
						countHit++;
					}
					else if(_map->getCellValue(objectXOnMap,objectYOnMap) == Helper::OCCUPIED_CELL)
					{
						_map->setCellValue(objectXOnMap,objectYOnMap, Helper::FREE_CELL);
						countMiss++;
					}
					else if(_map->getCellValue(objectXOnMap,objectYOnMap) == Helper::FREE_CELL)
					{
						countHit++;
					}
				}
			}
			else
			{
				objectX = ((M_TO_CM(laserScan[i])) * cos(DTOR(convertIndexToAngle(i,laserCount,LASER_ANGLE_RANGE)) + _location.getYaw())) + _location.getX();
				objectY = ((M_TO_CM(laserScan[i])) * sin(DTOR(convertIndexToAngle(i,laserCount,LASER_ANGLE_RANGE)) + _location.getYaw())) + _location.getY();
				_map->getMapCoordinates(objectX,objectY,objectXOnMap,objectYOnMap);

				if (_map->getCellValue(objectXOnMap,objectYOnMap) == Helper::UNKNOWN_CELL)
				{
					_map->setCellValue(objectXOnMap,objectYOnMap, Helper::OCCUPIED_CELL);
					countHit++;
				}
				else if (_map->getCellValue(objectXOnMap,objectYOnMap) == Helper::OCCUPIED_CELL)
				{
					countHit++;
				}
				else if(_map->getCellValue(objectXOnMap,objectYOnMap) == Helper::FREE_CELL)
				{
					_map->setCellValue(objectXOnMap,objectYOnMap, Helper::OCCUPIED_CELL);
					countMiss++;
				}
			}
		}


	_map->printMap();
	return ((float)(countHit))/(countMiss + countHit);
}

double Particle::probByMov(double deltaX, double deltaY, double deltaYaw)
{
	double distance = sqrt(pow(deltaX,2)+pow(deltaY,2));

	if ((deltaYaw <= NORMAL_ACCURATE_ANGLE_TO_MOVE) && (deltaYaw >= -NORMAL_ACCURATE_ANGLE_TO_MOVE))
	{
		if (distance <= SAFE_DISTANCE_TO_MOVE)
			return 1.0;
		else
			return (SAFE_DISTANCE_TO_MOVE + distance + 0.2);
	}
	else if ((deltaYaw < MAX_ACCURATE_ANGLE_TO_MOVE) && (deltaYaw > -MAX_ACCURATE_ANGLE_TO_MOVE))
	{
		if (distance <= SAFE_DISTANCE_TO_MOVE)
			return 1.0;
		else
			return (SAFE_DISTANCE_TO_MOVE + distance - 0.2);
	}
	else
		return 1.0;
}

void Particle::setMap(Map* map)
{
	_map = map;
}

Map* Particle::getMap()
{
	return _map;
}

double Particle::getBelief()
{
	return _belief;
}

double Particle::convertIndexToAngle(int i, int x, int r)
{
	return ((double)i*((double)r/x))-r/2.0;
}

void Particle::printMap()
{
	_map->printMap();
}

void Particle::setYaw(double yaw)
{
	_location.setYaw(yaw);
}

Location* Particle::getLocation()
{
	return new Location(_location.getX(),_location.getY(),_location.getYaw());
}

Particle::~Particle()
{
}
