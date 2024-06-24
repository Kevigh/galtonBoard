//
// Created by Nicolas Aguilera García  on 3/06/24.
//

#include "Vector2D.h"
#include <cmath>

double Vector2D::magnitude() const {
    return sqrt(x * x + y * y);
}

double Vector2D::magnitudeSquared() const {
    return x * x + y * y;
}

double Vector2D::distance(const Vector2D &p) const {
    const double dx = x - p.x;
    const double dy = y - p.y;

    return sqrt(dx * dx + dy * dy);
}
