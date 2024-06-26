//
// Created by Nicolas Aguilera García  on 24/06/24.
//

#include "Mesh.h"

Cell* Mesh::getCell(int row, int col) const
{
    Cell* cell = cells[row * cols + col];
    return cell;
}

void Mesh::addParticle(Particle* particle) const
{
    const double x = particle->position.x;
    const double y = particle->position.y;

    int row = std::floor(y / height);
    if (row >= rows) {
        row = rows - 1;
    }
    int col = std::floor(x / width);
    if (col >= cols) {
        col = cols - 1;
    }
    Cell* cell = getCell(row, col);

    if (particle->type == BALL) {
        cell->balls.push_back(particle);
    } else {
        cell->pegs.push_back(particle);
    }
}

void Mesh::addParticles(const std::vector<Particle*>& particles) const
{
    for (auto particle : particles) {
        addParticle(particle);
    }
}

void Mesh::createCells(const int rows, const int cols, const double width, const double height)
{
    const int totalCells = rows * cols;
    cells.reserve(totalCells);

    for (int i = 0; i < totalCells; i++) {
        auto* cell = new Cell();
        cells.push_back(cell);
    }

    this->width = width;
    this->height = height;
    this->rows = rows;
    this->cols = cols;
}

void Mesh::clear() const
{
    for (auto cell : cells) {
        cell->balls.clear();
        cell->pegs.clear();
    }
}
