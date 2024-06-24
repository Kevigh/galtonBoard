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

double Random::getRandom(Range range)
{
    double const random = distribution(gen);
    return random * (range.max - range.min) + range.min;
}

Random::Random()
    : gen(rd()), distribution(0, 1)
{
}
