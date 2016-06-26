#ifndef WATERAREA_H
#define WATERAREA_H
#include "Water.h"
#include "Exceptions.h"
#include <vector>
#include <memory>
using namespace std;

class WaterArea {
private:
    Water UL;
    Water BR;
public:
    WaterArea(int ULx, int ULy, int BRx, int BRy);
    Water GetUL() const;
    Water GetBR() const;
    int GetHeight() const;
    int GetWidth() const;
    bool HasThisCoordinate(const Object&);
    bool HasRightInput();

};

typedef vector <shared_ptr<WaterArea> > waterVec;

#endif // WATERAREA_H
