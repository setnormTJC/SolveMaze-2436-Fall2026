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

    randomlyFillMazeWithWalls(); //here I come to save the day! (Mighty Mouse)

    //put START position at top left:
    mazeData[0][0] = 'S'; //in mazeData[x][y], is x the row and y the column? Or vice versa?

    //put the end at the bottom right
    mazeData[NUMBER_OF_ROWS - 1][NUMBER_OF_COLUMNS - 1] = 'G'; //G as in "Goal"

    fillUpTheEmptySpots();
}

void Maze::print() const
{
    for (const auto& row : mazeData)
    {
        for (const auto& character : row)
        {
            if (character == 'S') //make it red (make it OBVIOUS) -> C as in "current pos"
            {
                makeTextRed();
            }

            else
            {
                resetTextColor();
            }

            std::cout << character << " "; //setwidth might be "mandatory" for making the maze "pretty
        }
        std::cout << std::endl;//move to the next row in the maze
    }
}

void Maze::solveMaze()
{
    //step 1 from pseudocode for solving maze screenshot
    std::stack<std::pair<int, int>> stackOfCoordinates;

    std::pair<int, int> startingCoordinates = {0, 0};
    stackOfCoordinates.push(startingCoordinates);

    //step 2 (mark start pos. as visited)
    mazeData[startingCoordinates.first][startingCoordinates.second]
        = 'V';

    std::pair<int, int> goalCoordinates =
    {
        NUMBER_OF_ROWS - 1, NUMBER_OF_COLUMNS - 1
    };


    //step 3
    while (!stackOfCoordinates.empty())
    {
        std::pair<int,int> currentCoordinates = stackOfCoordinates.top(); //step 3a

        if (currentCoordinates == goalCoordinates) //step 3b
        {
            std::cout << std::endl << "Solved the maze" << std::endl;
            break;
        }

        std::pair<int, int> unvisitedNeighborCoordinates = findAnUnvisitedNeighbor(currentCoordinates);


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

void Maze::fillUpTheEmptySpots()
{
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
}

void Maze::makeTextRed() const
{
    std::cout << "\033[31m";
}

void Maze::resetTextColor() const
{
    std::cout << "\033[0m";
}

std::pair<int, int> Maze::findAnUnvisitedNeighbor(const std::pair<int, int> &currentPosition)
{

}
