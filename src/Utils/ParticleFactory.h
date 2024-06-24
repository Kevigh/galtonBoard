//
// Created by Nicolas Aguilera García  on 23/06/24.
//

#ifndef PARTICLEFACTORY_H
#define PARTICLEFACTORY_H
#include <vector>

#include "../Entities/GaltonProps.h"
#include "../Entities/Particle.h"


namespace Factory {
    std::vector<Particle*> createBalls(int nParticles, const BallProps& props);
    std::vector<Particle*> createPegs(const BoardProps& props);
}



#endif //PARTICLEFACTORY_H
