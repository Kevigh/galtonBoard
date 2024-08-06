//
// Created by Nicolas Aguilera García  on 23/06/24.
//

#include "ParticleFactory.h"

#include "Random.h"

std::vector<Particle*> Factory::createBalls(const int nParticles, const BallProps& props)
{
    auto particles = std::vector<Particle*>();
    auto random = Random();
    
    for (int i = 0; i < nParticles; i++) {
        auto* particle = new Particle();

        particle->position.x = random.getRandom(props.initialXPosition);
        particle->position.y = random.getRandom(props.initialYPosition);
        particle->radius = random.getRandom(props.radius);
        particle->velocity.x = random.getRandom(props.initialXVelocity);
        particle->velocity.y = random.getRandom(props.initialYVelocity);
        particle->mass = props.mass;
        particle->damping = props.damping;
        particle->type = BALL;

        particles.push_back(particle);
    }

    return particles;
}

std::vector<Particle*> Factory::createPegs(const double delta, const BoardProps& props, Range& horizontalConstrain, Range& verticalConstrain, std::vector<double>& columnsPositions)
{
    auto pegs = std::vector<Particle*>();
    auto width = 0.0;
    auto height = 0.0;
    auto columnsPositionsInt = std::vector<double>();
    
    for (int i = 0; i < props.numberOfRows; i++) {
        for (int j = 0; j < props.numberOfColumns; j++) {
            auto peg = new Particle();
            auto x = j * props.horizontalSpacing - j * j * delta;
            auto y = i * props.verticalSpacing;

            if (i % 2 != 0) {
                x += props.horizontalSpacing / 2;
            }

            peg->damping = props.pegDamping;
            peg->position.x = x;
            peg->position.y = y;
            peg->radius = props.pegRadius;
            peg->type = PEG;

            pegs.push_back(peg);

            width = x;
            height = y;

            if (i == props.numberOfRows - 1) {
                columnsPositionsInt.push_back(x);
            }
        }
    }

    horizontalConstrain = Range(0, width);
    verticalConstrain = Range(0, height + props.pegRadius * 2);
    columnsPositions = columnsPositionsInt;

    return pegs;
}

std::vector<Particle*> Factory::createPegsSize(const double delta, const BoardProps& props, Range& horizontalConstrain, Range& verticalConstrain, std::vector<double>& columnsPositions)
{
    auto pegs = std::vector<Particle*>();
    auto width = 0.0;
    auto height = 0.0;
    auto columnsPositionsInt = std::vector<double>();
    
    for (int i = 0; i < props.numberOfRows; i++) {
        for (int j = 0; j < props.numberOfColumns; j++) {
            auto peg = new Particle();
            auto x = j * props.horizontalSpacing;
            auto y = i * props.verticalSpacing;

            if (i % 2 != 0) {
                x += props.horizontalSpacing / 2;
            }

            peg->damping = props.pegDamping;
            peg->position.x = x;
            peg->position.y = y;
            peg->radius = props.pegRadius + (j * j * delta);
            peg->type = PEG;

            pegs.push_back(peg);

            width = x;
            height = y;

            if (i == props.numberOfRows - 1) {
                columnsPositionsInt.push_back(x);
            }
        }
    }

    horizontalConstrain = Range(0, width);
    verticalConstrain = Range(0, height + props.pegRadius * 2);
    columnsPositions = columnsPositionsInt;

    return pegs;
}


