#include "RainArea.h"
#include <iostream>
using namespace std;

RainArea::RainArea(){
    int ULx = rand()% (Object::cols*2);
    int ULy = rand()% (Object::rows*2)+1;   //we don't want to get 0, because BRy divides by ULy
    int BRx = rand()% (Object::cols*2 - ULx) + (ULx+1);
    int BRy = rand()% ULy;
    ULx -= Object::cols;
    ULy -= Object::rows;
    BRx -= Object::cols;
    BRy -= Object::rows;
    this->UL.SetX(ULx);
    this->UL.SetY(ULy);
    this->BR.SetX(BRx);
    this->BR.SetY(BRy);
    //this->UL = Rain::GenerateUL();
    //this->BR = Rain::GenerateBR(UL.GetX(), UL.GetY());
}

Rain RainArea::GetUL()const {
    return this->UL;
}

Rain RainArea::GetBR()const {
    return this->BR;
}

int RainArea::GetHeight() const{
    return this->UL.GetY() - this->BR.GetY();
}

int RainArea::GetWidth() const{
    return this->BR.GetX() - this->UL.GetX();
}
