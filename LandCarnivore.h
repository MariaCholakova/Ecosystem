#ifndef LAND_CARNIVORE_H
#define LAND_CARNIVORE_H
#include "Carnivore.h"


class LandCarnivore:public Carnivore{
public:
    LandCarnivore(int x, int y, char gender, int age, int lifeExp, int stamina, int lifePoints, int food);

};
typedef vector<shared_ptr<LandCarnivore> > lcVec;

#endif // LAND_CARNIVORE_H
