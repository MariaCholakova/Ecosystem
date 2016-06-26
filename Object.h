#ifndef OBJECT_H
#define OBJECT_H


class Object
{
public:
    static int rows;
    static int cols;

private:
    struct Coordinate
    {
        int x;
        int y;
        Coordinate(int a, int b);
        Coordinate();
        bool operator == (const Coordinate& c) const;
    };

protected:
    Coordinate c;
    Object(int x, int y); // to not create objects of this class, but of his children
    Object();
public:
    Coordinate GetCoordinate() const;
    void SetX(const int x);
    void SetY(const int y);
    int GetX() const;
    int GetY() const;

};
#endif // OBJECT_H
