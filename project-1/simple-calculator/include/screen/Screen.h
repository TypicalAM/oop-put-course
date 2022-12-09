//
// Created by adam on 12/6/22.
//

#ifndef CLION_SCREEN_H
#define CLION_SCREEN_H


#include <vector>
#include "ui_elements/Textbox.h"
#include "ui_elements/Button.h"
#include "../math/expressions/ExpressionTokens.h"

const float fontSize = 16.0f;
const float smallButtonHeight = 32;
const float bigButtonHeight = 67;

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
