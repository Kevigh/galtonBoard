//
// Created by Nicolas Aguilera García  on 24/06/24.
//

#ifndef BASICMODEL_H
#define BASICMODEL_H
#include "Model.h"
#include "../RungeKutta.h"
#include "../../Entities/Particle.h"


class BasicModel : public Model {
public:
    RungeKutta rungeKutta{};
    
    void updateBall(Particle& ball, double dt, double t) const override;
    void updatePeg(Particle& peg, double dt, double t) const override;
    void resolveCollision(Particle& ball, Particle& peg) override;

    BasicModel();

private:
    Vector2D dPosition(double t, Vector2D position, Vector2D velocity, Vector2D acceleration);
    Vector2D dVelocity(double t, Vector2D position, Vector2D velocity, Vector2D acceleration);
};



#endif //BASICMODEL_H
