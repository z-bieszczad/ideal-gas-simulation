#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include "../core/PhysicsSystem.h"
#include "../core/Particle.h"
#include "../math/Vec3.h"

void testUpdateTwoParticlesCollision() {
    Particle p1(Vector3d(-1,0,0), Vector3d(1,0,0), 1.0, 1.0);
    Particle p2(Vector3d(1,0,0), Vector3d(-1,0,0), 1.0, 1.0);

    PhysicsSystem system(10.0);
    std::vector<Particle> particles = {p1, p2};

    // energia kinetyczna przed update
    auto KE = [](const Particle& a, const Particle& b) {
        double v1sq = a.getVelocity().getX()*a.getVelocity().getX() +
                      a.getVelocity().getY()*a.getVelocity().getY() +
                      a.getVelocity().getZ()*a.getVelocity().getZ();
        double v2sq = b.getVelocity().getX()*b.getVelocity().getX() +
                      b.getVelocity().getY()*b.getVelocity().getY() +
                      b.getVelocity().getZ()*b.getVelocity().getZ();
        return 0.5 * a.getMass() * v1sq + 0.5 * b.getMass() * v2sq;
    };

    double KE_before = KE(p1, p2);

    system.update(particles, 0.1);

    double KE_after = KE(particles[0], particles[1]);

    assert(std::abs(KE_before - KE_after) < 1e-9);
    std::cout << "Update two particles (energy conservation) test passed\n";
}

int main() {
    std::cout << "=== Running PhysicsSystem test ===\n\n";
    testUpdateTwoParticlesCollision();
    std::cout << "\nAll tests finished successfully!\n";
    return 0;
}