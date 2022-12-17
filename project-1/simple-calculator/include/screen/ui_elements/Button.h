#include "raylib.h"
#include "../State.h"
#include "Textbox.h"

#ifndef CLION_BUTTON_H
#define CLION_BUTTON_H


class Button {
private:
    Rectangle rectangle{};
    std::string text;
    Font font;
public:
    State state;

    void Render();

    Rectangle bounds();

    Textbox Click(Textbox textbox);

    explicit Button(Font font, float xPos, float yPos, bool isBig, std::string text);
};


#endif //CLION_BUTTON_H
