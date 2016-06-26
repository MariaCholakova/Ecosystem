#ifndef LAND_HERBIVORE_H
#define LAND_HERBIVORE_H
#include "Herbivore.h"


class LandHerbivore:public Herbivore{
public:
    LandHerbivore(int x, int y, char gender, int age, int lifeExp, int stamina, int lifePoints, int food);

};
typedef vector<shared_ptr<LandHerbivore> > lhVec;

#endif // LAND_HERBIVORE_H
