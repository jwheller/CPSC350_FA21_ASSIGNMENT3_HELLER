// Jaden Heller
// 2328279
// jaheller@chapman.edu
// CPSC-350-01
// Assignment 3 - Game of Life


//Class that combines the Cell and ArrayBoard classes and handles the simulation
#include <iostream>
#include "ArrayBoard.h"
#include <fstream> //For reading a game board file
#include <string> //For reading the game file line-by-line using string's getLine() method


using namespace std;

class Simulation{
    public:
    Simulation();
    ~Simulation();
    string configType; //The method the user choses to configurate their board (from a file
    //or randomized)
    ArrayBoard *currentBoard; //define the current board (pointer)
    ArrayBoard *nextBoard;
    void simNextGen();
    void initRandomBoard();
    void initBoardFromFile();

    private:
    float startDensity;
    string fileName;
    string pauseType; //How the user would prefer pauses to occur between generations
    //(either by hitting enter or automatic)
    bool simPause(string pause);
};