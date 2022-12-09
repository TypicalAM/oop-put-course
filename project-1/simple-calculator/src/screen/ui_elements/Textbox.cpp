//
// Created by adam on 12/7/22.
//

#include "../../../include/screen/ui_elements/Textbox.h"

void Textbox::Render(bool isError) {
    DrawRectangleRec(rectangle, ORANGE);
    if (isError) {
        DrawText(text.c_str(), 20, 35, 20, RED);
    } else {
        DrawText(text.c_str(), 20, 35, 20, BLACK);
    }
}

Rectangle Textbox::Bounds() {
    return rectangle;
}

Textbox::Textbox(std::string text) {
    // Create the bounding box
    rectangle = Rectangle{0, 0, 315, 90};

    // Set the current text
    this->text = std::move(text);

    // Set the state of the button
    state = DEFAULT;
}

std::string Textbox::Text() {
    return text;
}

Textbox::Textbox() {}
