//
// Created by adam on 12/6/22.
//

#include "../../../include/screen/ui_elements/Textbox.h"
#include "../../../include/screen/ui_elements/Button.h"
#include "../../../include/math/expressions/ExpressionTree.h"
#include "../../../include/math/expressions/ExpressionParseError.h"

#include <utility>

Textbox Button::Click(Textbox textbox) {
    // Evaluate the expression
    if (text == "=" && textbox.Text().length() > 1) {
        ExpressionTree tree(textbox.Text());
        return Textbox(tree.Evaluate());
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
            rectangle.Draw(raylib::Color::Magenta());
            break;
        }
        case HOVERED: {
            rectangle.Draw(raylib::Color::Gray());
            break;
        }
        case PRESSED: {
            rectangle.Draw(raylib::Color::RayWhite());
            break;
        }
    }


    // Calculate the xPos and yPos of the text, so that it can be in the middle
    int xPos = rectangle.GetX() + rectangle.GetWidth() / 2 - raylib::MeasureText(text, 16) / 2; // TODO: Define fontsize
    int yPos = rectangle.GetY() + rectangle.GetHeight() / 2 - 16 / 2;

    // Draw the button text in the middle of the button
    raylib::DrawText(text, xPos, yPos, 16, raylib::Color::Black());
}

Button::Button(float xPos, float yPos, bool isBig, std::string text) {
    // Create the bounding box
    if (isBig) {
        // TODO: PREDEFINE SMALL HEIGHT AND HIG HEIGHT
        rectangle = raylib::Rectangle(xPos, yPos, 51, 67);
    } else {
        rectangle = raylib::Rectangle(xPos, yPos, 51, 32);
    }

    // Set the text variable
    this->text = std::move(text);

    // Set the state of the button
    state = State::DEFAULT;
}

raylib::Rectangle Button::bounds() {
    return rectangle;
}
