#include "Algae.h"

Algae::Algae(int x, int y, int lp):Plant(x,y,lp){};

void Algae::TakeRain(){
//    cout<<"algae takes rain\n";
    this->lifePoints /= 2;
}
