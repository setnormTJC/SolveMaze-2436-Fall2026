#include <iostream>

#include"raylib.h"

int main()
{
    InitWindow(600, 400, "Window title");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello window", 100, 100, 200, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
