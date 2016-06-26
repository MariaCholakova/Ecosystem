#include "ReadFunctions.h"
#include "Exceptions.h"
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <iostream>


void ReadSize(){
     ifstream myfile("EcosystemFile.txt");
     string firstLine;
     if (myfile.is_open()){
        getline (myfile,firstLine);
     }
     firstLine.erase(0,5);
     istringstream iss (firstLine);
     vector <int> values(2);
     for (int i = 0; i < 2; i++){
        int val;
        iss >> val;
        values[i] = val;
     }
     Object::rows = values[0];
     Object::cols = values[1];
}

int ReadTurns(){
    ifstream myfile("EcosystemFile.txt");
    string secondLine;
    if (myfile.is_open()){
        for (int i = 0; i < 2; i++){
            getline(myfile, secondLine);
        }
     }
     secondLine.erase(0,6);
     istringstream iss(secondLine);
     int number;
     iss >> number;
     return number;
}

int ReadWaterAreas(){
    ifstream myfile("EcosystemFile.txt");
    string thirdLine;
    if (myfile.is_open()){
        for (int i = 0; i < 3; i++){
            getline(myfile, thirdLine);
        }
     }
     thirdLine.erase(0,11);
     istringstream iss(thirdLine);
     int number;
     iss >> number;
     return number;
}

void ReadWaterCoord(waterVec& wv){
     ifstream myfile("EcosystemFile.txt");
     int n = ReadWaterAreas();
     string line;
     vector <int> values(4);
     if (myfile.is_open()){
        for (int i = 0; i < n + 3; i++){
            getline(myfile, line);
            if (i > 2){
                for (int k = 0; k < line.size(); k++){
                    if (line[k] == ',') line[k] = ' ';
                }
                istringstream iss(line);
                for (int j = 0; j < 4; j++){
                    int val;
                    iss >> val;
                    values[j] = val;
                }
                shared_ptr<WaterArea> wa (new WaterArea(values[0], values[1], values[2], values[3]));
                try {
                   if (wa->HasRightInput()) wv.push_back(wa);
                }
                catch (AreaException& e){
                    cout<<e.what()<<endl;
                }
           }
        }
     }
     cout<<"Water areas: "<<wv.size()<<endl;
}

int ReadGrassAreas(){
    ifstream myfile("EcosystemFile.txt");
    int waterLines = ReadWaterAreas();
    string grassLine;
    if (myfile.is_open()){
        for (int i = 0; i < 4 + waterLines ; i++){
            getline(myfile, grassLine);
        }
     }
     grassLine.erase(0,6);
     istringstream iss(grassLine);
     int numberGrass;
     iss >> numberGrass;
     return numberGrass;
}

void ReadGrassCoord(plantVec& pv, waterVec& wv){
     ifstream myfile("EcosystemFile.txt");
     int waterLines = ReadWaterAreas();
     int grassLines = ReadGrassAreas();
     string line;
     vector <int> values(5);
     if (myfile.is_open()){
        for (int i = 0; i < waterLines + grassLines + 4; i++){
            getline(myfile, line);
            if (i > waterLines + 3){
                for (int k = 0; k < line.size(); k++){
                    if (line[k] == ',') line[k] = ' ';
                }
                istringstream iss(line);
                for (int j = 0; j < 5; j++){
                    int val;
                    iss >> val;
                    values[j] = val;
                }
                shared_ptr<GrassArea> ga (new GrassArea(values[0], values[1], values[2], values[3],values[4]));
                bool overlap = false;
                try {
                   if (ga->HasRightInput()){
                        for (int l = 0; l < wv.size(); l++){
                            if (ga->OverlapWithWater(*wv[l])){
                               overlap = true;
                               break;
                            }
                        }
                        if (!overlap) pv.push_back(ga);
                   }
                }
                catch (AreaException& e){
                    cout<<e.what()<<endl;
                }
                catch (GrassException& ge){
                    cout<<ge.what()<<endl;
                }
            }
        }
     }
}

int ReadAlgaeAreas(){
    ifstream myfile("EcosystemFile.txt");
    int waterLines = ReadWaterAreas();
    int grassLines = ReadGrassAreas();
    string algaeLine;
    if (myfile.is_open()){
        for (int i = 0; i < 5 + waterLines + grassLines ; i++){
            getline(myfile, algaeLine);
        }
     }
     algaeLine.erase(0,6);
     istringstream iss(algaeLine);
     int numberA;
     iss >> numberA;
     return numberA;
}

