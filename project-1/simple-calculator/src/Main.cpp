#include <iostream>
#include "raylib-cpp.hpp"
#include "../include/screen/Screen.h"
#include "../include/math/expressions/ExpressionParseError.h"
#include "../include/math/expressions/ExpressionParser.h"

int main() {
    raylib::Window window(315, 330, "Core window");
    SetTargetFPS(60);
    Screen mainScreen;
    while (!window.ShouldClose()) {
        window.BeginDrawing();
        window.ClearBackground(raylib::Color::RayWhite());
        mainScreen.Update();
        mainScreen.Draw();
        window.EndDrawing();
    }
    return 0;
}