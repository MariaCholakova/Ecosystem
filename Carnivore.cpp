#include "Carnivore.h"

Carnivore::Carnivore(int x, int y, char gender, int age, int lifeExp, int stamina, int lifePoints, int food):
    Animal(x, y, gender, age, lifeExp, stamina, lifePoints, food) {}

void Carnivore::FindTarget(const herbVec& vegans){
    int n = vegans.size();
    cout<<"\t\t vegans size: "<<n<<endl;
    bool carnivoreOnTarget = false;
    for (int i = 0; i < n; i++){
        if (vegans[i]->GetCoordinate() == this->GetCoordinate()){
            target = vegans[i];
            carnivoreOnTarget = true;
            break;
        }
    }
    if (carnivoreOnTarget == false){
        cout<<"finding closest herbivore..\n";
        vector<int> distances;
        for (int i = 0; i < n; i++){
            int d = GetManhattanDistance(*vegans[i]);
            distances.push_back(d);
        }
        int minD = distances[0];
        int minDindex = 0;
        for (int i = 1; i < n; i++){
            if (distances[i] < minD) {
                minD = distances[i];
                minDindex = i;
            }
        }
        target = vegans[minDindex];
    }
}

void Carnivore::Eat(){
    if (this->GetCoordinate() == target->GetCoordinate()){
        cout<<"Carnivore is eating herbivore...\n";
        this->lifePoints += food;
        target->DecreaseLP(food);
        if (this->lifePoints > maxPoints){
            lifePoints = maxPoints;
        }
    } else cout<<"not on target , no eating..\n";
}

int Carnivore::GetFood() const{
    return this->food;
}

void Carnivore::Fight(Carnivore& other){
    cout<<"\t\t\tCarnivores are fighting..\n";
    this->DecreaseLP(food/2);
    other.DecreaseLP(other.GetFood()/2);
}

