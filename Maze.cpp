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

    //hard-coded walls so that we're looking at the same maze during testing
    // mazeData[0][2] = 'W';
    // mazeData[0][6] = 'W';
    // mazeData[0][8] = 'W';
    // mazeData[1][9] = 'W';
    // mazeData[1][2] = 'W';
    // mazeData[1][5] = 'W';
    // mazeData[4][4] = 'W';
    // mazeData[4][5] = 'W';
    // mazeData[5][6] = 'W';
    // mazeData[7][8] = 'W';

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
            if (character == 'C') //make it red (make it OBVIOUS) -> C as in "current pos"
            {
                makeTextRed();
            }

            else
            {
                makeTextDefaultColor();
            }

            std::cout << character << " "; //setwidth might be "mandatory" for making the maze "pretty
        }
        std::cout << std::endl;//move to the next row in the maze
    }

    std::cout << std::endl;
}

void Maze::solveMaze()
{
    bool mazeSolved = false;

    //step 1 from pseudocode for solving maze screenshot
    std::stack<std::pair<int, int>> stackOfCoordinates;

    std::pair<int, int> startingCoordinates = {0, 0};
    //hardcoded to 0, 0 (be wary of this)
    stackOfCoordinates.push(startingCoordinates);

    //step 2 (mark start pos. as visited)
    mazeData[startingCoordinates.first][startingCoordinates.second]
        = 'V';

    std::pair<int, int> goalCoordinates =
    {
        NUMBER_OF_ROWS - 1, NUMBER_OF_COLUMNS - 1
    };

    //step 3
    auto outOfBoundsCoordinates = std::pair<int, int>(-1, -1);

    while (!stackOfCoordinates.empty())
    {
        std::pair<int,int> currentCoordinates = stackOfCoordinates.top(); //step 3a

        if (currentCoordinates == goalCoordinates) //step 3b
        {
            std::cout << std::endl << "Solved the maze" << std::endl;
            mazeSolved = true;
            break; //exit the while loop
        }

        std::pair<int, int> unvisitedNeighborCoordinates
            = findAnUnvisitedNeighbor(currentCoordinates);

        //step 3d
        if (unvisitedNeighborCoordinates != outOfBoundsCoordinates) //constructor for pair that makes {-1, -1}
        {
            mazeData[unvisitedNeighborCoordinates.first][unvisitedNeighborCoordinates.second]
                = 'C'; //update current position

            print();
            // std::cout << std::endl;
            std::system("pause");
            // std::system("cls");

            //update the stack of directions
            stackOfCoordinates.push(unvisitedNeighborCoordinates);

            mazeData[unvisitedNeighborCoordinates.first][unvisitedNeighborCoordinates.second]
                 = 'V'; //mark as visited
        }

        else //no suitable neighbor found - dead end
        {
            makeTextRed();
            std::cout << "DEAD END HIT - BACKTRACKING (popping the stack of directions)" << std::endl;
            makeTextDefaultColor();

            stackOfCoordinates.pop(); //"backtrack"

            //mark the dead end as visited so we don't revisit it
            mazeData[currentCoordinates.first][currentCoordinates.second] = 'V';

            //mark the current position based on the updated top of the stack:
            mazeData[stackOfCoordinates.top().first][stackOfCoordinates.top().second] = 'C';

            print();


            // mazeData[unvisitedNeighborCoordinates.first][unvisitedNeighborCoordinates.second]
            //     = '_';
        }
    }//end while

    if (!mazeSolved)
    {
        std::cout << "No solution was possible" << std::endl;
    }

    else
    {
        std::cout << "Maze solved" << std::endl;
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

void Maze::makeTextDefaultColor() const
{
    std::cout << "\033[0m";
}

std::pair<int, int> Maze::findAnUnvisitedNeighbor(const std::pair<int, int> &currentPosition)
{
    //where to look first? up, down, left, or right?
    //just go in up, down, left, right order (arbitrarily)

    std::pair<int, int> up = {currentPosition.first - 1, currentPosition.second};
    std::pair<int, int> down = {currentPosition.first + 1, currentPosition.second};
    std::pair<int, int> left = {currentPosition.first, currentPosition.second - 1};
    std::pair<int, int> right = {currentPosition.first, currentPosition.second + 1};

    if (isInBounds(up)) //only check neighbor's contents if in bounds!
    {
        if (isAWallOrHasBeenVisited(up) == false)
        {
            return up;
        }
    }
    if (isInBounds(down))
    {
        if (isAWallOrHasBeenVisited(down) == false)
        {
            return down;
        }
    }
    if (isInBounds(left))
    {
        if (isAWallOrHasBeenVisited(left) == false)
        {
            return left;
        }
    }

    if (isInBounds(right))
    {
        if (isAWallOrHasBeenVisited(right) == false)
        {
            return right;
        }
    }

    return {-1, -1}; //no neighbor found
    //(dead end has been reached - up, down, left, right all contain walls or have already been visited)
}

bool Maze::isInBounds(const std::pair<int, int> &position) const
{
    if (position.first < 0 || position.first > NUMBER_OF_ROWS - 1)
    {
        return false;
    }

    if (position.second < 0 || position.second > NUMBER_OF_COLUMNS - 1)
    {
        return false;
    }

    return true;
}

bool Maze::isAWallOrHasBeenVisited(const std::pair<int, int> &position) const
{
    char mazeValueAtPosition = mazeData[position.first][position.second];

    if (mazeValueAtPosition != 'W'
        &&
        mazeValueAtPosition != 'V')
    {
        return false;
    }

    return true;
}
