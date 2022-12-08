//
// Created by adam on 12/7/22.
//

#include "raylib-cpp.hpp"
#include "../State.h"

#ifndef CLION_TEXTBOX_H
#define CLION_TEXTBOX_H


class Textbox {
private:
    raylib::Rectangle rectangle;
    std::string text;
public:
    State state;

    void Render();

    std::string Text();

    raylib::Rectangle Bounds();

    explicit Textbox(std::string text);

    Textbox();
};


#endif //CLION_TEXTBOX_H
