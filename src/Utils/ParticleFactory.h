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
    std::vector<Particle*> createPegs(const double delta, const BoardProps& props, Range& horizontalConstrain, Range& verticalConstraint, std::vector<double>& columnsPositions);
    std::vector<Particle*> createPegsSize(const double delta, const BoardProps& props, Range& horizontalConstrain, Range& verticalConstraint, std::vector<double>& columnsPositions);
}



#endif //PARTICLEFACTORY_H
