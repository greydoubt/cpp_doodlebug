#ifndef ANT_H
#define ANT_H

#include "Organism.h"

template<typename T>
class Ant : public Organism<T> {
public:
    Ant(int x, int y);
    void move() override;

private:
    int x_;
    int y_;
    int stepsSurvived_;
    int stepsSinceBreed_;

    void breed();
};

#endif // ANT_H
