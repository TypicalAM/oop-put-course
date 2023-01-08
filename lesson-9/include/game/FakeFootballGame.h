//
// Created by adam on 1/8/23.
//

#ifndef LESSON_9_FAKEFOOTBALLGAME_H
#define LESSON_9_FAKEFOOTBALLGAME_H


#include "Game.h"
#include "FootballTeam.h"

class FakeFootballGame : public Game {
public:
    std::pair<int, int> result() override;
    explicit FakeFootballGame(const std::pair<FootballTeam, FootballTeam>& teams);
};


#endif //LESSON_9_FAKEFOOTBALLGAME_H
