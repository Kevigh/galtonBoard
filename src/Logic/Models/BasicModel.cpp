//
// Created by Nicolas Aguilera García  on 24/06/24.
//

#include "BasicModel.h"


void BasicModel::updateBall(Particle& ball, float dt, float t) const
{
    auto state = rungeKutta.rungeKutta4(dt, t, ball.position, ball.velocity, ball.force / ball.mass);
    ball.position = *state.position;
    ball.velocity = *state.velocity;
    ball.force = Vector2D();
}

void BasicModel::updatePeg(Particle& peg, float dt, float t) const
{
}

BasicModel::BasicModel()
{
    using namespace std::placeholders; // Para usar _1, _2, etc.
    rungeKutta = RungeKutta(
        std::bind(&BasicModel::dPosition, this, _1, _2, _3, _4),
        std::bind(&BasicModel::dVelocity, this, _1, _2, _3, _4)
    );
}

Vector2D BasicModel::dPosition(double t, Vector2D position, Vector2D velocity, Vector2D acceleration)
{
    return velocity;
}

Vector2D BasicModel::dVelocity(double t, Vector2D position, Vector2D velocity, Vector2D acceleration)
{
    return acceleration;
}
