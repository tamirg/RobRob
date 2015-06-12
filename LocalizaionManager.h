#ifndef SLAMMANAGER_H_
#define SLAMMANAGER_H_

#include <vector>
#include <libplayerc++/playerc++.h>

#include "Particle.h"

#define PARTICLES_QTY 100
#define THRESHOLD 0.6
typedef vector <Particle> ParticleVector;

class LocalizaionManager
{

private:
	ParticleVector _particleVector;

public:
	LocalizaionManager(double x,double y);
	void InitParticles(double x,double y);
	void UpdateParticles(double delX, double delY, double delTetha,float laserScan[]);
	virtual ~LocalizaionManager();
};

#endif /* LocalizaionManager */
