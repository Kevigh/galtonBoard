//
// Created by Nicolas Aguilera García  on 3/06/24.
//

#include "Vector.h"
#include <cmath>

double Vector::magnitude() const {
    return sqrt(x * x + y * y);
}

double Vector::magnitudeSquared() const {
    return x * x + y * y;
}

double Vector::distance(const Vector &p) const {
    const double dx = x - p.x;
    const double dy = y - p.y;

    return sqrt(dx * dx + dy * dy);
}
