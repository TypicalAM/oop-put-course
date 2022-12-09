//
// Created by adam on 12/7/22.
//

#include "../../../include/screen/ui_elements/Textbox.h"
#include "../../../include/screen/Screen.h"

void Textbox::Render(bool isError) {
    DrawRectangleRec(rectangle, ORANGE);
    DrawText(text.c_str(), 20, 35, 1.5 * fontSize, ((isError) ? RED : BLACK));
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
