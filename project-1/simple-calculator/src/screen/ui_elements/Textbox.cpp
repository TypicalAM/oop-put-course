//
// Created by adam on 12/7/22.
//

#include "../../../include/screen/ui_elements/Textbox.h"
#include "../../../include/screen/Screen.h"
#include "../../../include/math/expressions/ExpressionParser.h"

void Textbox::Render(bool isError) {
    DrawRectangleRec(rectangle, BUTTON_NORMAL_COLOR);
    DrawText(text.c_str(), 20, 40, 1.5 * FONTSIZE, ((isError) ? RED : TEXT_COLOR));
}

Rectangle Textbox::Bounds() {
    return rectangle;
}


std::string Textbox::Text() {
    return text;
}

Textbox Textbox::Backspace() {
    if (text.length() == 0) return *this;
    if (text.length() == 1) return Textbox("0");

    std::string expressionText = text;
    expressionText.pop_back();
    return Textbox(expressionText);
}

Textbox Textbox::C() {
    return Textbox("0");
}

Textbox Textbox::EqualsSign() {
    return Textbox(ExpressionParser(text).RPN().Evaluate());
}

Textbox::Textbox(std::string text) {
    // Create the bounding box
    rectangle = Rectangle{0, 20, 315, 60};

    // Set the current text
    this->text = std::move(text);

    // Set the state of the button
    state = DEFAULT;
}

Textbox::Textbox() {}
