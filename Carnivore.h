#ifndef CARNIVORE_H
#define CARNIVORE_H
#include "Herbivore.h"

class Carnivore: public Animal{
private:
    int GetFood() const;
public:
    Carnivore(int x, int y, char gender, int age, int lifeExp, int stamina, int lifePoints, int food);
    void FindTarget(const herbVec& vegans);
    void Eat();
    void Fight(Carnivore& other);

};


#endif // CARNIVORE_H
