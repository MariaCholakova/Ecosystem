#include "Engine.h"

Engine::Engine(){}

void Engine::ReadEnvironmentData(){
    ReadSize();
    ReadWaterCoord(waterTerritories);
    ReadGrassCoord(plantTerritories, waterTerritories);
    ReadAlgaeCoord(plantTerritories, waterTerritories);
    ReadAnimalsData(vLH, vWH, vLC, vWC, waterTerritories);
    cout<<"Number land herbivores: "<<vLH.size()<<endl;
    cout<<"Number water herbivores: "<<vWH.size()<<endl;
    cout<<"Number land carnivores: "<<vLC.size()<<endl;
    cout<<"Number water herbivores: "<<vWC.size()<<endl;
    cout<<"Plant territories: "<<plantTerritories.size()<<endl;
}

void Engine::HandleRainfalls(){
    int numberAreas = rand()% 5 + 1;
    cout<<"Number rain areas: "<<numberAreas<<endl;
    cout<<"Coordinates of the rain territories: \n";
    if(!rainTerritories.empty()){
       rainTerritories.clear();
    }
    for (int i = 0; i < numberAreas; i++){
        rainTerritories.push_back(shared_ptr<RainArea> (new RainArea));
        cout<<rainTerritories[i]->GetUL().GetX()<<" "<<rainTerritories[i]->GetUL().GetY()<<" "<<
        rainTerritories[i]->GetBR().GetX()<< " "<<rainTerritories[i]->GetBR().GetY()<<endl;
    }
    for (int i = 0; i < plantTerritories.size(); i++){
        for (int j = 0; j < rainTerritories.size(); j++){
            if (plantTerritories[i]->OverlapWithRain(*rainTerritories[j])){
                plantTerritories[i]->WaterOverlappedArea(*rainTerritories[j]);
            }
        }
    }
}

herbVec Engine::ConcatenateHerbVectors(){
    herbVec commonHerbVector;
    for (int i = 0; i < vLH.size(); i++){
        commonHerbVector.push_back(vLH[i]);
    }
    for (int i = 0; i < vWH.size(); i++){
        commonHerbVector.push_back(vWH[i]);
    }
    return commonHerbVector;
}

void Engine::HerbTurns(){
    if (plantTerritories.empty()){
        cout<<"All plants are dead! Eco cataclism! \n";
    } else{
        for(int i = 0; i < vLH.size(); i++){
            cout<<"Land Herb N:"<<i+1<<endl;
            vLH[i]->FindTarget(plantTerritories);
            vLH[i]->Move();
            vLH[i]->Eat();
            vLH[i]->CheckLocation(waterTerritories);
            vLH[i]->GrowAge();
        }
         for(int i = 0; i < vWH.size(); i++){
            cout<<"Water Herb N: "<<i+1<<endl;
            vWH[i]->FindTarget(plantTerritories);
            vWH[i]->Move();
            vWH[i]->Eat();
            vWH[i]->CheckLocation(waterTerritories);
            vWH[i]->GrowAge();
        }
    }
}

void Engine::CarnTurns(){
    herbVec allVegans = ConcatenateHerbVectors();
    if (allVegans.empty()) {
        cout<<"All herbivores are dead! Eco cataclism! \n";
    } else {
        for(int i = 0; i < vLC.size(); i++){
            vLC[i]->FindTarget(allVegans);
            vLC[i]->Move();
            vLC[i]->Eat();
            vLC[i]->CheckLocation(waterTerritories);
            vLC[i]->GrowAge();
        }
         for(int i = 0; i < vWC.size(); i++){
            vWC[i]->FindTarget(allVegans);
            vWC[i]->Move();
            vWC[i]->Eat();
            vWC[i]->CheckLocation(waterTerritories);
            vWC[i]->GrowAge();
        }
    }
}


void Engine::HandleAnimalsTurns(){
    HerbTurns();
    CarnTurns();
}

