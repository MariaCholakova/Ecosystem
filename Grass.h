#ifndef GRASS_H
#define GRASS_H
#include "Plant.h"

class Grass: public Plant{
public:
    Grass(int x, int y, int lp);
    void TakeRain();
};

#endif // GRASS_H
