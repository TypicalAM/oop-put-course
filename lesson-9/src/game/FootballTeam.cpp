//
// Created by adam on 1/8/23.
//

#include <utility>

#include "../../include/game/FootballTeam.h"

FootballTeam::FootballTeam(std::string name) {
    this->name = std::move(name);
}

std::string FootballTeam::Name() {
    return name;
}
