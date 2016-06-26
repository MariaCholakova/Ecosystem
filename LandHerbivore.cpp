#include "LandHerbivore.h"

LandHerbivore::LandHerbivore(int x, int y, char gender, int age, int lifeExp, int stamina, int lifePoints, int food):
    Herbivore(x, y, gender, age, lifeExp, stamina, lifePoints, food){
     //   cout<<"creating land herb...\n";
        location = habitat::land;
    }



