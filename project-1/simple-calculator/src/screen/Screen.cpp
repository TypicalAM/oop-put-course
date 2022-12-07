//
// Created by adam on 12/6/22.
//

#include "Screen.h"
#include "ui_elements/Button.h"

void Screen::Update() {
    // Update the variables used in this screen
    for (auto &button: buttons) {
        // Check if the mouse is in the button
        if (!raylib::Mouse::GetPosition().CheckCollision(button.bounds())) {
            // The button has been released,and perform the button action if true
            if (button.state == PRESSED) { button.Click(); }
            button.state = DEFAULT;
        } else {
            // Check if the left mouse button is down
            if (raylib::Mouse::IsButtonDown(90)) {
                button.state = PRESSED;
            } else {
                button.state = HOVERED;
            }
        }
    }
}

void Screen::Draw() {
    // Draw the UI elements on the screen
    for (auto button: buttons) {
        button.Render();
    }

    // Draw the textbox
    textbox.Render();
}

Screen::Screen() {
    // Initialize the screen variables
    const std::vector<std::string> buttonTexts = {"÷", "x", "-", "+", "C", "7", "8", "9", "√", "OR", "4", "5", "6",
                                                  "^", "AND", "1", "2", "3", "=", "(", "0", "0", ".", "=", ")"};

    // Initialize all ui_elements and append them to the ui_elements vector
    int counter = 0;
    for (int rows = 0; rows < 5; rows++) {
        for (int cols = 0; cols < 5; cols++) {
            Button newButton(10 + cols * 61, 110 + rows * 42, false, buttonTexts[counter]);
            buttons.push_back(newButton);
            counter++;
        }
    }

    // Create the textbox
    this->textbox = Textbox("2+5+10-50");
}
