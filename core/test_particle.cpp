#include <iostream>
#include "Particle.h"
#include "../math/Vec3.h"

int main() {
    // creating minimal particle
    Vector3d pos(1.0, 2.0, 3.0);
    Vector3d vel(0.5, 0.0, -0.5);
    double mass = 2.0;
    double radius = 1.0;

    Particle p(pos, vel, mass, radius);

    //  getters
    std::cout << "position: " 
              << p.getPosition().getX() << ", "
              << p.getPosition().getY() << ", "
              << p.getPosition().getZ() << "\n";

    std::cout << "velocity: "
              << p.getVelocity().getX() << ", "
              << p.getVelocity().getY() << ", "
              << p.getVelocity().getZ() << "\n";

    std::cout << "mass: " << p.getMass() << "\n";
    std::cout << "radius: " << p.getRadius() << "\n";

    //  setters
    p.setPosition(Vector3d(10, 10, 10));
    p.setVelocity(Vector3d(1, 1, 1));

    std::cout << "new position: "
              << p.getPosition().getX() << ", "
              << p.getPosition().getY() << ", "
              << p.getPosition().getZ() << "\n";

    std::cout << "new velocity: "
              << p.getVelocity().getX() << ", "
              << p.getVelocity().getY() << ", "
              << p.getVelocity().getZ() << "\n";

    //  Test applyForce
    Vector3d force(0.5, 0.0, 0.0);
    p.applyForce(force);

    std::cout << "force after applyForce: "
              << p.getForce().getX() << ", "
              << p.getForce().getY() << ", "
              << p.getForce().getZ() << "\n";

    // Test resetForces
    p.resetForces();
    std::cout << "force after resetForces: "
              << p.getForce().getX() << ", "
              << p.getForce().getY() << ", "
              << p.getForce().getZ() << "\n";

    return 0;
}
