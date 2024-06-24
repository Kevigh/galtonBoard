//
// Created by Nicolas Aguilera García  on 7/06/24.
//

#ifndef ENGINE_H
#define ENGINE_H
#include <vector>

#include "../Models/Model.h"
#include "../Utils/Random.h"
#include "../Utils/Range.h"
#include "../Utils/Vector2D.h"


class Engine {
public:
    float dt{};
    float damping{};

    Vector2D gravity{};
    Vector2D origin{};
    Range verticalConstrain{};
    Range horizontalConstrain{};

    std::vector<Particle*> bodies{};
    std::vector<Particle*> pegs{};

    Model* model{};
    Random random{};

    void initialize();

    void update();
    void updateBodies();
    void validateCollisions();
    void validateConstraints();

    Engine() = default;
};



#endif //ENGINE_H
