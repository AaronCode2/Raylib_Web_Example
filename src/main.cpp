#include <raylib.h>
#include <emscripten/emscripten.h>

void UpdateDrawFrame() {

    BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

    EndDrawing();
}

int main() {

    InitWindow(1000, 600, "Basic Window!!");

    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);

    CloseWindow(); 
    return 0;
}