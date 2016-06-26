#include "Herbivore.h"

int GetMiddleValueOfThree(int a, int b, int c);

//--------------------------------------------------------------------------------------------------------
Herbivore::Herbivore(int x, int y, char gender, int age, int lifeExp, int stamina, int lifePoints, int food):
    Animal(x, y, gender, age, lifeExp, stamina, lifePoints, food) {}


void Herbivore::FindTarget(plantVec& pv){
    cout<<"herbivore finding target..\n";
    bool animalOnPlant = false;
    int indexDeadArea;              //if all plants in the area are dead
    for (int i = 0; i < pv.size(); i++){
        if (pv[i]->HasThisCoordinate(*this)){
            cout<<"herbivore is on plant.."<<endl;
            target = pv[i]->GetPlant(*this);
            animalOnPlant = true;
            indexDeadArea = i;
            break;
        }
    }
    bool enteredDeadArea = false;
    if (animalOnPlant && target->CheckIfAlive() == false) enteredDeadArea = true;
    if ((!animalOnPlant) || enteredDeadArea){      //the cases when the animal has to search for plant area
        cout<<"animal is not on plant...\n";
        int distanceToUL = GetManhattanDistance(pv[0]->GetUL());
        int distanceToBR = GetManhattanDistance(pv[0]->GetBR());
        int minSum = 2*(distanceToUL + distanceToBR);     //distance to a rectangle
        int minDindex = 0;
        for (int i = 0; i < pv.size(); i++){
            if (enteredDeadArea){
                if(i == indexDeadArea) continue;           //skip the dead area the animal is currently on
            }
            distanceToUL = GetManhattanDistance(pv[i]->GetUL());
            if(distanceToUL > minSum){                 //if the distance to one of the corners is greater than
                continue;                             //the previous sum, no need to continue with this area ->skip it
            }
            else {
                distanceToBR = GetManhattanDistance(pv[i]->GetBR());
                if (distanceToBR > minSum){
                    continue;
                }
                else {
                    int sum = 2*(distanceToUL + distanceToBR);
                    if (sum < minSum ){
                        minSum = sum;
                        minDindex = i;
                    }
                }
            }
        }
        int x1 = this->GetX();
        int x2 = pv[minDindex]->GetUL().GetX();
        int x3 = pv[minDindex]->GetBR().GetX();
        int targetX = GetMiddleValueOfThree(x1, x2, x3);
        int y1 = this->GetY();
        int y2 = pv[minDindex]->GetUL().GetY();
        int y3 = pv[minDindex]->GetBR().GetY();
        int targetY = GetMiddleValueOfThree(y1, y2, y3);
        shared_ptr<Alive> a (new  Alive(targetX, targetY, pv[minDindex]->GetUL().GetLifePoints()));
        target = pv[minDindex]->GetPlant(*a);
        cout<<"Target coords: "<<target->GetX()<<" "<<target->GetY()<<endl;
   }
}

void Herbivore::Eat(){
    if (this->GetCoordinate() == target->GetCoordinate()){
        if (this->lifePoints < this->maxPoints){
            cout<<"herbivore is eating, life points :"<<GetLifePoints()<<endl;//only then eat
            if (target->GetLifePoints() >= food){
                this->lifePoints += food;
                target->DecreaseLP(food);
            }else {
                this->lifePoints += target->GetLifePoints();      //plant capacity < food
                target->DecreaseLP(food);
            }
        }
        if (this->lifePoints > maxPoints){
            lifePoints = maxPoints;
        }
    } else cout<<"not on target yet, no eating :(..."<<endl;
}

//--------------------------------------------------------------------------------

int GetMiddleValueOfThree(int a, int b, int c){
    if ((a-b)*(c-a)>= 0){
        return a;
    }
    else if((b-a)*(c-b) >= 0){
        return b;
    }
    else return c;
}
