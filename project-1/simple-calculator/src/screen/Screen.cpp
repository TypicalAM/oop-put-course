#include "../../include/screen/Screen.h"
#include "../../include/math/expressions/ExpressionParseError.h"
#include "../../include/math/expressions/ExpressionTokens.h"

void Screen::Update() {
  // Update the state of the buttons
  for (auto &button : buttons) {
    // Check if the mouse is in the button
    if (CheckCollisionPointRec(GetMousePosition(), button.bounds())) {
      // Check if the left mouse button is down
      if (IsMouseButtonDown(0) && uiEnabled) {
        if (button.state == HOVERED) {
          try {
            textbox = button.Click(textbox);
          } catch (ExpressionParseError epe) {
            // Disable the UI if the textbox gives us an error
            uiEnabled = false;
            uiCoolDown = 45;
            textbox = Textbox(font, epe.what());
          }
        }
        button.state = PRESSED;
      } else {
        button.state = HOVERED;
      }
    } else {
      button.state = DEFAULT;
    }
  }

  // Update the state of the textbox
  textbox.state = (CheckCollisionPointRec(GetMousePosition(), textbox.Bounds()))
                      ? HOVERED
                      : DEFAULT;

  // Enable the UI if the cooldown has ended
  if (!uiEnabled && !uiCoolDown--) {
    uiEnabled = true;
    textbox = Textbox(font, "0");
  }
}

void Screen::Draw() {
  // Draw the background
  ClearBackground(BACKGROUND_COLOR);

  // Draw the UI elements on the screen
  for (auto button : buttons)
    button.Render();

  // Draw the textbox
  textbox.Render(!uiEnabled);
}

Screen::Screen(Font font) {
  // Initialize the screen variables
  const std::vector<std::string> buttonTexts = {
      "/", "*",   "-", "BACK", "C", "7", "8", "9", "+", "OR", "4", "5", "6",
      "%", "AND", "1", "2",    "3", "^", "(", "0", "0", ".",  "=", ")"};

  // Initialize all ui_elements and append them to the ui_elements vector
  int counter = 0;
  for (int rows = 0; rows < 5; rows++) {
    for (int cols = 0; cols < 5; cols++) {
      if (counter == 20) {
        buttons.emplace_back(font, 10 + cols * 61, 110 + rows * 42, true,
                             buttonTexts[counter]);
      } else if (counter == 21) {
        counter++;
        continue;
      } else {
        buttons.emplace_back(font, 10 + cols * 61, 110 + rows * 42, false,
                             buttonTexts[counter]);
      }
      counter++;
    }
  }

  // Enable the UI and the UI cooldown in case the user produces a parser error
  this->uiEnabled = true;
  this->uiCoolDown = 45;

  // Set the font
  this->font = font;

  // Create the textbox
  this->textbox = Textbox(font, "0");
}
