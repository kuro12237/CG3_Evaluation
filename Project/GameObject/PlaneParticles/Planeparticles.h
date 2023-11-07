#pragma once
#include"Particle/Particle.h"

class PlaneParticles
{
public:
	PlaneParticles() {};
	~PlaneParticles() {};

	void Initialize();

	void Update();

	void Draw(ViewProjection view);

private:

	unique_ptr<Particle>particle_ = nullptr;
	uint32_t texHandle_ = 0;
	list<Particle_param>particles_{};
};

