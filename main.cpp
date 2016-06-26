#include <iostream>
#include "Engine.h"
#include <stdlib.h>
#include <ctime>

using namespace std;


int main()
{
    int turns = ReadTurns();
    cout<<turns<<endl;
    Engine eng;
    eng.ReadEnvironmentData();
    for (int i = 0; i < turns; i++){
        if (eng.AllAnimalsDead()){
            cout<<"all animals dead\n";
            break;
        }
        else {
            cout<<"\t\t\t\t\t TURN "<<i+1<<endl;
            eng.HandleRainfalls();
            eng.HandleAnimalsTurns();
            eng.HandleHerbivoreMeeting();
            eng.HandleCarnivoreMeeting();
            eng.EndOfTurn();
        }
    }
    return 0;
}



