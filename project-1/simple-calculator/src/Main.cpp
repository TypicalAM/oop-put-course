#include "../include/screen/Screen.h"
#include "../include/math/expressions/ExpressionParser.h"

int main() {
    //ExpressionParser tokens = ExpressionParser("(10+15)*2").RPN();
   // printf("%s\n", tokens.Evaluate().c_str());
 //   return 0;

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