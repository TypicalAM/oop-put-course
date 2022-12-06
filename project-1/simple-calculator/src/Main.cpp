#include "raylib-cpp.hpp"
#include "screen/buttons/Button.h"

int main() {
    raylib::Window window(800, 600, "Core window");
    SetTargetFPS(60);
    Button button(0.0, 0.0, true, "test");
    while (!window.ShouldClose()) {
        window.BeginDrawing();
        window.ClearBackground(raylib::Color::RayWhite());
        button.render();
        window.EndDrawing();
    }
    return 0;
}