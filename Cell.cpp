// Jaden Heller
// 2328279
// jaheller@chapman.edu
// CPSC-350-01
// Assignment 3 - Game of Life

#include "Cell.h"

Cell::Cell(){

}

Cell::Cell(int row, int column, bool living){
    yPosition = row;
    xPosition = column;
    isAlive = living; 
}

Cell::~Cell(){

}

void Cell::listSurroundingCells(){
    int surrCount = 0; //Counter to help iterate over each of the 8 squares that surround any non-border cell
    int surrCell[2]; //An array that will hold the x and y position of each of the cells that surround the given cell

    for(int y = -1; y <= 1; y++){
        for(int x = -1; x <= 1; x++){ //List all 9 positions surrounding cells can be relative to a given cell
            if(y == 0 && x == 0){ //Both cordinates + 0 is just the cell's position, so skip it (there for it's only 8 positions)
                continue;
            }
            else{
                surrCell[0] = yPosition + y; //The absolute y-position of a surrounding cell is its relative position from above plus
                //the absolute position of the given cell
                surrCell[1] = xPosition + x; //same goes for x

                surrCellsPositons[surrCount][0] = surrCell[0]; //add the absoulte y position to the array of surrounding cell positions
                surrCellsPositons[surrCount][1] = surrCell[1]; //same for the x

                surrCount += 1; //Iterate over all the 8 cells, so each can be added to the array above
            }
        }

    }

}