//
// Created by Nicolas Aguilera García  on 24/06/24.
//

#include "BasicModel.h"
#include <cmath>


void BasicModel::updateBall(Particle& ball, double dt, double t) const
{
    auto state = rungeKutta.rungeKutta4(dt, t, ball.position, ball.velocity, ball.force / ball.mass);
    ball.position = state.position;
    ball.velocity = state.velocity;
    ball.force = Vector2D();
}

void BasicModel::updatePeg(Particle& peg, double dt, double t) const
{
}

void BasicModel::resolveCollision(Particle& ball, Particle& peg)
{
    double dx = ball.position.x - peg.position.x;
    double dy = ball.position.y - peg.position.y;
    double sum_radius = ball.radius + peg.radius;
    double impact_angle = atan2(dy, dx);

    double vxa = ball.velocity.x;
    double vya = ball.velocity.y;
    double aplha_0 = peg.damping;

    double v_tangen = -vxa * sin(impact_angle) + vya * cos(impact_angle);
    double v_radial = -aplha_0 * (vxa * cos(impact_angle) + vya * sin(impact_angle));

    double vx_new = v_radial * cos(impact_angle) - v_tangen * sin(impact_angle);
    double vy_new = v_radial * sin(impact_angle) + v_tangen * cos(impact_angle);

    double new_x = (sum_radius) * cos(impact_angle) + peg.position.x;
    double new_y = (sum_radius) * sin(impact_angle) + peg.position.y;

    ball.position.x = new_x;
    ball.position.y = new_y;

    ball.velocity.x = vx_new;
    ball.velocity.y = vy_new;
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
