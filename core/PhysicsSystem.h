#pragma once
#include <cmath>
#include "../math/Vec3.h"
#include "Particle.h"
#include <string>
#include <vector>

class PhysicsSystemTest;

class PhysicsSystem{
public:
    PhysicsSystem(double boxSize);
    void update(std::vector<Particle>& particles, double dt);
    friend class PhysicsSystemTest;
private:
    void applyForces(std::vector<Particle>& particles);
    void handleParticleCollisions(std::vector<Particle>& particles);
    void handleWallCollisions(std::vector<Particle>& particles);
    void integrate(Particle& p, double dt);
    void updateColorFromVelocity(Particle& particle);

    double _halfSize;

};
