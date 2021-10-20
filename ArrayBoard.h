// Jaden Heller
// 2328279
// jaheller@chapman.edu
// CPSC-350-01
// Assignment 3 - Game of Life

//Class that handles the creating, filling, and changing the generations of the grid
#include <iostream>
#include "Cell.h"

using namespace std;


class ArrayBoard{

public:
Cell **board; //pointer to an array of pointers
Cell **nextBoard;
bool isBorderCell; //will help when switching game mode to dcetermine the behavior
//const string deadCell = "-";
bool *startingCellArray;


ArrayBoard();
~ArrayBoard();
void createBoard(string configTechnique, int row, int column);
void fillBoard(bool boolArray[]);
void randomGenBoard(float density);
void printBoard();
void determineNextLife();
void fillNextBoard();
void nextGenTocurrGen();
int numCol;
int numRow;


private:
Cell *cell;
int numStartCells;
int gridArea;

};