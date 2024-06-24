//
// Created by Nicolas Aguilera García  on 23/06/24.
//

#ifndef RANGE_H
#define RANGE_H



class Range {
public:
    double min;
    double max;

    double getRange() const;
    double getMiddle() const;

    Range(double min, double max);
    Range() = default;
};



#endif //RANGE_H
