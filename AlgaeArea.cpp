#include "AlgaeArea.h"
#include <iostream>
using namespace std;


AlgaeArea::AlgaeArea(int ULx, int ULy, int BRx, int BRy, int capacity):
    PlantArea(ULx, ULy, BRx, BRy, capacity) {
        FillThePlantVector<Algae>();
    }

bool AlgaeArea::EntirelyInWater(const WaterArea& w){
    bool rightULx = this->GetUL().GetX() >= w.GetUL().GetX() && this->GetUL().GetX() <= w.GetBR().GetX();
    bool rightULy = this->GetUL().GetY() <= w.GetUL().GetY() && this->GetUL().GetY() >= w.GetBR().GetY();
    bool rightBRx = this->GetBR().GetX() >= w.GetUL().GetX() && this->GetBR().GetX() <= w.GetBR().GetX();
    bool rightBRy = this->GetBR().GetY() <= w.GetUL().GetY() && this->GetBR().GetY() >= w.GetBR().GetY();
    if (rightULx && rightULy && rightBRx && rightBRy) {
        return true;
    }
    else {
        throw AlgaeException();
    }
}
