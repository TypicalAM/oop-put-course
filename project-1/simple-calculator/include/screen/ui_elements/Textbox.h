//
// Created by adam on 12/7/22.
//

#include <string>
#include "raylib.h" // Rectangle
#include "../State.h"

#ifndef CLION_TEXTBOX_H
#define CLION_TEXTBOX_H


class Textbox {
private:
    Rectangle rectangle{};
    std::string text;
public:
    State state;

    std::string Text();

    Rectangle Bounds();

    explicit Textbox(std::string text);

    Textbox();

    void Render(bool isError);
};


#endif //CLION_TEXTBOX_H