void ReadAlgaeCoord(plantVec& pv, waterVec& wv){
     ifstream myfile("EcosystemFile.txt");
     int waterLines = ReadWaterAreas();
     int grassLines = ReadGrassAreas();
     int algaeLines = ReadAlgaeAreas();
     string line;
     vector <int> values(5);
     if (myfile.is_open()){
        for (int i = 0; i < waterLines + grassLines + algaeLines + 5; i++){
            getline(myfile, line);
            if (i > waterLines + grassLines + 4){
                for (int k = 0; k < line.size(); k++){
                    if (line[k] == ',') line[k] = ' ';
                }
                istringstream iss(line);
                for (int j = 0; j < 5; j++){
                    int val;
                    iss >> val;
                    values[j] = val;
                }
                shared_ptr<AlgaeArea> a (new AlgaeArea(values[0], values[1], values[2], values[3],values[4]));
                bool entirelyIn = false;
                try {
                   if (a->HasRightInput()){
                        for (int l = 0; l < wv.size(); l++){
                            if (a->EntirelyInWater(*wv[l])){
                               entirelyIn = true;
                               break;
                            }
                        }
                        if (entirelyIn) pv.push_back(a);
                   }
                }
                catch (AreaException& e){
                    cout<<e.what()<<endl;
                }
                catch (AlgaeException& ae){
                    cout<<ae.what()<<endl;
                }
            }
        }
     }
}

int ReadAnimalsNumber(){
    ifstream myfile("EcosystemFile.txt");
    int waterLines = ReadWaterAreas();
    int grassLines = ReadGrassAreas();
    int algaeLines = ReadAlgaeAreas();
    string animalsLine;
    if (myfile.is_open()){
        for (int i = 0; i < 6 + waterLines + grassLines + algaeLines; i++){
            getline(myfile, animalsLine);
        }
     }
     animalsLine.erase(0,8);
     istringstream iss(animalsLine);
     int numberA;
     iss >> numberA;
     return numberA;
}

void ReadAnimalsData(lhVec& landHerbs, whVec& waterHerbs, lcVec& landCarns, wcVec& waterCarns, waterVec& wv){
     ifstream myfile("EcosystemFile.txt");
     int waterLines = ReadWaterAreas();
     int grassLines = ReadGrassAreas();
     int algaeLines = ReadAlgaeAreas();
     int animalsLines = ReadAnimalsNumber();
     string line;
     vector <int> values(7);
     char gender;
     if (myfile.is_open()){
        for (int i = 0; i < waterLines + grassLines + algaeLines + animalsLines + 6; i++){
            getline(myfile, line);
            if (i > waterLines + grassLines + algaeLines + 5){
                int found = line.find('|');
                string typeFeeding(line.begin()+ found +1, line.begin()+ found + 1 + 9);
                line.erase(found, 10);
                gender = line[found + 1];
                line.erase(found, 2);
                for (int k = 0; k < line.size(); k++){
                    if (line[k] == ',' || line[k]== '|') line[k] = ' ';
                }
                istringstream iss(line);
                for (int j = 0; j < 7; j++){
                    int val;
                    iss >> val;
                    values[j] = val;
                }
                if (typeFeeding == "herbivore"){
                    bool inWater = false;
                    shared_ptr<Herbivore> h (new Herbivore(values[0], values[1], gender, values[2], values[3], values[4], values[5], values[6]));
                    for(int m = 0; m < wv.size(); m++){
                        if (wv[m]->HasThisCoordinate(*h)){
                            inWater = true;
                            break;
                        }
                    }
                    if (inWater){
                        shared_ptr<WaterHerbivore> wh (new WaterHerbivore(values[0], values[1], gender, values[2], values[3], values[4], values[5], values[6]));
                        waterHerbs.push_back(wh);
                    } else {
                        shared_ptr<LandHerbivore> lh (new LandHerbivore(values[0], values[1], gender, values[2], values[3], values[4], values[5], values[6]));
                        landHerbs.push_back(lh);
                    }
                }
                else if(typeFeeding == "carnivore"){
                    bool inWater = false;
                    shared_ptr<Carnivore> c (new Carnivore(values[0], values[1], gender, values[2], values[3], values[4], values[5], values[6]));
                    for(int m = 0; m < wv.size(); m++){
                        if (wv[m]->HasThisCoordinate(*c)){
                            inWater = true;
                            break;
                        }
                    }
                    if (inWater){
                         shared_ptr<WaterCarnivore> wc (new WaterCarnivore(values[0], values[1], gender, values[2], values[3], values[4], values[5], values[6]));
                         waterCarns.push_back(wc);
                    }else{
                        shared_ptr<LandCarnivore> lc (new LandCarnivore(values[0], values[1], gender, values[2], values[3], values[4], values[5], values[6]));
                        landCarns.push_back(lc);
                    }
                }
            }
        }
    }
}

