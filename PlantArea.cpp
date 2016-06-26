#include "PlantArea.h"
#include "algorithm"
#include <iostream>
using namespace std;

PlantArea::PlantArea(int ULx, int ULy, int BRx, int BRy, int capacity):
    UL(ULx, ULy,capacity),  BR(BRx, BRy,capacity) {}

Alive PlantArea::GetUL() const{
    return this->UL;
}

Alive PlantArea::GetBR() const{
    return this->BR;
}

shared_ptr<Alive> PlantArea::GetPlant(const Alive& al) const {
    for (int i = 0; i < this->plantPoints.size(); i++){
        if (plantPoints[i]->GetCoordinate() == al.GetCoordinate()){
            int counter = 0;
            int j = i;
            while (plantPoints[j]->CheckIfAlive() == false && counter != plantPoints.size()){
                counter++;
                if (j != plantPoints.size() - 1) j++;
                else j = 0;
            }
            return plantPoints[j];
        }
    }
}


bool PlantArea::HasThisCoordinate(const Object& point){
    return (point.GetX() >= this->UL.GetX() &&
            point.GetX() <= this->BR.GetX() &&
            point.GetY() <= this->UL.GetY() &&
            point.GetY() >= this->BR.GetY() );
}

int PlantArea::GetHeight() const{
    return this->UL.GetY() - this->BR.GetY();
}

int PlantArea::GetWidth() const{
    return this->BR.GetX() - this->UL.GetX();
}

bool PlantArea::OverlapWithRain(const RainArea& r){
    int commonHeight = this->GetHeight() + r.GetHeight();
    int commonWidth = this->GetWidth() + r.GetWidth();
    int distanceY = max(this->UL.GetY(), r.GetUL().GetY()) - min(this->BR.GetY(), r.GetBR().GetY()); //abs
    int distanceX = max(this->BR.GetX(), r.GetBR().GetX()) - min(this->UL.GetX(), r.GetUL().GetX());
    return (commonHeight > distanceY && commonWidth > distanceX) ;
}


void PlantArea::WaterOverlappedArea(const RainArea& r){
    int ULx, ULy, BRx, BRy;
    ULx = max(this->UL.GetX(), r.GetUL().GetX());
    ULy = min(this->UL.GetY(), r.GetUL().GetY());
    BRx = min(this->BR.GetX(), r.GetBR().GetX());
    BRy = max(this->BR.GetY(), r.GetBR().GetY());
    for (int k = 0; k < plantPoints.size(); k++){
        for (int i = ULx; i <= BRx; i++){
            for (int j = BRy; j <= ULy; j++ ){
                Alive plant(i, j, this->UL.GetLifePoints());
                if (plantPoints[k]->GetCoordinate() == plant.GetCoordinate()){
                    plantPoints[k]->TakeRain();
                }
            }
        }
   }
}


bool PlantArea::HasRightInput(){
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

void PlantArea::ShowCapacity(){
       cout<<"Capacity:\n";
        cout<<plantPoints.size()<<endl;
        for (int i = 0; i<plantPoints.size();i++){
            cout<<plantPoints[i]->GetX()<<" "<<plantPoints[i]->GetY()<<" ";
            cout<<plantPoints[i]->GetLifePoints()<<endl;
        }
}


