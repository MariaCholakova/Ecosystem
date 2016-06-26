#ifndef PLANT_H
#define PLANT_H
#include "Alive.h"

class Plant: public Alive{
public:
    Plant(int x, int y, int lp);
    virtual void TakeRain() = 0; //implement in classes grass and algae
};

#endif // PLANT_H
