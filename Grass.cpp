#include "Grass.h"
#include <iostream>
using namespace std;

Grass::Grass(int x, int y, int lp):Plant(x,y,lp){}

void Grass::TakeRain(){
  //  cout<<"grass takes rain\n";
    this->lifePoints = maxPoints;
}
