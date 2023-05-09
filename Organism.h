/*
Organism is an abstract base class representing the common behavior of organisms in the Doodle-Bug problem. It declares a pure virtual function move() which needs to be implemented by derived classes (Ant and DoodleBug). The class is templated, allowing flexibility in the type of data associated with each organism.


*/

#ifndef ORGANISM_H
#define ORGANISM_H

template<typename T>
class Organism {
public:
    virtual ~Organism() {}
    virtual void move() = 0;
    virtual void breed() = 0;
    virtual void starve() {}
};

#endif // ORGANISM_H
