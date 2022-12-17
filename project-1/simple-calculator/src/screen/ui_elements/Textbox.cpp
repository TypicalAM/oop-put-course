#include "../../../include/screen/ui_elements/Textbox.h"
#include "../../../include/math/expressions/ExpressionParser.h"
#include "../../../include/screen/Screen.h"

void Textbox::Render(bool isError) {
  DrawRectangleRec(rectangle, BUTTON_NORMAL_COLOR);
  DrawTextEx(font, text.c_str(), Vector2{20, 35}, 2 * FONTSIZE, 2,
             ((isError) ? RED : TEXT_COLOR));
}

Rectangle Textbox::Bounds() { return rectangle; }

std::string Textbox::Text() { return text; }

Textbox Textbox::Backspace() {
  if (text.length() == 0)
    return *this;
  if (text.length() == 1)
    return Textbox(font, "0");

  std::string expressionText = text;
  switch (text[text.length() - 1]) {
  case 'D':
    // AND
    expressionText.pop_back();
    expressionText.pop_back();
    expressionText.pop_back();
    break;
  case 'R':
    // OR
    expressionText.pop_back();
    expressionText.pop_back();
    break;
  default:
    // Default backspace
    expressionText.pop_back();
    break;
  }
  return Textbox(font, expressionText);
}

Textbox Textbox::C() { return Textbox(font, "0"); }

Textbox Textbox::EqualsSign() {
  return Textbox(font, ExpressionParser(text).RPN().Evaluate());
}

Textbox::Textbox(Font font, std::string text) {
  // Set the current text
  this->text = std::move(text);

  // Set the font
  this->font = font;

  // Create the bounding box
  rectangle = Rectangle{0, 20, 315, 60};

  // Set the state of the button
  state = DEFAULT;
}

Textbox::Textbox() = default;
