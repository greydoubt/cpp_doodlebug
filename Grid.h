/*
Grid is a class that represents the grid where the organisms (Ants and Doodle-Bugs) reside. It contains member functions to populate the grid with ants and doodle-bugs, as well as to move the organisms. The grid is represented by a vector of unique pointers to the Organism base class.
*/

#ifndef GRID_H
#define GRID_H

#include <vector>
#include <memory>
#include "Ant.h"
#include "DoodleBug.h"

template<typename T>
class Grid {
public:
    Grid(int rows, int cols);
    void populateAnts(int numAnts);
    void populateDoodleBugs(int numDoodleBugs);
    void moveOrganisms();

private:
    int rows_;
    int cols_;
    std::vector<std::unique_ptr<Organism<T>>> grid_;
};

#endif // GRID_H
