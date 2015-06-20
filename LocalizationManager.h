#ifndef LOCALIZATIONMANAGER_H_
#define LOCALIZATIONMANAGER_H_

#include <vector>
#include <libplayerc++/playerc++.h>

#include "Particle.h"

#define PARTICLES_QTY 100
#define THRESHOLD 0.6
typedef vector <Particle> ParticleVector;

class LocalizationManager
{

private:
	ParticleVector _particleVector;

public:
	LocalizationManager(double x,double y, Map* map);
	void InitParticles(double x,double y, Map* map);
	void UpdateParticles(double delX, double delY, double delTetha,float laserScan[]);
	virtual ~LocalizationManager();
};

#endif /* LocalizationManager */
