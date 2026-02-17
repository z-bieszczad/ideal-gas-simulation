#pragma once
#include <vector>
#include "../core/Particle.h"
#include "../math/Vec3.h"

class World {
    private:
        std::vector<Particle> _particles;
        float _boxSize;

        double _totalEnergy;
        double _temperature;
        double _pressure;
        std::vector<int> _velocityHistogram;
    
    public:
        World();

        void initializeRandom(int numParticles, double maxSpeed);

        const std::vector<Particle>& getParticles() const {
            return _particles;
        }
        float getBoxSize() const { return _boxSize; }

        void calculateStatistics();
        double getTemperature() const { return _temperature; }
        double getPressure() const { return _pressure; }
        double getTotalEnergy() const { return _totalEnergy; }
        const std::vector<int>& getHistogram() const { return _velocityHistogram; }


        void update(double dt);

};