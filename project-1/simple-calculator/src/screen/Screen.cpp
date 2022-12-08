//
// Created by adam on 12/6/22.
//

#include "../../include/screen/Screen.h"
#include "../../include/math/expressions/ExpressionParseError.h"

void Screen::Update() {
    // Update the state of the buttons
    for (auto &button: buttons) {
        // Check if the mouse is in the button
        if (raylib::Mouse::GetPosition().CheckCollision(button.bounds())) {
            // Check if the left mouse button is down
            if (raylib::Mouse::IsButtonDown(0) && uiEnabled) {
                if (button.state == HOVERED) {
                    try {
                        textbox = button.Click(textbox);
                    } catch (ExpressionParseError epe) {
                        uiEnabled = false;
                        uiCoolDown = 45;
                        textbox = Textbox(epe.what());
                    }
                }
                button.state = PRESSED;
            } else {
                button.state = HOVERED;
            }
        } else {
            button.state = DEFAULT;
        }
    }

    // Update the state of the textbox
    textbox.state = raylib::Mouse::GetPosition().CheckCollision(textbox.Bounds()) ? HOVERED : DEFAULT;

    // Disable the UI if the textbox gives us an error
    if (!uiEnabled && !uiCoolDown--) {
        uiEnabled = true;
        textbox = Textbox("");
    }
}

void Screen::Draw() {
    // Draw the UI elements on the screen
    for (auto button: buttons) {
        button.Render();
    }

    // Draw the textbox
    textbox.Render(!uiEnabled);
}

Screen::Screen() {
    // Initialize the screen variables
    const std::vector<std::string> buttonTexts = {"÷", "x", "-", "BACK", "C", "7", "8", "9", "+", "OR", "4", "5", "6",
                                                  "√", "AND", "1", "2", "3", "^", "(", "0", "0", ".", "=", ")"};

    // Initialize all ui_elements and append them to the ui_elements vector
    int counter = 0;
    for (int rows = 0; rows < 5; rows++) {
        for (int cols = 0; cols < 5; cols++) {
            Button newButton(10 + cols * 61, 110 + rows * 42, false, buttonTexts[counter]);
            buttons.push_back(newButton);
            counter++;
        }
    }

    // Enable the UI and the UI cooldown in case the user produces a parser error
    this->uiEnabled = true;
    this->uiCoolDown = 45;

    // Create the textbox
    this->textbox = Textbox("2+5*10");
}
