#ifndef PLANTAREA_H
#define PLANTAREA_H
#include "Plant.h"
#include "RainArea.h"
#include "Exceptions.h"
#include <vector>
#include <memory>
using namespace std;

class PlantArea{
private:
    Alive UL;
    Alive BR;
    vector <shared_ptr<Plant> > plantPoints;
public:
    PlantArea(int ULx, int ULy, int BRx, int BRy, int capacity);
    template <typename T>
    void FillThePlantVector();
    Alive GetUL() const;
    Alive GetBR() const;
    shared_ptr<Alive> GetPlant(const Alive& al) const;
    int GetHeight() const;
    int GetWidth() const;
    bool OverlapWithRain(const RainArea&);
    void WaterOverlappedArea(const RainArea&);
    bool HasThisCoordinate(const Object&);
    bool HasRightInput();
    void ShowCapacity();
};

typedef vector<shared_ptr<PlantArea> > plantVec;

template <typename T>
void PlantArea::FillThePlantVector(){
    for (int i = UL.GetX(); i <= BR.GetX(); i++){
        for (int j = BR.GetY(); j <= UL.GetY(); j++){
                shared_ptr<T> p(new T(i,j,UL.GetLifePoints()));
                plantPoints.push_back(p);
        }
    }
}


#endif // PLANTAREA_H
