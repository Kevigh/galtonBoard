//
// Created by Nicolas Aguilera García  on 3/06/24.
//

#ifndef MODEL_H
#define MODEL_H
#include <vector>

#include "../Entities/Ball.h"
#include "../Entities/Peg.h"


class Model {
public:
    virtual ~Model() = default;

    virtual void updateBalls(std::vector<Ball>* balls, float dt) = 0;
    virtual void updatePegs(std::vector<Peg>* pegs, float dt) = 0;
};



#endif //MODEL_H
