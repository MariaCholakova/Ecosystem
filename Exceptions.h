#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>
#include <exception>
using namespace std;

struct AreaException : public exception
{
  const char* what () const throw ()
  {
    return "Invalid input! The coordinates of the area are out of the field's range!";
  }
};

struct GrassException : public exception
{
  const char* what () const throw ()
  {
    return "Invalid input! The coordinates of the grass area overlap with water area!";
  }
};

struct AlgaeException : public exception
{
  const char* what () const throw ()
  {
    return "Invalid input! The coordinates of the algae area are not entirely in water area!";
  }
};

#endif // EXCEPTIONS_H
