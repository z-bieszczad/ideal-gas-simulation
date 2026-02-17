#pragma once
#include <vector>
#include "../core/Particle.h"
#include "../math/Vec3.h"

class World {
    private:
        std::vector<Particle> particles;
        float boxSize;

        double totalEnergy;
        double temperature;
        double pressure;
        std::vector<int> velocityHistogram;
    
    public:
        World();

        void initializeRandom(int numParticles, double maxSpeed);

        const std::vector<Particle>& getParticles() const {
            return particles;
        }
        float getBoxSize() const { return boxSize; }

        void calculateStatistics();
        double getTemperature() const { return temperature; }
        double getPressure() const { return pressure; }
        double getTotalEnergy() const { return totalEnergy; }
        const std::vector<int>& getHistogram() const { return velocityHistogram; }


        void update();

};