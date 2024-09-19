//
// Created by Nicolas Aguilera García  on 7/06/24.
//

#ifndef ENGINE_H
#define ENGINE_H
#include <vector>

#include "../Exporter.h"
#include "../../Entities/GaltonProps.h"
#include "../../Entities/Mesh.h"
#include "../../Entities/Particle.h"
#include "../../Utils/Random.h"
#include "../../Utils/Range.h"
#include "../Models/Model.h"


class Engine {
public:
    bool stop{};
    float dt{};
    float damping{};
    int step{};
    int maxSteps{};
    int subSteps{};
    int totalParticles{};
    int totalPegs{};

    Vector2D gravity{};
    Range verticalConstrain{};
    Range horizontalConstrain{};

    BoardProps boardProps{};
    BallProps ballProps{};

    std::vector<Particle*> balls{};
    std::vector<Particle*> pegs{};

    Model* model;
    Random random{};
    Exporter exporter{};
    Mesh mesh{};

    std::string dataFilePath{};
    bool exportData{};

    void initialize();
    void run();
    
    void updateBodies(double t, double dtt) const;
    void validateCollisions();
    void validateConstraints();
    void applyForces() const;
    void updateMesh();
    void validateStop();

    Engine() = default;
};



#endif //ENGINE_H
