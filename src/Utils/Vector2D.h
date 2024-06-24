//
// Created by Nicolas Aguilera García  on 3/06/24.
//

#ifndef POINT_H
#define POINT_H



class Vector2D {
public:
    double x{};
    double y{};

    double magnitude() const;
    double magnitudeSquared() const;
    double distance(const Vector2D &p) const;
};



#endif //POINT_H
