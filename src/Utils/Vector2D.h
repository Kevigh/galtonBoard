//
// Created by Nicolas Aguilera García  on 3/06/24.
//

#ifndef POINT_H
#define POINT_H



class Vector2D {
public:
    double x;
    double y;
    
    double magnitude() const;
    double magnitudeSquared() const;
    double distance(const Vector2D &p) const;

    // Define operators
    Vector2D operator+(const Vector2D &p) const;
    Vector2D operator-(const Vector2D &p) const;
    Vector2D operator*(double scalar) const;
    Vector2D operator/(double scalar) const;

    Vector2D() {}
};



#endif //POINT_H
