//
// Created by Nicolas Aguilera García  on 3/06/24.
//

#ifndef MODEL_H
#define MODEL_H
#include <vector>

#include "../Entities/Particle.h"


class Model {
public:
    Model() = default;
    virtual ~Model() = default;

    virtual void updateBalls(std::vector<Particle>* balls, float dt) = 0;
    virtual void updatePegs(std::vector<Particle>* pegs, float dt) = 0;
};



#endif //MODEL_H
