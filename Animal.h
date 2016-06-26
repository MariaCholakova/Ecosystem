#ifndef ANIMAL_H
#define ANIMAL_H
#include "Alive.h"
#include "WaterArea.h"
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <memory>

using namespace std;
enum class habitat{land , water};

class Animal:public Alive{

public:
    Animal(int x, int y, char gender, int age, int lifeExp, int st, int lifePoints, int food);
    void Move();
    virtual void Eat() = 0;
    char GetGender() const;
    void CheckLocation(waterVec& wv);
    void GrowAge();
    bool CheckIfAlive();
    template <typename T>
    void Copulate(const Animal& other, vector<shared_ptr<T> >& v);

protected:
    int age;
    int lifeExp;
    int food;
    int stamina;
    char gender;
    habitat location;
    shared_ptr<Alive> target;

};

template <typename T>
    void Animal::Copulate(const Animal& other, vector<shared_ptr<T> >& v){
        cout<<"Copulation...\n";
        int newborns = rand()%3  + 1;
        cout<<"babies : "<<newborns<<endl;
        cout<<"Parents coordinates: "<<GetX()<<","<<GetY()<<endl;
        int babyLifePoints;
        int babyLifeExp;
        int babyFood;
        int babyStamina;
        int babyGenderRand;
        char babyGender;
        for (int i = 0; i < newborns; i++){
            babyLifePoints = rand()% 20 + 5;
            babyLifeExp = rand()% 15 + 5;
            babyStamina = rand()% 15 + 5;
            babyFood = rand()% 10 + 3;
            babyGenderRand = rand()% 2 + 1;
            if (babyGenderRand == 1) babyGender = 'm';
            else babyGender = 'f';
            int babyX = rand()% Object::cols*2;
            int babyY = rand()% Object::rows*2;
            babyX -= Object::cols;
            babyY -= Object::rows;
            shared_ptr<T> baby (new T(babyX, babyY, babyGender, 1, babyLifeExp, babyStamina, babyLifePoints, babyFood));
            cout<<"\t\t\t Baby is born:"<<babyX<<","<<babyY<<","<<babyGender<<","<<babyLifePoints<<endl;
            v.push_back(baby);
        }
    }


#endif // ANIMAL_H

