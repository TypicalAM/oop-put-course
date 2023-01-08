//
// Created by adam on 1/8/23.
//

#ifndef LESSON_9_GAME_H
#define LESSON_9_GAME_H

#include <utility>
#include <string>

class Game {
public:
    virtual std::pair<int, int> result() = 0;
};

#endif //LESSON_9_GAME_H
