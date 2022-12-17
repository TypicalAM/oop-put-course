#include "../State.h"
#include "raylib.h"
#include <string>

#ifndef TEXTBOX_H
#define TEXTBOX_H

class Textbox {
private:
  Rectangle rectangle{};
  std::string text;
  Font font{};

public:
  State state;
  std::string Text();
  Rectangle Bounds();
  Textbox Backspace();
  Textbox C();
  Textbox EqualsSign();
  Textbox();
  void Render(bool isError);
  explicit Textbox(Font font, std::string text);
};

#endif // TEXTBOX_H
