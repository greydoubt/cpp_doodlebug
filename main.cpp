//  main.cpp
//  RandomGenerator.h
//  RandomGenerator.cpp
//  Organism.h
//  DoodleBug.h
//  DoodleBug.cpp
//  Ant.h
//  Ant.cpp
//  Grid.h
//  Grid.cpp

#include <iostream>
#include "Grid.h"

void displayGrid(const Grid<char>& grid) {
    for (int i = 0; i < grid.getHeight(); ++i) {
        for (int j = 0; j < grid.getWidth(); ++j) {
            std::cout << grid.get(i, j) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    Grid<char>& grid = Grid<char>::getInstance();

    // Initialize the grid with ants and doodlebugs
    grid.addAnt(1, 1);
    grid.addAnt(2, 3);
    grid.addDoodleBug(4, 2);
    grid.addDoodleBug(3, 4);

    // Display the initial grid
    displayGrid(grid);

    // Simulate the movement of organisms for 5 steps
    for (int step = 1; step <= 5; ++step) {
        std::cout << "Step: " << step << std::endl;

        // Move doodlebugs
        grid.moveDoodleBugs();
        // Move ants
        grid.moveAnts();

        // Display the grid after each step
        displayGrid(grid);
    }

    return 0;
}
