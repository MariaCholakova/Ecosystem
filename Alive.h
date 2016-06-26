#ifndef ALIVE_H
#define ALIVE_H
#include "Object.h"
#include <cmath>
using namespace std;

class Alive: public Object{
public:
    Alive(int x, int y, int lp);
    void DecreaseLP(int amount);
    int GetLifePoints() const;
    virtual bool CheckIfAlive();  //virtual because in animal age is checked as well
    int GetManhattanDistance(const Alive& other) const;
protected:
    int lifePoints;
    const int maxPoints;
    bool isAlive;
};


#endif // ALIVE_H
