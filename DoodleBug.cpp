#include "DoodleBug.h"
#include "Grid.h"

template<typename T>
DoodleBug<T>::DoodleBug(int x, int y) : x_(x), y_(y), stepsSurvived_(0), stepsSinceBreed_(0), stepsSinceLastMeal_(0) {
    // DoodleBug constructor implementation
}

template<typename T>
void DoodleBug<T>::move() {
    Grid<T>& grid = Grid<T>::getInstance();
    RandomGenerator random;

    // Check if there is an adjacent ant to eat
    if (eatAnt(x_ - 1, y_)) { // Check up
        return;
    }
    if (eatAnt(x_ + 1, y_)) { // Check down
        return;
    }
    if (eatAnt(x_, y_ - 1)) { // Check left
        return;
    }
    if (eatAnt(x_, y_ + 1)) { // Check right
        return;
    }

    // If no ant to eat, move like an ant
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
        stepsSinceLastMeal_++;

        if (stepsSurvived_ >= 8 && stepsSinceBreed_ >= 8) {
            breed();
            stepsSinceBreed_ = 0;
        }

        if (stepsSinceLastMeal_ >= 3) {
            starve();
        }
    }
}

template<typename T>
bool DoodleBug<T>::eatAnt(int newX, int newY) {
    Grid<T>& grid = Grid<T>::getInstance();

    if (grid.isValidPosition(newX, newY) && grid.isAnt(newX, newY)) {
        grid.removeAnt(newX, newY);
        grid.moveOrganism(x_, y_, newX, newY);
        x_ = newX;
        y_ = newY;

        stepsSinceLastMeal_ = 0;

        return true;
    }

    return false;
}

template<typename T>
void DoodleBug<T>::breed() {
    Grid<T>& grid = Grid<T>::getInstance();
    RandomGenerator random;

    int direction = random
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
        grid.addDoodleBug(newX, newY);
    }
}

template<typename T>
void DoodleBug<T>::starve() {
    Grid<T>& grid = Grid<T>::getInstance();
    grid.removeDoodleBug(x_, y_);
}

// Explicit template instantiation
template class DoodleBug<int>;
