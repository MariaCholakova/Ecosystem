#ifndef ALGAEAREA_H
#define ALGAEAREA_H
#include "Algae.h"
#include "RainArea.h"
#include "WaterArea.h"
#include "PlantArea.h"


class AlgaeArea:public PlantArea{
public:
    AlgaeArea(int ULx, int ULy, int BRx, int BRy, int capacity);
    bool EntirelyInWater(const WaterArea&);
};


#endif // ALGAEAREA_H
