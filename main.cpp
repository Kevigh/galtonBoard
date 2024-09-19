#include <iostream>
#include "./src/Entities/Particle.h"
#include "src/Logic/Engine/Engine.h"
#include <chrono>

int main()
{
    const auto start = std::chrono::high_resolution_clock::now();

    Engine engine;
    engine.maxSteps = 3000;
    engine.subSteps = 10;
    engine.dt = 0.03;
    engine.damping = 0.6;
    engine.dataFilePath = "/Users/niaggar/Developer/Results/GaltonBoard/";
    engine.exportData = true;
    engine.totalParticles = 2500;

    engine.initialize();
    engine.run();

    const auto end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}
