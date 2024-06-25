//
// Created by Nicolas Aguilera García  on 7/06/24.
//

#include "Exporter.h"

#include <fstream>
#include <iostream>


void Exporter::addData(std::vector<Particle*> particles, Range xWidth, Range yWidth)
{
    int totalParticles = particles.size();
    std::string data = "";

    data += std::to_string(totalParticles + 4) + "\n";
    data += "aver\n";

    int i = 0;
    for (auto ball : particles) {
        data += std::to_string(i) + " " + "1" + " " + std::to_string(ball->position.x) + " " + std::to_string(ball->position.y) + " " + std::to_string(ball->radius) + "\n";
        i++;
    }

    // Add one ball on each corner
    data += std::to_string(i) + " " + "1" + " " + std::to_string(xWidth.min) + " " + std::to_string(yWidth.min) + " " + "1" + "\n";
    i++;
    data += std::to_string(i) + " " + "1" + " " + std::to_string(xWidth.min) + " " + std::to_string(yWidth.max) + " " + "1" + "\n";
    i++;
    data += std::to_string(i) + " " + "1" + " " + std::to_string(xWidth.max) + " " + std::to_string(yWidth.min) + " " + "1" + "\n";
    i++;
    data += std::to_string(i) + " " + "1" + " " + std::to_string(xWidth.max) + " " + std::to_string(yWidth.max) + " " + "1" + "\n";

    exportData.push_back(data);
}

void Exporter::saveData(std::string filename)
{
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        throw std::runtime_error("Could not open file for writing");
    }

    for (auto data : exportData) {
        outFile << data;
    }

    outFile.close();
}
