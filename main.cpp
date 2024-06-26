#include <iostream>
#include "./src/Entities/Particle.h"
#include "src/Logic/Engine/Engine.h"

int main()
{
    Engine engine;
    engine.maxSteps = 3000;
    engine.subSteps = 10;
    engine.dt = 0.03;
    engine.damping = 0.6;

    
    engine.initialize();
    std::cout << "Version: " << engine.balls.size() << std::endl;
    engine.run();
    
    return 0;
}
