#include "WaterCarnivore.h"

 WaterCarnivore::WaterCarnivore(int x, int y, char gender, int age, int lifeExp, int stamina, int lifePoints, int food):
      Carnivore(x, y, gender, age, lifeExp, stamina, lifePoints, food){
            location = habitat::water;
      }

