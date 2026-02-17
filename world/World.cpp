#include "World.h"
#include <iostream>
#include <cmath>


World::World() : boxSize(10.0f) {
    velocityHistogram.resize(20, 0);
}

void World::initializeRandom(int numParticles, double maxSpeed) {
    particles.clear();

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

        particles.push_back(p);
    }

    calculateStatistics();

    std::cout << "World create " << particles.size() << " particles" << std::endl;
}

void World::calculateStatistics() {
    totalEnergy = 0;
    temperature = 0;
    pressure = 0;

    std::fill(velocityHistogram.begin(), velocityHistogram.end(), 0);

    for (const auto& p : particles) {
        Vector3d vel = p.getVelocity();
        double speed = vel.magnitude();

        totalEnergy += 0.5 * speed * speed;

        int bin = static_cast<int>(speed * 2);
        if (bin >= 0 && bin < velocityHistogram.size()) {
            velocityHistogram[bin]++;
        }
    }

    if (!particles.empty()) {
        temperature = (2.0/3.0) * totalEnergy / particles.size();
    }

    double volume = boxSize * boxSize * boxSize;
    pressure = particles.size() * temperature / volume;
}

void World::update() {
    calculateStatistics();
}