#include "../../../include/screen/ui_elements/Button.h"
#include "../../../include/screen/Screen.h"
#include "../../../include/screen/ui_elements/Textbox.h"

#include <utility>

Textbox Button::Click(Textbox textbox) {
  // Evaluate the expression
  if (text == "=")
    return textbox.EqualsSign();

  // Clear the screen
  if (text == "C")
    return textbox.C();

  // Backspace
  if (text == "BACK")
    return textbox.Backspace();

  // Check if we are on the first character
  if (textbox.Text().length() == 1 && textbox.Text()[0] == '0') {
    return Textbox(font, text);
  }

  // Perform the selected operation
  return Textbox(font, textbox.Text() + text);
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
  Vector2 textSize = MeasureTextEx(font, text.c_str(), FONTSIZE * 1.4, 0);
  float xPos = rectangle.x + rectangle.width / 2 - textSize.x / 2;
  float yPos = rectangle.y + rectangle.height / 2 - textSize.y / 2;

  // Draw the button text in the middle of the button
  DrawTextEx(font, text.c_str(), Vector2{xPos, yPos}, FONTSIZE * 1.4, 0,
             TEXT_COLOR);
}

Button::Button(Font font, float xPos, float yPos, bool isBig,
               std::string text) {
  // Set the text variable
  this->text = std::move(text);

  // Set the font
  this->font = font;

  // Create the bounding box
  rectangle = Rectangle{xPos, yPos,
                        ((isBig) ? BIG_BUTTON_WIDTH : SMALL_BUTTON_WIDTH), 32};

  // Set the state of the button
  state = State::DEFAULT;
}

Rectangle Button::bounds() { return rectangle; }
