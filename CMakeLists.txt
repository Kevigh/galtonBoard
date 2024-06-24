cmake_minimum_required(VERSION 3.28)
project(galtonBoard)

set(CMAKE_CXX_STANDARD 17)

add_executable(galtonBoard main.cpp
        src/Utils/Vector2D.cpp
        src/Utils/Vector2D.h
        src/Entities/Particle.cpp
        src/Entities/Particle.h
        src/Logic/Models/Model.h
        src/Logic/Engine/Engine.cpp
        src/Logic/Engine/Engine.h
        src/Logic/Exporter.cpp
        src/Logic/Exporter.h
        src/Utils/ParticleFactory.cpp
        src/Utils/ParticleFactory.h
        src/Utils/Range.cpp
        src/Utils/Range.h
        src/Utils/Random.cpp
        src/Utils/Random.h
        src/Entities/Mesh.cpp
        src/Entities/Mesh.h
        src/Entities/Cell.cpp
        src/Entities/Cell.h
        src/Entities/GaltonProps.h
        src/Entities/Types.h)
