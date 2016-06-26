#include "WaterArea.h"


WaterArea::WaterArea(int ULx, int ULy, int BRx, int BRy):
    UL(ULx, ULy),  BR(BRx, BRy) {}

Water WaterArea::GetUL() const{
    return this->UL;
}

Water WaterArea::GetBR() const{
    return this->BR;
}

int WaterArea::GetHeight() const{
    return this->UL.GetY() - this->BR.GetY();
}

int WaterArea::GetWidth() const{
    return this->BR.GetX() - this->UL.GetX();
}

bool WaterArea::HasThisCoordinate(const Object& point){
    return (point.GetX() >= this->UL.GetX() &&
            point.GetX() <= this->BR.GetX() &&
            point.GetY() <= this->UL.GetY() &&
            point.GetY() >= this->BR.GetY() );
}

bool WaterArea::HasRightInput(){
    bool rightULx = this->UL.GetX() >= (-Object::cols) && this->UL.GetX() <= Object::cols;
    bool rightULy = this->UL.GetY() <= Object::rows && this->UL.GetY() >= (-Object::rows);
    bool rightBRx = this->BR.GetX() >= (-Object::cols) && this->BR.GetX() <= Object::cols;
    bool rightBRy = this->BR.GetY() <= Object::rows && this->BR.GetY() >= (-Object::rows);
    if (rightBRx && rightBRy && rightULx && rightULy){
        return true;
    }
    else {
        throw AreaException();
    }
}

