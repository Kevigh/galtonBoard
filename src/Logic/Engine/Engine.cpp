//
// Created by Nicolas Aguilera García  on 7/06/24.
//

#include "Engine.h"

#include "../../Utils/ParticleFactory.h"
#include "../Models/BasicModel.h"

void Engine::initialize()
{
    const BallProps props = {
        .radius = {1, 2},
        .mass = 1,
        .damping = 1,
        .initialXVelocity = {-10, 10},
        .initialYVelocity = {-10, 10},
        .initialXPosition = {0, 100},
        .initialYPosition = {0, 100}
    };

    const BoardProps boardProps = {
        .numberOfColumns = 10,
        .numberOfRows = 10,
        .pegRadius = 1,
        .verticalSpacing = 1,
        .horizontalSpacing = 1,
        .borderDamping = 1,
        .pegDamping = 1,
        .type = BoardType::GALTON        
    };

    gravity = Vector2D();
    gravity.y = -9.8;
    gravity.x = 0;

    horizontalConstrain = Range(0, 100);
    verticalConstrain = Range(0, 100);

    
    mesh = Mesh();
    model = new BasicModel();
    pegs = Factory::createPegs(boardProps);
    balls = Factory::createBalls(30, props);
    mesh.createCells(10, 10, 10, 10);
}

void Engine::run() {
    float t = 0;
    float dtt = dt / (subSteps * 1.0);
    
    for (step = 0; step < maxSteps; step++) {
        for (int i = 0; i < subSteps; i++) {
            applyForces();
            updateBodies(t, dtt);
            updateMesh();
            validateCollisions();
            validateConstraints();
            t += dtt;
        }
        
        exporter.addData(balls, pegs, horizontalConstrain, verticalConstrain);
    }

    exporter.saveData("/Users/niaggar/Developer/Temporal/GaltonBoardTest/data.txt");
}

void Engine::updateBodies(float t, float dtt) const
{
    for (auto ball : balls) {
        model->updateBall(*ball, dtt, t);
    }
    
    for (auto peg : pegs) {
        model->updatePeg(*peg, dtt, t);
    }
}

void Engine::validateCollisions()
{
    int rows = mesh.rows;
    int cols = mesh.cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Cell* cell = mesh.getCell(i, j);
            std::vector<Particle*> pegs = cell->pegs;
            std::vector<Particle*> balls = cell->balls;

            if (i > 0) {
                std::vector<Particle*> topPegs = mesh.getCell(i - 1, j)->pegs;
                pegs.insert(pegs.end(), topPegs.begin(), topPegs.end());
                if (j > 0) {
                    std::vector<Particle*> topLeftPegs = mesh.getCell(i - 1, j - 1)->pegs;
                    pegs.insert(pegs.end(), topLeftPegs.begin(), topLeftPegs.end());
                }
                if (j < cols - 1) {
                    std::vector<Particle*> topRightPegs = mesh.getCell(i - 1, j + 1)->pegs;
                    pegs.insert(pegs.end(), topRightPegs.begin(), topRightPegs.end());
                }
            }

            if (j > 0) {
                std::vector<Particle*> leftPegs = mesh.getCell(i, j - 1)->pegs;
                pegs.insert(pegs.end(), leftPegs.begin(), leftPegs.end());
            }

            if (j < cols - 1) {
                std::vector<Particle*> rightPegs = mesh.getCell(i, j + 1)->pegs;
                pegs.insert(pegs.end(), rightPegs.begin(), rightPegs.end());
            }

            if (i < rows - 1) {
                std::vector<Particle*> bottomPegs = mesh.getCell(i + 1, j)->pegs;
                pegs.insert(pegs.end(), bottomPegs.begin(), bottomPegs.end());
                if (j > 0) {
                    std::vector<Particle*> bottomLeftPegs = mesh.getCell(i + 1, j - 1)->pegs;
                    pegs.insert(pegs.end(), bottomLeftPegs.begin(), bottomLeftPegs.end());
                }
                if (j < cols - 1) {
                    std::vector<Particle*> bottomRightPegs = mesh.getCell(i + 1, j + 1)->pegs;
                    pegs.insert(pegs.end(), bottomRightPegs.begin(), bottomRightPegs.end());
                }
            }

            for (auto ball : balls) {
                for (auto peg : pegs) {
                    if (ball->collidesWith(*peg)) {
                        model->resolveCollision(*ball, *peg);
                    }
                }
            }
        }
    }    
}

void Engine::validateConstraints()
{
    for (auto ball : balls) {
        if (ball->position.x - ball->radius < horizontalConstrain.min) {
            ball->position.x = horizontalConstrain.min + ball->radius;
            ball->velocity.x = -ball->velocity.x * damping;
        }
        
        if (ball->position.x + ball->radius > horizontalConstrain.max) {
            ball->position.x = horizontalConstrain.max - ball->radius;
            ball->velocity.x = -ball->velocity.x * damping;
        }
        
        if (ball->position.y - ball->radius < verticalConstrain.min) {
            ball->position.y = verticalConstrain.min + ball->radius;
            ball->velocity.y = -ball->velocity.y * damping;
        }
        
        if (ball->position.y + ball->radius > verticalConstrain.max) {
            ball->position.y = verticalConstrain.max - ball->radius;
            ball->velocity.y = -ball->velocity.y * damping;
        }
    }
}

void Engine::applyForces() const
{
    for (auto ball : balls) {
        ball->force = ball->force + gravity * ball->mass;
    }
}

void Engine::updateMesh()
{
    mesh.clear();
    for (auto ball : balls) {
        mesh.addParticle(ball);
    }
    for (auto peg : pegs) {
        mesh.addParticle(peg);
    }
}
