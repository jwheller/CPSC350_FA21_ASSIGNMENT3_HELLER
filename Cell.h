// Jaden Heller
// 2328279
// jaheller@chapman.edu
// CPSC-350-01
// Assignment 3 - Game of Life


//Class that defines and calculates the current status and future status of each cell
#include <iostream>

using namespace std;

class Cell{
public:
Cell();
Cell(int row, int column, bool living); //Overload constructor with parameters for the cell's
//position on the grid and if it's living or dead
~Cell();
string generateCell();
bool isAlive;
bool willBeAlive; //if the cell will be alive next genration
void listSurroundingCells();
int surrCellsPositons[8][2]; //An array to hold the position (X and Y) of the 8 (maximum) cells that
//can surround any given cell 

private:
int yPosition;
int xPosition;
};
