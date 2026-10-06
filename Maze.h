//
// Created by Work on 9/24/2026.
//

#ifndef RAYLIBTEST_SEPT24_MAZE_H
#define RAYLIBTEST_SEPT24_MAZE_H
#include <vector>

// enum MazeSymbols
// {
//     WALL = 'W'
//     EMPTY_SPOT = '_'
// };

class Maze
{
private:
    static constexpr int NUMBER_OF_ROWS = 10;
    static constexpr int NUMBER_OF_COLUMNS = 10;
    static constexpr int NUMBER_OF_WALLS = 30;  //this number should VARY with numberOfRows * numberOfCols

    // static constexpr char emptySpot = '_'; //use this if you like

    //the initial dims: 0 x 0
    std::vector<std::vector<char>> mazeData; //what is the default initialized value for a char? Is it ' '?

public:
    ///@brief Randomly generates a maze with character W indicating a Wall and also
    ///puts an 'S' at start position (top left) and a 'G' (goal) at bottom right
    Maze();

    void print() const;

    ///@brief AKA: "traverse" maze (traversal algos are fascinating)
    void solveMaze();

private:
    void randomlyFillMazeWithWalls();
    void fillUpTheEmptySpots();

    void makeTextRed() const; //const because this method won't modify the state of the maze
    void makeTextDefaultColor() const;

    ///@brief returns the coordinates of the (first-encountered) neighbor<br>
    ///returns {-1, -1} if an unvisited, "nonwall" neighbor does NOT exist
    std::pair<int, int> findAnUnvisitedNeighbor(const std::pair<int, int>& currentPosition);

    bool isInBounds(const std::pair<int, int>& position) const;

    bool isAWallOrHasBeenVisited(const std::pair<int, int>& position) const;

};


#endif //RAYLIBTEST_SEPT24_MAZE_H
