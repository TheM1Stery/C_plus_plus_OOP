#include "Vector.h"
#include <iostream>

struct Point
{
    float x,y,z;
};

int main()
{
    Vector<Point> vec;
    vec.push_back({1,2,3});
    std::cout << vec[0].x;
}