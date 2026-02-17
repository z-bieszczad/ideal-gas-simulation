#include "render/Renderer.h"
#include "core/Particle.h"      
#include "math/Vec3.h"
#include "world/World.h"      
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main(int argc, char** argv) {
    srand(time(nullptr));

    World world;
    world.initializeRandom(100, 5.0);

    Renderer renderer;
    if (!renderer.initialize(1024, 768, "Ideal Gas Simulation 3D")) {
        return 1;
    }

    renderer.setWorld(&world);

    std::cout << "=== SIMULATION ===\n";
    std::cout << "Particles: " << world.getParticles().size() << std::endl;
    std::cout << "Temperature: " << world.getTemperature() << std::endl;
    std::cout << "Pressure: " << world.getPressure() << std::endl; 
    
   
    glutMainLoop(); 
    return 0;
}