void Engine::HandleHerbivoreMeeting(){
    lhVec babyLH;
    whVec babyWH;          //otherwise endless cycle happens, if baby's and parents' coordinates are the same
     for (int i = 0; i < vLH.size(); i++){
        for (int j = i + 1; j < vLH.size(); j++){
             if (vLH[i]->GetCoordinate() == vLH[j]->GetCoordinate() && vLH[i]->GetGender() != vLH[j]->GetGender()){
                vLH[i]->Copulate(*vLH[j], babyLH);
                break;
            }
        }
    }
    for (int i = 0; i < vLH.size(); i++){
        for (int j = 0; j < vWH.size(); j++){
            if (vLH[i]->GetCoordinate() == vWH[j]->GetCoordinate()&& vLH[i]->GetGender() != vWH[j]->GetGender()){
                vLH[i]->Copulate(*vWH[j], babyLH);
            }
        }
    }
    for (int k = 0; k < babyLH.size(); k++){
        vLH.push_back(babyLH[k]);
    }
    for (int i = 0; i < vWH.size(); i++){
        for (int j = i + 1; j < vWH.size(); j++){
            if (vWH[i]->GetCoordinate() == vWH[j]->GetCoordinate()&& vWH[i]->GetGender() != vWH[j]->GetGender()){
                vWH[i]->Copulate(*vWH[j], babyWH);
            }
        }
    }
    for (int k = 0; k < babyWH.size(); k++){
        vWH.push_back(babyWH[k]);
    }
}


void Engine::HandleCarnivoreMeeting(){
    cout<<"Handling carnivore meeting...\n";
    lcVec babyLC;
    wcVec babyWC;
     for (int i = 0; i < vLC.size(); i++){
        for (int j = i + 1; j < vLC.size(); j++){
            if (vLC[i]->GetCoordinate() == vLC[j]->GetCoordinate() ){
                if (vLC[i]->GetGender() != vLC[j]->GetGender()){
                    vLC[i]->Copulate(*vLC[j], babyLC);
                }
                if (vLC[i]->GetGender() == vLC[j]->GetGender()){
                    vLC[i]->Fight(*vLC[j]);
                }
            }
        }
     }
    for (int i = 0; i < vLC.size(); i++){
        for (int j = 0; j < vWC.size(); j++){
            if (vLC[i]->GetCoordinate() == vWC[j]->GetCoordinate()){
                if (vLC[i]->GetGender() != vWC[j]->GetGender()){
                    vLC[i]->Copulate(*vLC[j], babyLC);
                }
                if (vLC[i]->GetGender() == vWC[j]->GetGender()){
                    vLC[i]->Fight(*vWC[j]);
                }
            }
        }
    }
    for (int k = 0; k < babyLC.size(); k++){
        vLC.push_back(babyLC[k]);
    }
    for (int i = 0; i < vWC.size(); i++){
        for (int j = i + 1; j < vWC.size(); j++){
           if (vWC[i]->GetCoordinate() == vWC[j]->GetCoordinate()){
                if (vWC[i]->GetGender() != vWC[j]->GetGender()){
                    vWC[i]->Copulate(*vWC[j], babyWC);
                }
                if (vWC[i]->GetGender() == vWC[j]->GetGender()){
                    vWC[i]->Fight(*vWC[j]);
                }
            }
        }
    }
    for (int k = 0; k < babyWC.size(); k++){
        vWC.push_back(babyWC[k]);
    }
}

void Engine::EndOfTurn(){
    RemoveDeadAnimals(vLH);
    RemoveDeadAnimals(vWH);
    RemoveDeadAnimals(vLC);
    RemoveDeadAnimals(vWC);
}

bool Engine::AllAnimalsDead(){
    if (vLH.empty() && vWH.empty() && vLC.empty() &&  vWC.empty()){
        return true;
    } else {
        return false;
    }
}

