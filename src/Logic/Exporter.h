//
// Created by Nicolas Aguilera García  on 7/06/24.
//

#ifndef EXPORTER_H
#define EXPORTER_H
#include <vector>

#include "../Entities/Particle.h"
#include "../Utils/Range.h"

class Exporter {
public:
    std::vector<std::string> exportData{};

    void addData(const std::vector<Particle *>& particles, const std::vector<Particle *>& pegs, int totalParticles, int totalPegs,
                 Range xWidth, Range yWidth);

    void saveData(std::string filename);

    void saveHistogram(const std::string &filename, const std::vector<Particle *> &particles, int bins, Range xRange);
};


#endif //EXPORTER_H
