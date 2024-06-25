//
// Created by Nicolas Aguilera García  on 24/06/24.
//

#ifndef CELL_H
#define CELL_H
#include <vector>

#include "Particle.h"


class Cell {
public:
    std::vector<Particle*> balls;
    std::vector<Particle*> pegs;
};



#endif //CELL_H
