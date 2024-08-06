//
// Created by Nicolas Aguilera García  on 7/06/24.
//

#include "Engine.h"

#include "../../Utils/ParticleFactory.h"
#include "../Models/BasicModel.h"

void Engine::initialize()
{
    const double pegRadius = 10;
    const int columns = 13;
    const int rows = 10;
    
    ballProps = {
        .radius = {pegRadius/5, pegRadius/5},
        .mass = 1,
        .damping = 1,
        .initialXVelocity = {-1, 1},
        .initialYVelocity = {-5, 0},
        .initialXPosition = {(pegRadius * 4 * columns) / 2 - pegRadius / 2, (pegRadius * 4 * columns) / 2 + pegRadius / 2},
        .initialYPosition = {pegRadius * 2 * rows, pegRadius * 2 * rows}
    };

    boardProps = {
        .numberOfColumns = columns,
        .numberOfRows = rows,
        .pegRadius = pegRadius / 1.3,
        .verticalSpacing = pegRadius * 2,
        .horizontalSpacing = pegRadius * 4,
        .borderDamping = 0.5,
        .pegDamping = 0.5,
        .type = BoardType::GALTON        
    };

    gravity = Vector2D();
    gravity.y = -9.8;
    gravity.x = 0;
    maxSteps = 4000;

    horizontalConstrain = Range(0, pegRadius * 4 * columns);
    verticalConstrain = Range(0, pegRadius * 2 * rows);

    std::vector<double> columnsPositions;
    
    mesh = Mesh();
    model = new BasicModel();
    // pegs = Factory::createPegsSize(0.1, boardProps, horizontalConstrain, verticalConstrain, columnsPositions);
    pegs = Factory::createPegs(1.0, boardProps, horizontalConstrain, verticalConstrain, columnsPositions);


    // get the middle of the board
    std::cout << "Number of columns" << columnsPositions.size() << std::endl;
    double middle = columnsPositions[columnsPositions.size() / 2];
    ballProps.initialXPosition = {middle, middle};
    ballProps.initialYPosition = {verticalConstrain.max, verticalConstrain.max};
    
    balls = Factory::createBalls(2500, ballProps);
    mesh.createCells(10, 10, 10, 10);
}

void Engine::run() {
    float t = 0;
    float dtt = dt / (subSteps * 1.0);
    
    for (step = 0; step < maxSteps; step++) {
        for (int i = 0; i < subSteps; i++) {
            if (stop) {
                break;
            }
            
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
    exporter.saveHistogram(balls, "/Users/niaggar/Developer/Temporal/GaltonBoardTest/histogram.txt", boardProps.numberOfColumns, horizontalConstrain);
}

void Engine::updateBodies(float t, float dtt) const
{
    for (auto ball : balls) {
        if (ball->isStopped) {
            continue;
        }
        
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
                if (ball->isStopped) {
                    continue;
                }
                
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
            ball->isStopped = true;
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

void Engine::validateStop()
{
    int stopped = 0;
    for (auto ball : balls) {
        if (ball->isStopped) {
            stopped++;
        }
    }

    if (stopped == balls.size()) {
        std::cout << "All balls stopped" << std::endl;
        stop = true;
    }
}
