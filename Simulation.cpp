// Jaden Heller
// 2328279
// jaheller@chapman.edu
// CPSC-350-01
// Assignment 3 - Game of Life

#include "Simulation.h"

Simulation::Simulation(){
    currentBoard = new ArrayBoard();
    configType = "";
    startDensity = 0; 

    //Make sure the user choses either F or R to represent how they want to configure the board
    while(configType != "F" && configType != "f" && configType != "R" && configType != "r"){
        configType = "";
        cout << "Press 'F' if you want to read a file as the input or 'R' if you wish to generate a random grid ";
        cin >> configType;
    }
    while(pauseType != "enter" && pauseType != "Enter" && pauseType != "none" && pauseType != "None"){
        cout << "Write 'enter' if you want to hit enter between generartions or write 'none' to have them load automatically: " << endl;
        cin >> pauseType;
    }

    if (configType == "R" || configType == "r"){
        initRandomBoard();
    }
    else{
        initBoardFromFile();
    }
}

Simulation::~Simulation(){
    delete currentBoard;
    delete nextBoard;
}

void Simulation::simNextGen(){
    int p = 0;

    while (p < 40){ //Didn't finish the method to detect when the board is repeating in time,
    //so have a limit of 40 boards before quitting
        currentBoard -> determineNextLife(); //determine the status (living or dead) each cell
        //will have in the next generation
        currentBoard -> printBoard();
        currentBoard -> fillNextBoard(); //Fill the nextGen board will cells based on the status 
        //calculated by determineNextLife() above
        bool unPause = false; 
        while (unPause == false){
            unPause = simPause(pauseType); //Make sure the unPausing conditions are met (hitting enter) 
            //if there are any before moving onto the next generation
        }
        currentBoard -> nextGenTocurrGen(); //Set all of the cells in the current board equal to the cells
        //that were calculated for the next generation
        cout << "  " << endl; //Add gap between generations
        p++;
    }  
}

bool Simulation::simPause(string pause){ //Handles the pasuong between generations
    if(pause == "none"){
        return true;
    }

    else{ //If pause == "enter"
        cout << "Press 'Enter' to continue..." << endl;
        cin.get(); //Wait for the user to hit enter
        return true;
    }

}

void Simulation::initRandomBoard(){ //If the user choses to generate a randomized board
    currentBoard -> createBoard(configType, 0, 0); //Passing the dimensions to a default of 0 as those
    //parameters aren't used when creating a randomly-filled board
    cout << "What would you like the initial density of cells to be (Enter a decimal number greater than 0 and less than or equal to 1): " << endl;
    cin >> startDensity;
    currentBoard -> randomGenBoard(startDensity);
    currentBoard -> fillBoard(currentBoard -> startingCellArray); //Populate the board based
    //off of the randomly-generated array of cells created by randomGenBoard() above
}

void Simulation::initBoardFromFile(){
    //Filestream
    fstream inputFile;
    cout << "Name of the file you want to configure a grid from: " << endl;
    cin >> fileName;

    int lineCounter = 0; //Counts which line number of the file fstream is on to seperate
    //The two numbers that represent the dimensions at the top from the supplied starting board
    int height;
    int width;

    inputFile.open(fileName, ios::in); //read from the supplied file
    if(inputFile.is_open()){
        string line; //String to hold each line from the supplied text file
        int gridArea;
        while(getline(inputFile, line)){
            if(lineCounter == 0){
                height = stoi(line);      
                cout << "width is therefor: " << height << endl;
            }
            else if (lineCounter == 1){
                width = stoi(line);
                cout << "height is therefor: " << width << endl;
                gridArea = width*height;
                break;
            }

            lineCounter++;
        }
        bool cellArray[gridArea];
        line = ""; //reset line to blank
        int cellArrayIndex = 0;
        
        while(getline(inputFile, line)){ //Translate the grid in the file into booleans that
        //will represent whether each cell is alive or dead
            for(int i = 0; i < line.length(); i++){
                if(line[i] == '-'){
                    cellArray[cellArrayIndex] = false; //-'s are dead
                    cellArrayIndex++;
                }
                else if(line [i] == 'X'){
                    cellArray[cellArrayIndex] = true; //X's are alive
                    cellArrayIndex++;
                }
            }
        }

        currentBoard -> createBoard(configType, height, width);
        currentBoard -> fillBoard(cellArray);
    }


}