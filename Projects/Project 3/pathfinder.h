//
// Created by bob on 11/23/18.
//

#ifndef SOLUTION_PATHFINDER_H
#define SOLUTION_PATHFINDER_H

#include <cstdint>

const int
        MAX_ROWS = 50,
        MAX_COLS = 50;

//
// these are constants to use in the maze cells
//

enum CellValues {
    WALL_UP    = 0x01,
    WALL_RIGHT = 0x02,
    WALL_DOWN  = 0x04,
    WALL_LEFT  = 0x08,
    VISITED    = 0x10,
    DEAD_END   = 0x20
};

//=============================================================================
// void printMaze(uint8_t maze[][MAX_COLS],int nR,int nC);
//  print the given maze
//
// Parameters
//  maze - MAX_ROWS x MAX_COLS character array containing maze information
//  nR   - number of rows in the maze
//  nC   - number of columns in the maze
//

void printMaze(uint8_t maze[][MAX_COLS],int nR,int nC);

#endif //SOLUTION_PATHFINDER_H
