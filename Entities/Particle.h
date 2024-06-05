//
// Created by Nicolas Aguilera García  on 3/06/24.
//

#ifndef PARTICLE_H
#define PARTICLE_H
#include <string>

#include "../Utils/Vector.h"


class Particle {
public:
    virtual ~Particle() = default;

    Vector position{};
    Vector velocity{};
    float radius{};
    float mass{};

    virtual std::string toString() const;
};



#endif //PARTICLE_H
