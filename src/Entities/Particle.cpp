//
// Created by Nicolas Aguilera García  on 3/06/24.
//

#include "Particle.h"

std::string Particle::toString() const {
    std::string str = std::to_string(position.x) + " " + std::to_string(position.y) + " ";
    return str;
}
