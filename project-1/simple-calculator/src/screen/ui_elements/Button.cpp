//
// Created by adam on 12/6/22.
//

#include "Button.h"

#include <utility>

void Button::Click() {
    printf("%s has been clicked!\n", text.c_str());
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
        this->rectangle = raylib::Rectangle(xPos, yPos, 51, 67);
    } else {
        this->rectangle = raylib::Rectangle(xPos, yPos, 51, 32);
    }

    // Set the text variable
    this->text = std::move(text);

    // Set the state of the button
    this->state = State::DEFAULT;
}

raylib::Rectangle Button::bounds() {
    return rectangle;
}
