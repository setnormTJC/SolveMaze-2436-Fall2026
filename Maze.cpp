//
// Created by Work on 9/24/2026.
//

#include "Maze.h"

#include <iostream>
#include<random>
#include <stack>

Maze::Maze()
{
    mazeData.resize(NUMBER_OF_COLUMNS); //initial maze dims: 0 x 0
    for (int i = 0; i < NUMBER_OF_COLUMNS; ++i)
    {
        mazeData.at(i).resize(NUMBER_OF_ROWS);
    }

    randomlyFillMazeWithWalls();

    //put START position at top left:
    mazeData[0][0] = 'S'; //in mazeData[x][y], is x the row and y the column? Or vice versa?

    //put the end at the bottom right
    mazeData[NUMBER_OF_ROWS - 1][NUMBER_OF_COLUMNS - 1] = 'F';

    for (int row = 0; row < NUMBER_OF_ROWS; ++row)
    {
        for (int col = 0; col < NUMBER_OF_COLUMNS; ++col)
        {
            if (mazeData[row][col] == 0)
            {
                // int a = 123;
                mazeData[row][col] = '_';
            }
        }
    }


    // mazeData[0][1] = 'X';
    // mazeData[0][2] = 'Y';
    // mazeData[0][3] = 'Z';





    // maze.resize()
}

void Maze::print() const
{
    for (const auto& row : mazeData)
    {
        for (const auto& character : row)
        {
            std::cout << character << " "; //setwidth might be "mandatory" for making the maze "pretty"
        }
        std::cout << "\n";//move to the next row in the maze
    }
}

void Maze::solveMaze()
{
    // std::pair<int, int> pairExample = {11, 232};
    //
    // cout << pairExample.first

    std::stack<std::pair<int, int>> stackOfCoordinates;

    std::pair<int, int> startingCoordinates = {0, 0};
    stackOfCoordinates.push(startingCoordinates);

    mazeData[startingCoordinates.first][startingCoordinates.second] = 'V';

    while (!stackOfCoordinates.empty())
    {
        auto topItem = stackOfCoordinates.top();

        char mazeContentsAtTopCoordinate =
            mazeData[topItem.first][topItem.second];

        int a = 123;

        //if (topItem == )
    }
    

}

void Maze::randomlyFillMazeWithWalls()
{
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> distribution(0, NUMBER_OF_COLUMNS - 1);

    //put NUMBER_OF_WALLS walls in the maze at random positions
    for (int i = 0; i < NUMBER_OF_WALLS; ++i)
    {
        int randomRow = distribution(rng);
        int randomCol = distribution(rng);

        mazeData[randomRow][randomCol] = 'W';
    }
}
