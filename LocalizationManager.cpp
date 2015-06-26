#include "LocalizationManager.h"

LocalizationManager::LocalizationManager(double x, double y, Map* map) {
	srand(time(NULL));
	InitParticles(x, y, map);
}

void LocalizationManager::InitParticles(double x, double y, Map* map) {
	for (int p = 0; p < PARTICLES_QTY; p++) {
		Particle newP(x, y, map);
		_particleVector.push_back(newP);
	}
}

void LocalizationManager::UpdateParticles(double deltaX, double deltaY,
		double deltaTetha, float laserScan[]) {
	ParticleVector::iterator pd = _particleVector.begin();
	ParticleVector::iterator pEnd = _particleVector.end();

	int counter = 0;

	while (pd != pEnd) {
		pd->update(deltaX, deltaY, deltaTetha, laserScan,
				Helper::HALF_SCAN_SPAN);

		if (pd->getBelief() < THRESHOLD && _particleVector.size() > 1) {
			_particleVector.erase(pd);
		} else {
			counter++;
			if (counter % 13 == 0) {
				Map* m = pd->getMap();
//				m->printMap();
				cout << endl << endl;
				counter = 0;
			}

			if (_particleVector.size() < PARTICLES_QTY) {
				Location* pLocation = pd->getLocation();

				Particle newParticle(pLocation->getX(), pLocation->getY(),
						pd->getMap());
				newParticle.setYaw(pLocation->getYaw());
				newParticle.setMap(pd->getMap());
				_particleVector.push_back(newParticle);

				delete pLocation;
			}
		}

		pd++;
	}
}

Location* LocalizationManager::CalcRobotLocation()
{
	double particleXSum = 0;
	double particleYSum = 0;
	double particleYawSum = 0;
	double totalBelief = 0;

	for (int i = 0; i < _particleVector.size(); i++)
	{
		double curBelief = _particleVector[i].getBelief();

		particleXSum += curBelief * _particleVector[i].getX();
		particleYSum += curBelief * _particleVector[i].getY();
		particleYawSum += curBelief * _particleVector[i].getYaw();
		totalBelief += curBelief;
	}

	double robotX = particleXSum / totalBelief;
	double robotY = particleYSum / totalBelief;
	double robotYaw = particleYawSum / totalBelief;

	return new Location(robotX, robotY, robotYaw);
}

LocalizationManager::~LocalizationManager() {
}
