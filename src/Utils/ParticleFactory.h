//
// Created by Nicolas Aguilera García  on 23/06/24.
//

#ifndef PARTICLEFACTORY_H
#define PARTICLEFACTORY_H
#include <vector>

#include "../Entities/Particle.h"


class ParticleFactory {
public:
    std::vector<Particle*> createParticles(int n, float radius, float mass, float damping, Vector2D position, Vector2D velocity, Vector2D force);
};



#endif //PARTICLEFACTORY_H
