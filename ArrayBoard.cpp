// Jaden Heller
// 2328279
// jaheller@chapman.edu
// CPSC-350-01
// Assignment 3 - Game of Life


#include "ArrayBoard.h" 

ArrayBoard::ArrayBoard(){
}

ArrayBoard::~ArrayBoard(){

    for (int i = 0; i < numRow; i++){
        delete[] board[i];
        delete[] nextBoard[i];
    }
    delete[] board;
    delete nextBoard;
    cout << "Board deleted " << endl;
    delete cell;
    delete startingCellArray;
}

void ArrayBoard::createBoard(string configTechnique, int row = 0, int column = 0){
    //If the user choses to generate a randomized grid of cells...
    if(configTechnique == "R" || configTechnique == "r"){
        cout << "How many rows would you like? " << endl;
        cin >> numRow;

        cout << "How many coloms would you like? " << endl;
        cin >> numCol;
    }
    
    else{
        numRow = row;
        numCol = column;
    }

    board = new Cell*[numRow];

    for(int i = 0; i < numRow; i++){
        board[i] = new Cell[numCol];
    }
}

void ArrayBoard::randomGenBoard(float density){
    int cellsInConfig = 0;
    gridArea = (numRow*numCol);
    numStartCells = gridArea * density;

    bool randomCellArray[gridArea];
    for(int r = 0; r < gridArea; r++){
        randomCellArray[r] = false;
    }
    while(cellsInConfig < numStartCells){
        int randInt = rand() % (gridArea-1);
        cout << "Random number is: " << randInt << endl;
        //generate random number q
        if(randomCellArray[randInt] != true){
            randomCellArray[randInt] = true;
            cellsInConfig++;
        }
    }

    
    startingCellArray = new bool[gridArea];

    for(int z = 0; z < gridArea; z++){
        startingCellArray[z] = randomCellArray[z];
    }
}

void ArrayBoard::fillBoard(bool boolArray[]){
    int livingNeighbors;
    int boolCounter = 0;

    for (int i = 0; i < numRow; i++){
        for (int n = 0; n < numCol; n++){
            board[i][n] = Cell(i, n, boolArray[boolCounter]);
            boolCounter++;
        }
    }
}

void ArrayBoard::determineNextLife(){ //determine if this cell will be alive 
//next gen based on the status of the cells around it

    int numLivingNeighbors;

    //Iterate over all of the cells in the grid (now that they are populated)
    for (int i = 0; i < numRow; i++){
        for (int n = 0; n < numCol; n++){

            numLivingNeighbors = 0;

            board[i][n].listSurroundingCells(); //List out the position of the cells that 
            //surround this cell

            for (int p = 0; p < 8; p++){ //iterate over the 8 cells that could be surrounding this one
                int neighborCellRow = board[i][n].surrCellsPositons[p][0];
                int neighborCellColumn = board[i][n].surrCellsPositons[p][1];
                
                if (neighborCellRow >= 0 && neighborCellRow < numRow && neighborCellColumn >= 0 && neighborCellColumn < numCol){
                    //If each possible neighbor is an actual location on the grid (aka between 0 and the max row/column)
                    Cell neighborCell = board[neighborCellRow][neighborCellColumn];
                    //Then set neighborCell equal to the cell that is in that positions

                    if (neighborCell.isAlive){

                    numLivingNeighbors += 1;
                    }
                }                          
                  
            }

            if (numLivingNeighbors <= 1){
                board[i][n].willBeAlive = false;
            }
            else if (numLivingNeighbors == 2 && board[i][n].isAlive){
                board[i][n].willBeAlive = true;
            }
            else if (numLivingNeighbors == 3){ //Cell will be alive next gen regardless of if it's
            //curently alive or dead
                board[i][n].willBeAlive = true;
            }
            else{
                board[i][n].willBeAlive = false;
            }
        }
    }
}

void ArrayBoard::fillNextBoard(){
    bool livingInNextGrid;

    nextBoard = new Cell*[numRow];

    for(int i = 0; i < numRow; i++){
        nextBoard[i] = new Cell[numCol];
    }

    for(int a = 0; a < numRow; a++){
        for(int b = 0; b < numCol; b++){
            livingInNextGrid = board[a][b].willBeAlive; //Check if each cell will be alive or 
            //not next generation
            nextBoard[a][b] = Cell(a,b,livingInNextGrid); //Then fill the new board with cells that
            //reflect that information (the next gen board)
        }
    }

}

void ArrayBoard::printBoard(){
    string row;
    for(int r = 0; r < numRow; r++){//column
        for(int c = 0; c < numCol; c++){
            if(board[r][c].isAlive){
                row += "X";
            }
            else{
                row += "-";
            }
        }
        cout << row << endl;
        row = "";
    }
}

void ArrayBoard::nextGenTocurrGen(){

    for(int a = 0; a < numRow; a++){
        for(int b = 0; b < numCol; b++){
            board[a][b] = nextBoard[a][b];
        }
    }

}