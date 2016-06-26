#ifndef GRASSAREA_H
#define GRASSAREA_H
#include "Grass.h"
#include "RainArea.h"
#include "WaterArea.h"
#include "PlantArea.h"


class GrassArea:public PlantArea{
public:
    GrassArea(int ULx, int ULy, int BRx, int BRy, int capacity);
    bool OverlapWithWater(const WaterArea& w);
};


#endif // GRASSAREA_H
