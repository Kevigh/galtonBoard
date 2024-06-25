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

std::vector<Particle*> Factory::createPegs(const BoardProps& props)
{
    auto pegs = std::vector<Particle*>();
    auto random = Random();

    return pegs;
}
