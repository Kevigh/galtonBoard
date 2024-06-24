//
// Created by Nicolas Aguilera García  on 23/06/24.
//

#include "Range.h"


double Range::getRange() const
{
    return max - min;
}

double Range::getMiddle() const
{
    return (max - min) / 2;
}

Range::Range(double min, double max)
    : min(min), max(max)
{}
