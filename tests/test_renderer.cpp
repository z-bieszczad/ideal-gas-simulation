#include "render/Renderer.h"
#include "core/Particle.h"      // do tworzenia cząstek
#include "math/Vec3.h"      // do wektorów
#include <iostream>
#include "world/World.h"
#include <vector>
#include <cstdlib>
#include <ctime>

int main(int argc, char** argv) {
    srand(time(nullptr));  // losowość

    
    World world;
    world.initializeRandom(50, 5.0);

    Renderer renderer;
    renderer.initialize(1024, 768, "Ideal Gas");
    renderer.setParticles(world.getParticles());
    renderer.setBoxSize(world.getBoxSize());


    
    // ===== 4. URUCHAMIAMY =====
    glutMainLoop();
    
    return 0;
}