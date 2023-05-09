#include "Ant.h"
#include "Grid.h"

template<typename T>
Ant<T>::Ant(int x, int y) : x_(x), y_(y), stepsSurvived_(0), stepsSinceBreed_(0) {
    // Ant constructor implementation
}

template<typename T>
void Ant<T>::move() {
    Grid<T>& grid = Grid<T>::getInstance();
    RandomGenerator random;

    int direction = random.generate(0, 3);
    int newX = x_;
    int newY = y_;

    switch (direction) {
        case 0: // Move up
            newX = x_ - 1;
            break;
        case 1: // Move down
            newX = x_ + 1;
            break;
        case 2: // Move left
            newY = y_ - 1;
            break;
        case 3: // Move right
            newY = y_ + 1;
            break;
        default:
            break;
    }

    if (grid.isValidPosition(newX, newY) && grid.isEmpty(newX, newY)) {
        grid.moveOrganism(x_, y_, newX, newY);
        x_ = newX;
        y_ = newY;

        // Check breed condition
        stepsSurvived_++;
        stepsSinceBreed_++;

        if (stepsSurvived_ >= 3 && stepsSinceBreed_ >= 3) {
            breed();
            stepsSinceBreed_ = 0;
        }
    }
}

template<typename T>
void Ant<T>::breed() {
    Grid<T>& grid = Grid<T>::getInstance();
    RandomGenerator random;

    int direction = random.generate(0, 3);
    int newX = x_;
    int newY = y_;

    switch (direction) {
        case 0: // Breed up
            newX = x_ - 1;
            break;
        case 1: // Breed down
            newX = x_ + 1;
            break;
        case 2: // Breed left
            newY = y_ - 1;
            break;
        case 3: // Breed right
            newY = y_ + 1;
            break;
        default:
            break;
    }

    if (grid.isValidPosition(newX, newY) && grid.isEmpty(newX, newY)) {
        grid.addAnt(newX, newY);
    }
}

// Explicit template instantiation
template class Ant<int>;
