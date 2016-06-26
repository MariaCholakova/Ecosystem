#ifndef WATER_HERBIVORE_H
#define WATER_HERBIVORE_H
#include "Herbivore.h"


class WaterHerbivore: public Herbivore{
public:
    WaterHerbivore(int x, int y, char gender, int age, int lifeExp, int stamina, int lifePoints, int food);
};
typedef vector<shared_ptr<WaterHerbivore> > whVec;

#endif // WATER_HERBIVORE_H
