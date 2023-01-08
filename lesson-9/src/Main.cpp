//
// Created by adam on 1/8/23.
//

#include <iostream>
#include "../include/game/FootballTeam.h"
#include "../include/game/FakeFootballGame.h"

int main() {
    // TODO: Possibly identify games by gamehash/gameid
    FootballTeam germany("Germany");
    FootballTeam brasil("Brasil");
    auto result = FakeFootballGame(std::make_pair(germany, brasil)).result();
    if (result.first == 7 && result.second == 1) {
        std::cout << "Yay! You have passed the 2014 PTSD test!!!!!!!!!!!" <<std::endl;
    } else {
        std::cout << "No tests have passed, I shall henceforth smite your hard drive" <<std::endl;
    }
}
