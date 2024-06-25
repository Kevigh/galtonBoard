//
// Created by Nicolas Aguilera García  on 7/06/24.
//

#ifndef ENGINE_H
#define ENGINE_H
#include <vector>

#include "../Exporter.h"
#include "../../Entities/Particle.h"
#include "../../Utils/Random.h"
#include "../../Utils/Range.h"
#include "../Models/Model.h"


class Engine {
public:
    float dt{};
    float damping{};
    int step{};
    int maxSteps{};
    int subSteps{};

    Vector2D gravity{};
    Range verticalConstrain{};
    Range horizontalConstrain{};

    std::vector<Particle*> balls{};
    std::vector<Particle*> pegs{};

    Model* model;
    Random random{};
    Exporter exporter{};

    void initialize();
    void run();
    
    void updateBodies(float t, float dtt) const;
    void validateCollisions();
    void validateConstraints();
    void applyForces() const;

    Engine() = default;
};



#endif //ENGINE_H
