#include "raylib.h"
#include "../State.h"
#include "Textbox.h"

#ifndef CLION_BUTTON_H
#define CLION_BUTTON_H


class Button {
private:
    Rectangle rectangle;
    std::string text;
public:
    State state;

    void Render();

    Rectangle bounds();

    explicit Button(float xPos, float yPos, bool isBig, std::string text);

    Textbox Click(Textbox textbox);
};


#endif //CLION_BUTTON_H
