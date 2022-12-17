#ifndef SCREEN_H
#define SCREEN_H

#include "../math/expressions/ExpressionTokens.h"
#include "ui_elements/Button.h"
#include "ui_elements/Textbox.h"
#include <vector>

const float FONTSIZE = 16.0f;
const float SMALL_BUTTON_WIDTH = 51;
const float BIG_BUTTON_WIDTH = 112;

const Color TEXT_COLOR{255, 255, 255, 255};
const Color BACKGROUND_COLOR{34, 33, 49, 255};
const Color BUTTON_NORMAL_COLOR{68, 68, 82, 255};
const Color BUTTON_HOVERED_COLOR{100, 100, 114, 255};
const Color BUTTON_PRESSED_COLOR{120, 120, 134, 255};

class Screen {
private:
  std::vector<Button> buttons;
  Textbox textbox;
  bool uiEnabled;
  int uiCoolDown;
  ExpressionTokens expr;
  Font font;

public:
  void Update();
  void Draw();
  explicit Screen(Font font);
};

#endif // SCREEN_H
