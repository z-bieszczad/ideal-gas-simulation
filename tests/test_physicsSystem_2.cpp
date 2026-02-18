#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include "../core/PhysicsSystem.h"
#include "../core/Particle.h"
#include "../math/Vec3.h"

void testUpdateSingleParticle() {
    Particle p(Vector3d(4.9,0,0), Vector3d(1,0,0), 1.0, 1.0); 
    PhysicsSystem system(10.0);

    std::vector<Particle> particles = {p};
    double dt = 0.1;
    system.update(particles, dt);

    Particle& p2 = particles[0];

    
    assert(p2.getPosition().getX() <= 5.0);
    assert(p2.getVelocity().getX() < 0); 
    std::cout << "Update single particle (wall collision) test passed\n";
}

int main() {
    std::cout << "=== Running PhysicsSystem tests ===\n\n";

    testUpdateSingleParticle();
    

    std::cout << "\nAll PhysicsSystem tests finished successfully!\n";
    return 0;
}