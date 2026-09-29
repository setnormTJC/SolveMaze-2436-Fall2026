#include <iostream>

#include "Maze.h"
#include"raylib.h"

int main()
{
    // std::vector<std::vector<int>> twoDArray(4, std::vector<int>(4));

    Maze maze;

    maze.print();

    maze.solveMaze();


    // "\n" v endl

    InitWindow(1000, 700, "Window title");

    while (!WindowShouldClose()) //has the user clicked x yet?
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("C", 100, 100, 200, LIGHTGRAY);
        DrawRectangle(0, 0, 100, 100, GREEN);
        EndDrawing();
    }

    CloseWindow();
    //
    // std::cout << "Hello, World!" << std::endl;
    // return 0;
}
