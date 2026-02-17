#pragma once
#include <cmath>
#include "../math/Vec3.h"
#include "Particle.h"
#include <string>
#include <vector>

class PhysiscSystem{
public:
    void update(std::vector<Particle>& particles, double dt);

private:
    void applyForces(std::vector<Particle>& particles);
    void handleCollisions(std::vector<Particle>& particles); 
    void integrate(Particle& p, double dt); 
    
};
