#include "RandomGenerator.h"

RandomGenerator::RandomGenerator() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

int RandomGenerator::generate(int min, int max) const {
    return min + std::rand() % (max - min + 1);
}
