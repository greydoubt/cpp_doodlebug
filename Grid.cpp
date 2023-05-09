#include "Grid.h"
#include "RandomGenerator.h"

template<typename T>
Grid<T>::Grid(int rows, int cols) : rows_(rows), cols_(cols), grid_(rows * cols) {}

template<typename T>
void Grid<T>::populateAnts(int numAnts) {
    RandomGenerator random;
    for (int i = 0; i < numAnts; ++i) {
        int x = random.generate(0, rows_ - 1);
        int y = random.generate(0, cols_ - 1);
        grid_[x * cols_ + y] = std::make_unique<Ant<T>>(x, y);
    }
}

template<typename T>
void Grid<T>::populateDoodleBugs(int numDoodleBugs) {
    RandomGenerator random;
    for (int i = 0; i < numDoodleBugs; ++i) {
        int x = random.generate(0, rows_ - 1);
        int y = random.generate(0, cols_ - 1);
        grid_[x * cols_ + y] = std::make_unique<DoodleBug<T>>(x, y);
    }
}

template<typename T>
void Grid<T>::moveOrganisms() {
    for (auto& organism : grid_) {
        if (organism) {
            organism->move();
        }
    }
}

// Explicit template instantiation
template class Grid<int>;
