#include <iostream>

#include "Maze.h"
#include"raylib.h"

int main()
{
    std::cout << "\033[31m" << "Is this red?" << std::endl; //endl does a "flush" (ANSI code)
    std::cout << "\033[0m" << "Is this back to the normal color?" << std::endl;


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
