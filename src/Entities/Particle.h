//
// Created by Nicolas Aguilera García  on 3/06/24.
//

#ifndef PARTICLE_H
#define PARTICLE_H
#include <string>

#include "Types.h"
#include "../Utils/Vector2D.h"


class Particle {
public:
    Particle() = default;
    ~Particle() = default;
    Vector2D position{};
    Vector2D velocity{};
    Vector2D force{};
    double radius{};
    double mass{};
    double damping{};
    bool isStopped{};
    ParticleType type{};

    bool collidesWith(const Particle& peg) const;
    virtual std::string toString() const;
};



#endif //PARTICLE_H
