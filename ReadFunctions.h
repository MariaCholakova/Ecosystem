#ifndef READ_FUNCTIONS_H
#define READ_FUNCTIONS_H
#include "Object.h"
#include "WaterArea.h"
#include "GrassArea.h"
#include "AlgaeArea.h"
#include "LandHerbivore.h"
#include "WaterHerbivore.h"
#include "LandCarnivore.h"
#include "WaterCarnivore.h"

using namespace std;

void ReadSize();
int ReadTurns();
int ReadWaterAreas();
void ReadWaterCoord(waterVec& wv);
int ReadGrassAreas();
void ReadGrassCoord(plantVec& pv, waterVec& wv);
int ReadAlgaeAreas();
void ReadAlgaeCoord(plantVec& pv, waterVec& wv);
int ReadAnimalsNumber();
void ReadAnimalsData(lhVec&, whVec&, lcVec&, wcVec&, waterVec& );

#endif // READ_FUNCTIONS_H
