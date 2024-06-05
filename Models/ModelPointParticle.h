//
// Created by Nicolas Aguilera García  on 4/06/24.
//

#ifndef MODELPOINTPARTICLE_H
#define MODELPOINTPARTICLE_H
#include "Model.h"


class ModelPointParticle : public Model {
public:
    void updateBalls(std::vector<Ball>* balls, float dt) override;
    void updatePegs(std::vector<Peg>* pegs, float dt) override;
};



#endif //MODELPOINTPARTICLE_H
