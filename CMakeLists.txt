cmake_minimum_required(VERSION 3.28)
project(galtonBoard)

set(CMAKE_CXX_STANDARD 17)

add_executable(galtonBoard main.cpp
        Entities/Ball.cpp
        Entities/Ball.h
        Entities/Peg.cpp
        Entities/Peg.h
        Utils/Vector.cpp
        Utils/Vector.h
        Entities/Particle.cpp
        Entities/Particle.h
        Models/Model.h
        Models/ModelPointParticle.cpp
        Models/ModelPointParticle.h
        Entities/Board.cpp
        Entities/Board.h)
