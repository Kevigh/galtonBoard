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

    void addData(std::vector<Particle*> particles, std::vector<Particle*> pegs, Range xWidth, Range yWidth);
    void saveData(std::string filename);

    void saveHistogram(const std::vector<Particle*>& particles, const std::string& filename, int bins, Range xRange);
};



#endif //EXPORTER_H
