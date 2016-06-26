#ifndef ALGAE_H
#define ALGAE_H
#include "Plant.h"

class Algae: public Plant{
public:
    Algae(int x, int y, int lp);
    void TakeRain();
};

#endif // ALGAE_H
