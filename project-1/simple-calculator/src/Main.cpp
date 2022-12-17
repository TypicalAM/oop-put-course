#include "../include/screen/Screen.h"

int main() {
    InitWindow(315, 330, "Calculator in raylib!");
    SetTargetFPS(60);
    // TODO: Fix for relative paths
    Font mainFont = LoadFont("/home/adam/code/workspaces/clion/im-crying-rn/assets/product_sans.ttf");
    Screen mainScreen(mainFont);
    while (!WindowShouldClose()) {
        BeginDrawing();
        mainScreen.Update();
        mainScreen.Draw();
        EndDrawing();
    }
    return 0;
}