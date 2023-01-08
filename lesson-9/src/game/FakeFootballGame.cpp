//
// Created by adam on 1/8/23.
//

#include "../../include/game/FakeFootballGame.h"

std::pair<int, int> FakeFootballGame::result() {
    return std::make_pair(7, 1);
}

FakeFootballGame::FakeFootballGame(const std::pair<FootballTeam, FootballTeam>& teams) {}
