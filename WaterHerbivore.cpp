#include "WaterHerbivore.h"

 WaterHerbivore::WaterHerbivore(int x, int y, char gender, int age, int lifeExp, int stamina, int lifePoints, int food):
      Herbivore(x, y, gender, age, lifeExp, stamina, lifePoints, food){
            location = habitat::water;
      }
