#ifndef RAINAREA_H
#define RAINAREA_H
#include "Rain.h"
#include <vector>
#include <memory>
using namespace std;

class RainArea {
private:
    Rain UL;
    Rain BR;
public:
    RainArea();
    Rain GetUL() const;
    Rain GetBR() const;
    int GetHeight() const;
    int GetWidth() const;
};
typedef vector<shared_ptr<RainArea> >rainVec;

#endif // RAINAREA_H
