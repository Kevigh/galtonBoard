//
// Created by Nicolas Aguilera García  on 3/06/24.
//

#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include "../../Entities/Particle.h"


class Model {
public:
    Model() = default;
    ~Model() = default;

    virtual void updateBall(Particle& ball, float dt, float t) const = 0;
    virtual void updatePeg(Particle& pegs, float dt, float t) const = 0;
    virtual void resolveCollision(Particle& ball, Particle& peg) = 0;
};



#endif //MODEL_H
