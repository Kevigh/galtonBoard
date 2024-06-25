//
// Created by Nicolas Aguilera García  on 24/06/24.
//

#ifndef RUNGEKUTTA_H
#define RUNGEKUTTA_H
#include <functional>

#include "../Entities/Types.h"


class RungeKutta {
public:
    RungeState rungeKutta4(double dt, double t, const Vector2D& position, const Vector2D& velocity, const Vector2D& acceleration) const;

    RungeKutta(std::function<Vector2D(double t, Vector2D position, Vector2D velocity, Vector2D acceleration)> f1,
               std::function<Vector2D(double t, Vector2D position, Vector2D velocity, Vector2D acceleration)> f2);
    RungeKutta() = default;
private:
    std::function<Vector2D(double t, Vector2D position, Vector2D velocity, Vector2D acceleration)> f1;
    std::function<Vector2D(double t, Vector2D position, Vector2D velocity, Vector2D acceleration)> f2;
};



#endif //RUNGEKUTTA_H
