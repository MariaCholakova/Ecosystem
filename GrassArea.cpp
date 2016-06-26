#include "GrassArea.h"
#include "algorithm"
#include <iostream>
using namespace std;

GrassArea::GrassArea(int ULx, int ULy, int BRx, int BRy, int capacity):
    PlantArea(ULx, ULy, BRx, BRy, capacity){
        FillThePlantVector<Grass>();
    }

bool GrassArea::OverlapWithWater(const WaterArea& w){
    int commonHeight = this->GetHeight() + w.GetHeight();
    int commonWidth = this->GetWidth() + w.GetWidth();
    int distanceY = max(this->GetUL().GetY(), w.GetUL().GetY()) - min(this->GetBR().GetY(), w.GetBR().GetY());
    int distanceX = max(this->GetBR().GetX(), w.GetBR().GetX()) - min(this->GetUL().GetX(), w.GetUL().GetX());
    if (commonHeight >= distanceY && commonWidth >= distanceX) {
        throw GrassException();
    } else {
        return false;
    }
}


