#include "raylib-cpp.hpp"
#include "../State.h"

#ifndef CLION_BUTTON_H
#define CLION_BUTTON_H


class Button {
private:
    raylib::Rectangle bounds;
    std::string text;
    State state;
public:
    void click();

    void render(); // TODO: this might be unoptimal
    explicit Button(float xPos, float yPos, bool isBig, std::string text);

    Button();
};


#endif //CLION_BUTTON_H
