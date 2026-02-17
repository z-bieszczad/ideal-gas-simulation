#include "../world/World.h"
#include <iostream>
#include <ctime>

int main() {
    srand(time(nullptr));
    World world;
    
    
    // Test 1: inicjalizacja
    world.initializeRandom(30, 5.0);
    
    // Test 2: statystyki
    std::cout << "=== STATYSTYKI ===" << std::endl;
    std::cout << "Cząstek: " << world.getParticles().size() << std::endl;
    std::cout << "Energia: " << world.getTotalEnergy() << std::endl;
    std::cout << "Temperatura: " << world.getTemperature() << std::endl;
    std::cout << "Ciśnienie: " << world.getPressure() << std::endl;
    
    return 0;
}