//
// Created by adam on 12/6/22.
//

#include "../../../include/screen/ui_elements/Textbox.h"
#include "../../../include/screen/ui_elements/Button.h"
#include "../../../include/math/expressions/ExpressionParser.h"
#include "../../../include/screen/Screen.h"

#include <utility>

Textbox Button::Click(Textbox textbox) {
    // Evaluate the expression
    if (text == "=" && textbox.Text().length() > 1) {
        return Textbox(ExpressionParser(textbox.Text()).RPN());
    }

    // Delete the last character
    if (text == "BACK") {
        if (textbox.Text().length() == 0) {
            return textbox;
        }

        std::string expressionText = textbox.Text();
        expressionText.pop_back();
        return Textbox(expressionText);
    }

    // Clear the screen
    if (text == "C") {
        return Textbox("");
    }

    return Textbox(textbox.Text().append(text));
}

void Button::Render() {
    // Draw the bounding rectangle
    switch (state) {
        case DEFAULT: {
            DrawRectangleRec(rectangle, MAGENTA);
            break;
        }
        case HOVERED: {
            DrawRectangleRec(rectangle, GRAY);
            break;
        }
        case PRESSED: {
            DrawRectangleRec(rectangle, RAYWHITE);
            break;
        }
    }

    // Calculate the xPos and yPos of the text, so that it can be in the middle
    int xPos = rectangle.x + rectangle.width / 2 - MeasureText(text.c_str(), fontSize) / 2;
    int yPos = rectangle.y + rectangle.height / 2 - fontSize / 2;

    // Draw the button text in the middle of the button
    DrawText(text.c_str(), xPos, yPos, 16, BLACK);
}

Button::Button(float xPos, float yPos, bool isBig, std::string text) {
    // Set the text variable
    this->text = std::move(text);

    // Create the bounding box
    rectangle = Rectangle{xPos, yPos, 51, ((isBig) ? bigButtonHeight : smallButtonHeight)};

    // Set the state of the button
    state = State::DEFAULT;
}

Rectangle Button::bounds() {
    return rectangle;
}
