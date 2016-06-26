#ifndef ENGINE_H
#define ENGINE_H
#include "ReadFunctions.h"
#include "RainArea.h"
#include <stdlib.h>
#include <ctime>
#include <algorithm>

class Engine{
private:
    waterVec waterTerritories;
    plantVec plantTerritories;
    rainVec rainTerritories;
    lhVec vLH;
    whVec vWH;
    lcVec vLC;
    wcVec vWC;
    herbVec ConcatenateHerbVectors();
    void HerbTurns();
    void CarnTurns();

public:
     Engine();
     void ReadEnvironmentData();
     void HandleRainfalls();
     void HandleAnimalsTurns();
     void HandleHerbivoreMeeting();
     void HandleCarnivoreMeeting();
     template <typename T>
     void RemoveDeadAnimals(vector<shared_ptr<T> >& v);
     void EndOfTurn();
     bool AllAnimalsDead();
};


template <typename T>
void Engine::RemoveDeadAnimals(vector<shared_ptr<T> >& v){
    for (int i = 0; i < v.size(); i++){
        if(v[i]->CheckIfAlive() == false){
            v .erase(v.begin() + i);
        }
    }
}

#endif // ENGINE_H
