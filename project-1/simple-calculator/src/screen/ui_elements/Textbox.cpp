//
// Created by adam on 12/7/22.
//

#include "../../../include/screen/ui_elements/Textbox.h"

void Textbox::Render(bool isError) {
    rectangle.Draw(raylib::Color::Orange());
    if (isError) {
        raylib::DrawText(text, 20, 35, 20, raylib::Color::Red());
    } else {
        raylib::DrawText(text, 20, 35, 20, raylib::Color::Black());
    }
}

raylib::Rectangle Textbox::Bounds() {
    return rectangle;
}

Textbox::Textbox(std::string text) {
    // Create the bounding box
    rectangle = raylib::Rectangle(0, 0, 315, 90);

    // Set the current text
    this->text = std::move(text);

    // Set the state of the button
    state = DEFAULT;
}

Textbox::Textbox() = default;

std::string Textbox::Text() {
    return text;
}
