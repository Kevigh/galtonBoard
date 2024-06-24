//
// Created by Nicolas Aguilera García  on 24/06/24.
//

#include "Random.h"

double Random::getRandom()
{
    return distribution(gen);
}

double Random::getRandom(double min, double max)
{
    double const random = distribution(gen);
    return random * (max - min) + min;
}

Random::Random()
    : gen(rd()), distribution(0, 1)
{
}
