//
// Created by Nicolas Aguilera García  on 24/06/24.
//

#ifndef MESH_H
#define MESH_H
#include <vector>

#include "Cell.h"
#include "Particle.h"


class Mesh {
public:
    std::vector<Cell*> cells;

    int rows;
    int cols;
    double width;
    double height;

    Cell* getCell(int row, int col) const;
    void addParticle(Particle* particle) const;
    void addParticles(const std::vector<Particle*>& particles) const;
    void createCells(int rows, int cols, double width, double height);
    void clear() const;
    
};



#endif //MESH_H
