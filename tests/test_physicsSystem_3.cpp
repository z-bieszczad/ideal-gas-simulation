#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include "../core/PhysicsSystem.h"
#include "../core/Particle.h"
#include "../math/Vec3.h"


void testParticleColor() {
    
    Particle p(Vector3d(0,0,0), Vector3d(2,0,0), 1.0, 1.0); 
    PhysicsSystem system(10.0);
    std::vector<Particle> particles = {p};

   
    system.update(particles, 0.1);

    Vector3d color = particles[0].getColor();

    //  t = (2-0.5)/(3-0.5) = 0.6
    double expectedX = 0.6;
    double expectedZ = 0.4;

    assert(std::abs(color.getX() - expectedX) < 1e-9);
    assert(color.getY() == 0.0);
    assert(std::abs(color.getZ() - expectedZ) < 1e-9);

    std::cout << "Particle color gradient test passed\n";
}

int main() {
    std::cout << "=== Running Particle color test ===\n\n";

    testParticleColor();

    std::cout << "\nAll tests finished successfully!\n";
    return 0;
}
