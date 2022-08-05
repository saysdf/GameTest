cmake_minimum_required(VERSION 3.5)

project(ScoreWarrior LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ScoreWarrior main.cpp
    helper.hpp
    abstractobject.h abstractobject.cpp
    logger.hpp
    unitstate.h unitstate.cpp
    unit.h unit.cpp
    warrior.h warrior.cpp
    battle.h battle.cpp
    battlechecker.h battlechecker.cpp
    creatorfactory.h creatorfactory.cpp
    scenariobuilder.h scenariobuilder.cpp
    scenariocommand.h scenariocommand.cpp
    map.h map.cpp
    unitscollection.h unitscollection.cpp
    game.h game.cpp
    )
