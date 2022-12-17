#include "../State.h"
#include "Textbox.h"
#include "raylib.h"

#ifndef BUTTON_H
#define BUTTON_H

class Button {
private:
  Rectangle rectangle{};
  std::string text;
  Font font;

public:
  State state;
  void Render();
  Rectangle bounds();
  Textbox Click(Textbox textbox);
  explicit Button(Font font, float xPos, float yPos, bool isBig,
                  std::string text);
};

#endif // BUTTON_H
