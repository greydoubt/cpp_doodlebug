#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <cstdlib>
#include <ctime>

class RandomGenerator {
public:
    RandomGenerator();
    int generate(int min, int max) const;
};

#endif // RANDOMGENERATOR_H
