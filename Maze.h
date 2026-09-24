//
// Created by Work on 9/24/2026.
//

#ifndef RAYLIBTEST_SEPT24_MAZE_H
#define RAYLIBTEST_SEPT24_MAZE_H
#include <vector>


class Maze
{
private:
    static constexpr int NUMBER_OF_ROWS = 10;
    static constexpr int NUMBER_OF_COLUMNS = 10;
    static constexpr int NUMBER_OF_WALLS = 30;  //this number should VARY with numberOfRows * numberOfCols

    std::vector<std::vector<char>> mazeData; //what is the default initialized value for a char? Is it ' '?

public:
    ///@brief Randomly generates a maze with character W indicating a Wall and also
    ///puts an 'S' at start position (top left) and an 'F' at bottom right
    Maze();

    void print() const;


    void solveMaze();

private:
    void randomlyFillMazeWithWalls();
};


#endif //RAYLIBTEST_SEPT24_MAZE_H
