//
// Created by Nicolas Aguilera García  on 3/06/24.
//

#include "Particle.h"

bool Particle::collidesWith(const Particle& peg) const
{
    const double sumRadius = radius + peg.radius;
    const double distance = position.distance(peg.position);
    return distance < sumRadius;
}

std::string Particle::toString() const {
    std::string str = std::to_string(position.x) + " " + std::to_string(position.y) + " ";
    return str;
}
