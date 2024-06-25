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

    gravity = Vector2D();
    gravity.y = -9.8;
    gravity.x = 0;

    horizontalConstrain = Range(0, 100);
    verticalConstrain = Range(0, 100);
    
    model = new BasicModel();
    balls = Factory::createBalls(10, props);
}

void Engine::run() {
    float t = 0;
    float dtt = dt / (subSteps * 1.0);
    
    for (step = 0; step < maxSteps; step++) {
        for (int i = 0; i < subSteps; i++) {
            applyForces();
            updateBodies(t, dtt);
            validateCollisions();
            validateConstraints();
            t += dtt;
        }
        
        exporter.addData(balls, horizontalConstrain, verticalConstrain);
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

void Engine::validateCollisions() {
    
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
