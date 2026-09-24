#include <iostream>

#include "Maze.h"
#include"raylib.h"

int main()
{
    // std::vector<std::vector<int>> twoDArray(4, std::vector<int>(4));

    Maze maze;

    maze.print();

    // "\n" v endl

    // InitWindow(600, 400, "Window title");
    //
    // while (!WindowShouldClose())
    // {
    //     BeginDrawing();
    //     ClearBackground(RAYWHITE);
    //     DrawText("Hello window", 100, 100, 200, LIGHTGRAY);
    //     EndDrawing();
    // }
    //
    // CloseWindow();
    //
    // std::cout << "Hello, World!" << std::endl;
    // return 0;
}
