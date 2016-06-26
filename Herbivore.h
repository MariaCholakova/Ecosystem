#ifndef HERBIVORE_H
#define HERBIVORE_H
#include "Animal.h"
#include "PlantArea.h"

class Herbivore: public Animal{

public:
    Herbivore(int x, int y, char gender, int age, int lifeExp, int stamina, int lifePoints, int food);
    void FindTarget(plantVec& pv);
    void Eat();

};
typedef vector <shared_ptr<Herbivore> > herbVec;

#endif // HERBIVORE_H
