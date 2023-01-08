cmake_minimum_required(VERSION 3.24)
project(lesson_9)

set(CMAKE_CXX_STANDARD 17)

add_executable(lesson_9 src/game/FakeFootballGame.cpp include/game/FakeFootballGame.h include/game/Game.h src/Main.cpp src/game/FootballTeam.cpp include/game/FootballTeam.h)
