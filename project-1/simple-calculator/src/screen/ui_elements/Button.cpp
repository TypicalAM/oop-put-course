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

    // Clear the screen
    if (text == "C") return textbox.C();

	// Backspace
	if (text == "BACK") return textbox.Backspace();

	// Check if the input is numerical, if yes, add it to the output
	if (text.find_first_not_of(".0123456789") == std::string::npos) {
		return Textbox(textbox.Text() + text);
	}
	
	// Perform the selected operation
	return Textbox(textbox.Text() + text);
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
    DrawTextEx(font, text.c_str(), Vector2{static_cast<float>(xPos), static_cast<float>(yPos)}, FONTSIZE*1.2, 0, TEXT_COLOR);
}

Button::Button(Font font, float xPos, float yPos, bool isBig, std::string text) {
    // Set the text variable
    this->text = std::move(text);

    // Set the font
    this->font = font;

    // Create the bounding box
    rectangle = Rectangle{xPos, yPos, 51, ((isBig) ? BIG_BUTTON_HEIGHT : SMALL_BUTTON_HEIGHT)};

    // Set the state of the button
    state = State::DEFAULT;
}

Rectangle Button::bounds() {
    return rectangle;
}
