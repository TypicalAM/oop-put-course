//
// Created by adam on 12/6/22.
//

#include "Button.h"

#include <utility>

void Button::click() {
    printf("Do an action\n");
}

void Button::render() {
    // Draw the bounding rectangle
    bounds.Draw(raylib::Color::Magenta());

    // Calculate the xPos and yPos of the text, so that it can be in the middle
    int xPos = bounds.GetX() + bounds.GetWidth() / 2 - raylib::MeasureText(text, 16) / 2; // TODO: Define fontsize
    int yPos = bounds.GetY() + bounds.GetHeight() / 2 - 16 / 2;

    // Draw the button text in the middle of the button
    raylib::DrawText(text, xPos, yPos, 16, raylib::Color::Black());
}

Button::Button(float xPos, float yPos, bool isBig, std::string text) {
    // Create the bounding box
    if (isBig) {
        // TODO: PREDEFINE SMALL HEIGHT AND HIG HEIGHT
        this->bounds = raylib::Rectangle(xPos, yPos, 102, 64); // TODO: Define window sizes
    } else {
        this->bounds = raylib::Rectangle(xPos, yPos, 102, 134);
    }

    // Set the text variable
    this->text = std::move(text);

    // Set the state of the button
    this->state = State::DEFAULT;
}
