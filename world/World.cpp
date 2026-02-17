#include "World.h"
#include <iostream>
#include <cmath>


World::World() : _boxSize(10.0f) {
    _velocityHistogram.resize(20, 0);
}

void World::initializeRandom(int numParticles, double maxSpeed) {
    _particles.clear();

    for (int i = 0; i < numParticles; i++) {
        double x = (rand() % 1000 - 500) / 100.0;
        double y = (rand() % 1000 - 500) / 100.0;
        double z = (rand() % 1000 - 500) / 100.0;

        double theta = (rand() % 628) / 100.0;
        double phi = (rand() % 314) / 100.0;
        double v = (rand() % 1000) / 1000.0 * maxSpeed;

        double vx = v * sin(phi) * cos(theta);
        double vy = v * sin(phi) * sin(theta);
        double vz = v*cos(phi);

        Vector3d position(x, y, z);
        Vector3d velocity(vx, vy, vz);

        Particle p(position, velocity, 1.0, 0.2);

        _particles.push_back(p);
    }

    calculateStatistics();

    std::cout << "World create " << _particles.size() << " particles" << std::endl;
}

void World::calculateStatistics() {
    _totalEnergy = 0;
    _temperature = 0;
    _pressure = 0;

    std::fill(_velocityHistogram.begin(), _velocityHistogram.end(), 0);

    for (const auto& p : _particles) {
        Vector3d vel = p.getVelocity();
        double mass = p.getMass();
        double speed = vel.magnitude();

        _totalEnergy += 0.5 * mass * speed * speed;

        int bin = static_cast<int>(speed * 2);
        if (bin >= 0 && bin < _velocityHistogram.size()) {
            _velocityHistogram[bin]++;
        }
    }

    if (!_particles.empty()) {
        _temperature = (2.0/3.0) * _totalEnergy / _particles.size();
    }

    double volume = _boxSize * _boxSize * _boxSize;
    _pressure = _particles.size() * _temperature / volume;
}

void World::update(double dt) {
    
    calculateStatistics();

    
}