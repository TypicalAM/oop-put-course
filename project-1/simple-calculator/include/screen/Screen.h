//
// Created by adam on 12/6/22.
//

#ifndef CLION_SCREEN_H
#define CLION_SCREEN_H


#include <vector>
#include "ui_elements/Textbox.h"
#include "ui_elements/Button.h"
#include "../math/expressions/ExpressionTokens.h"

const float FONTSIZE = 16.0f;
const float SMALL_BUTTON_HEIGHT = 32;
const float BIG_BUTTON_HEIGHT = 67;

const Color TEXT_COLOR{255, 255, 255, 255};
const Color BACKGROUND_COLOR{34, 33, 49, 255};
const Color BUTTON_NORMAL_COLOR{68, 68, 82, 255};
const Color BUTTON_HOVERED_COLOR{100, 100, 114, 255};
const Color BUTTON_PRESSED_COLOR{120, 120, 134, 255};

class Screen {
private:
    std::vector<Button> buttons;
    Textbox textbox;
    bool uiEnabled;
    int uiCoolDown;
    ExpressionTokens expr;
public:
    void Update();

    void Draw();

    Screen();
};


#endif //CLION_SCREEN_H
