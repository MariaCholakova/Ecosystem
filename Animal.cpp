#include "Animal.h"

Animal::Animal(int x, int y, char gender, int age, int lifeExp, int st, int lifePoints, int food):
    Alive(x,y,lifePoints), age{age}, lifeExp{lifeExp}, food{food}, stamina{st}, gender{gender} {};

void Animal::Move(){
    cout<<"animal is moving to food...\n";
    int distance = this->GetManhattanDistance(*target);
    int vertical = abs(this->GetY() - target->GetY());
    int horizontal = abs(this->GetX() - target->GetX());
    bool thisXsmaller = this->GetX() < target->GetX();
    bool thisYsmaller = this->GetY() < target->GetY();
    if (this->stamina >= distance){
        cout<<"moving onto target..\n";
        this->SetX(target->GetX());
        this->SetY(target->GetY());
    }
    else if (this->stamina < distance ){
        if(this->stamina < horizontal && this->stamina < vertical){
            int newY = thisYsmaller ? this->GetY()+vertical : this->GetY()-vertical;
            this->SetY(newY);
            //cout<<"moving along Oy...\n";
        }
        else if (this->stamina >= vertical){
            this->SetY(target->GetY());
            int staminaLeft = stamina-vertical;
            int newX = thisXsmaller ? this->GetX()+staminaLeft : this->GetX()-staminaLeft;
            this->SetX(newX);
        } else if (this->stamina >= horizontal){
            this->SetX(target->GetX());
            int staminaLeft = stamina-horizontal;
            int newY = thisYsmaller ? this->GetY()+staminaLeft : this->GetY()-staminaLeft;
            this->SetY(newY);
        }
    }
    cout<<"target coords: "<<target->GetX()<<"  "<<target->GetY()<< "    ;";
    cout<<"animal finishes moving..new coordinates :"<<GetX()<<", "<<GetY()<<endl;
}

void Animal::CheckLocation(waterVec& wv){
    cout<<"system checks location..\n";
    if (location == habitat::land){
        for (int i = 0; i < wv.size(); i++){
            if (wv[i]->HasThisCoordinate(*this)){
                this->DecreaseLP(1);
                break;
            }
        }
    }
    if (location == habitat::water){
        bool inWater = false;
        for (int i = 0; i < wv.size(); i++){
            if (wv[i]->HasThisCoordinate(*this)){
                inWater = true;
                break;
            }
        }
        if (!inWater) {
            cout<<"\t Decreasing water animal life points..\n";
            this->DecreaseLP(1);
        }
    }
}

char Animal::GetGender() const{
    return this->gender;
}

void Animal::GrowAge(){
    this->age++;
}

bool Animal::CheckIfAlive(){
   if (this->lifePoints <= 0 || this->age == this->lifeExp){
        cout<<"This animal is dead : "<<GetX()<<","<<GetY()<<endl;
        isAlive = false;
    }
    return isAlive;
}
