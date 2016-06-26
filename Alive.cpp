#include "Alive.h"
#include <iostream>


Alive::Alive(int x, int y, int lp):Object(x,y), lifePoints{lp}, maxPoints{lp}, isAlive{true} {}

void Alive::DecreaseLP(int amount){
    this->lifePoints -= amount;
}

int Alive::GetLifePoints() const{
    return this->lifePoints;
}

bool Alive::CheckIfAlive(){
    if (this->lifePoints <= 0){
        cout<<"This organism is dead : "<<GetX()<<","<<GetY()<<endl;
        isAlive = false;
    }
    return isAlive;
}

int Alive::GetManhattanDistance (const Alive& other) const {
    return abs(this->GetX()-other.GetX()) + abs(this->GetY()-other.GetY());
}
