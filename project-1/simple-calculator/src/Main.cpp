#include "../include/screen/Screen.h"

int main() {
    InitWindow(315, 330, "My own calculator");
    SetTargetFPS(60);
    Screen mainScreen;
    while (!WindowShouldClose()) {
        BeginDrawing();
        mainScreen.Update();
        mainScreen.Draw();
        EndDrawing();
    }
    return 0;
}