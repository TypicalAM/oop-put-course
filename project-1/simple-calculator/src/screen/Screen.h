//
// Created by adam on 12/6/22.
//

#ifndef CLION_SCREEN_H
#define CLION_SCREEN_H


#include "ui_elements/Button.h"
#include "ui_elements/Textbox.h"

class Screen {
private:
    std::vector<Button> buttons;
    Textbox textbox;
public:
    void Update();

    void Draw();

    Screen();

};


#endif //CLION_SCREEN_H
