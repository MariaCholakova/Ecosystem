#include "Object.h"

int Object::rows = 10; //static variables
int Object::cols = 10;

Object::Coordinate::Coordinate(int a, int b): x {a}, y {b} {};

Object::Coordinate::Coordinate():Coordinate(0,0) {};

Object::Object(int x, int y)
{
    this->c = Coordinate(x,y);
}

Object::Object():Object(0,0){}

Object::Coordinate Object::GetCoordinate() const{
    return this->c;
}

void Object::SetX(const int x)
{
    this->c.x = x;
}

void Object::SetY(const int y)
{
    this->c.y = y;
}

int Object::GetX() const
{
    return this->c.x;
}

int Object::GetY() const
{
    return this->c.y;
}

bool Object::Coordinate::operator == (const Coordinate& c) const
{
    return ((this->x == c.x) &&(this->y == c.y));
}



