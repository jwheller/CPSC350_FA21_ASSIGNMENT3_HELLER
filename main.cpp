// Jaden Heller
// 2328279
// jaheller@chapman.edu
// CPSC-350-01
// Assignment 3 - Game of Life

#include <iostream>
#include "Simulation.h"

int main(int argc, char** argv){

    Simulation *sim = new Simulation();
    sim -> simNextGen(); 

    delete sim;
    return 0;
}