//
// Created by adam on 1/8/23.
//

#ifndef LESSON_9_FOOTBALLTEAM_H
#define LESSON_9_FOOTBALLTEAM_H


#include <string>

class FootballTeam {
private:
    std::string name;

public:
    std::string Name();
    explicit FootballTeam(std::string name);
};


#endif //LESSON_9_FOOTBALLTEAM_H
