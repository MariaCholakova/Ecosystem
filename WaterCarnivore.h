#ifndef WATER_CARNIVORE_H
#define WATER_CARNIVORE_H
#include "Carnivore.h"


class WaterCarnivore: public Carnivore{
public:
    WaterCarnivore(int x, int y, char gender, int age, int lifeExp, int stamina, int lifePoints, int food);

};
typedef vector<shared_ptr<WaterCarnivore> > wcVec;

#endif // WATER_CARNIVORE_H
