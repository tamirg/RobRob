#include "LocalizationManager.h"

LocalizationManager::LocalizationManager(double x,double y)
{
	srand(time(NULL));
	InitParticles(x,y);
}

void LocalizationManager::InitParticles(double x,double y)
{
	for (int p=0; p < PARTICLES_QTY; p++)
	{
		Particle newP(x, y, 1.0);
		_particleVector.push_back(newP);
	}
}

void LocalizationManager::UpdateParticles(double deltaX, double deltaY, double deltaTetha,float laserScan[])
{
	ParticleVector::iterator pd = _particleVector.begin();
	ParticleVector::iterator pEnd = _particleVector.end();

	int counter=0;

	while(pd!=pEnd)
	{
		pd->update(deltaX,deltaY, deltaTetha,laserScan,Helper::HALF_SCAN_SPAN);

		if (pd->getBelief() < THRESHOLD && _particleVector.size()>1)
		{
			_particleVector.erase(pd);
		}
		else
		{
			counter++;
			if (counter%13==0)
			{
				Map m = pd->getMap();
				m.printMap();

				cout << endl << endl;

				counter=0;
			}

			if(_particleVector.size() < PARTICLES_QTY)
			{
				Location* pLocation = pd->getLocation();

				Particle newParticle(pLocation->getX(),pLocation->getY(), pd->getBelief());
				newParticle.setYaw(pLocation->getYaw());
				newParticle.setMap(pd->getMap());
				_particleVector.push_back(newParticle);

				delete pLocation;
			}
		}

		pd++;
	}
}

LocalizationManager::~LocalizationManager()
{
}
