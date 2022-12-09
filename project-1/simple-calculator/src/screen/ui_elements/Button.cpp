//
// Created by adam on 12/6/22.
//

#include "../../../include/screen/ui_elements/Textbox.h"
#include "../../../include/screen/ui_elements/Button.h"
#include "../../../include/screen/Screen.h"

#include <utility>

Textbox Button::Click(Textbox textbox) {
    // Evaluate the expression
    if (text == "=") return textbox.EqualsSign();

    // Delete the last character
    if (text == "BACK") return textbox.Backspace();

    // Clear the screen
    if (text == "C") return textbox.C();

    return Textbox(textbox.Text().append(text));
}

void Button::Render() {
    // Draw the bounding rectangle
    switch (state) {
        case DEFAULT: {
            DrawRectangleRec(rectangle, BUTTON_NORMAL_COLOR);
            break;
        }
        case HOVERED: {
            DrawRectangleRec(rectangle, BUTTON_HOVERED_COLOR);
            break;
        }
        case PRESSED: {
            DrawRectangleRec(rectangle, BUTTON_PRESSED_COLOR);
            break;
        }
    }

    // Calculate the xPos and yPos of the text, so that it can be in the middle
    int xPos = rectangle.x + rectangle.width / 2 - MeasureText(text.c_str(), FONTSIZE) / 2;
    int yPos = rectangle.y + rectangle.height / 2 - FONTSIZE / 2;

    // Draw the button text in the middle of the button
    DrawText(text.c_str(), xPos, yPos, 16, TEXT_COLOR);
}

Button::Button(float xPos, float yPos, bool isBig, std::string text) {
    // Set the text variable
    this->text = std::move(text);

    // Create the bounding box
    rectangle = Rectangle{xPos, yPos, 51, ((isBig) ? BIG_BUTTON_HEIGHT : SMALL_BUTTON_HEIGHT)};

    // Set the state of the button
    state = State::DEFAULT;
}

Rectangle Button::bounds() {
    return rectangle;
}
