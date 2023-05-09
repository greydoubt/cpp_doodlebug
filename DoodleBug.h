#ifndef DOODLEBUG_H
#define DOODLEBUG_H

#include "Organism.h"

template<typename T>
class DoodleBug : public Organism<T> {
public:
    DoodleBug(int x, int y);
    void move() override;

private:
    int x_;
    int y_;
    int stepsSurvived_;
    int stepsSinceBreed_;
    int stepsSinceLastMeal_;

    void breed();
    void starve();
    bool eatAnt(int newX, int newY);
};

#endif // DOODLEBUG_H
