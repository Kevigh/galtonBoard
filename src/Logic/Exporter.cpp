//
// Created by Nicolas Aguilera García  on 7/06/24.
//

#include "Exporter.h"

#include <fstream>
#include <iostream>


void Exporter::addData(std::vector<Particle*> particles, std::vector<Particle*> pegs, Range xWidth, Range yWidth)
{
    int totalBalls = particles.size();
    int totalPegs = pegs.size();
    int totalBorders = 4;
    int totalParticles = totalBalls + totalPegs + totalBorders;
    std::string data = "";

    data += std::to_string(totalParticles) + "\n";
    data += "aver\n";

    int i = 0;
    for (auto ball : particles) {
        data += std::to_string(i) + " " + "1" + " " + std::to_string(ball->position.x) + " " + std::to_string(ball->position.y) + " " + std::to_string(ball->radius) + "\n";
        i++;
    }

    for (auto peg : pegs) {
        data += std::to_string(i) + " " + "2" + " " + std::to_string(peg->position.x) + " " + std::to_string(peg->position.y) + " " + std::to_string(peg->radius) + "\n";
        i++;
    }

    // Add one ball on each corner
    data += std::to_string(i) + " " + "3" + " " + std::to_string(xWidth.min) + " " + std::to_string(yWidth.min) + " " + "1" + "\n";
    i++;
    data += std::to_string(i) + " " + "3" + " " + std::to_string(xWidth.min) + " " + std::to_string(yWidth.max) + " " + "1" + "\n";
    i++;
    data += std::to_string(i) + " " + "3" + " " + std::to_string(xWidth.max) + " " + std::to_string(yWidth.min) + " " + "1" + "\n";
    i++;
    data += std::to_string(i) + " " + "3" + " " + std::to_string(xWidth.max) + " " + std::to_string(yWidth.max) + " " + "1" + "\n";

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

void Exporter::saveHistogram(const std::vector<Particle*>& particles, const std::string& filename, int bins, Range xRange)
{
    double binWidth = (xRange.max - xRange.min) / bins;
    std::vector<int> histogram(bins, 0);

    for (auto particle : particles) {
        int bin = std::floor((particle->position.x - xRange.min) / binWidth);
        if (bin >= 0 && bin < bins) {
            histogram[bin]++;
        }
    }

    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        throw std::runtime_error("Could not open file for writing");
    }

    for (int i = 0; i < bins; i++) {
        outFile << i  << "\t" << histogram[i] << "\n";
    }

    outFile.close();
}
