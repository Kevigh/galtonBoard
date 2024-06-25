//
// Created by Nicolas Aguilera García  on 24/06/24.
//

#ifndef TYPES_H
#define TYPES_H
#include "../Utils/Vector2D.h"

enum ParticleType {
    BALL,
    PEG
};

enum BoardType {
    GALTON,
    CUSTOM
};

struct RungeState
{
    Vector2D* position;
    Vector2D* velocity;
};

#endif //TYPES_H
