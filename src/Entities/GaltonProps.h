//
// Created by Nicolas Aguilera García  on 24/06/24.
//

#ifndef GALTONPROPS_H
#define GALTONPROPS_H
#include "Types.h"
#include "../Utils/Range.h"

struct BoardProps
{
    int numberOfRows;
    int numberOfColumns;
    double pegRadius;
    double verticalSpacing;
    double horizontalSpacing;
    double borderDamping;
    double pegDamping;
    BoardType type;
};

struct BallProps
{
    double mass;
    double damping;
    Range radius;
    Range initialXVelocity;
    Range initialYVelocity;
    Range initialXPosition;
    Range initialYPosition;
};

#endif //GALTONPROPS_H
