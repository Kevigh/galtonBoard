//
// Created by Nicolas Aguilera García  on 24/06/24.
//

#ifndef RANDOM_H
#define RANDOM_H

#include <iostream>
#include <random>


class Random {
public:
    double getRandom();
    double getRandom(double min, double max);

    Random();

private:
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<> distribution;
};



#endif //RANDOM_H
