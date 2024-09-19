//
// Created by Nicolas Aguilera García  on 24/06/24.
//

#include "RungeKutta.h"

RungeKutta::RungeKutta(
    std::function<Vector2D(double t, Vector2D position, Vector2D velocity, Vector2D acceleration)> f1,
    std::function<Vector2D(double t, Vector2D position, Vector2D velocity, Vector2D acceleration)> f2)
{
    this->f1 = f1;
    this->f2 = f2;
}

RungeState RungeKutta::rungeKutta4(double dt, double t, const Vector2D& position, const Vector2D& velocity, const Vector2D& acceleration) const
{
    Vector2D k11, k21, k12, k22, k13, k23, k14, k24;

    k11 = f1(t, position, velocity, acceleration) * dt;
    k21 = f2(t, position, velocity, acceleration) * dt;
    
    k12 = f1(t + dt / 2.0, position + k11 / 2.0, velocity + k21 / 2.0, acceleration) * dt;
    k22 = f2(t + dt / 2.0, position + k11 / 2.0, velocity + k21 / 2.0, acceleration) * dt;

    k13 = f1(t + dt / 2.0, position + k12 / 2.0, velocity + k22 / 2.0, acceleration) * dt;
    k23 = f2(t + dt / 2.0, position + k12 / 2.0, velocity + k22 / 2.0, acceleration) * dt;

    k14 = f1(t + dt, position + k13, velocity + k23, acceleration) * dt;
    k24 = f2(t + dt, position + k13, velocity + k23, acceleration) * dt;

    Vector2D pos_t = position + (k11 + k12 * 2.0 + k13 * 2.0 + k14) / 6.0;
    Vector2D vel_t = velocity + (k21 + k22 * 2.0 + k23 * 2.0 + k24) / 6.0;
    
    return {
        .position = pos_t,
        .velocity = vel_t
    };
}
