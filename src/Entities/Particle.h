//
// Created by Nicolas Aguilera García  on 3/06/24.
//

#ifndef PARTICLE_H
#define PARTICLE_H
#include <string>

#include "../Utils/Vector2D.h"


class Particle {
public:
    virtual ~Particle() = default;

    Vector2D position{};
    Vector2D velocity{};
    Vector2D force{};
    float radius{};
    float mass{};
    float damping{};

    virtual std::string toString() const;
};



#endif //PARTICLE_H
