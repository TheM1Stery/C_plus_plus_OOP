#include "Vector.h"
#include <iostream>


struct Point
{
    double x,y,z;
    Point(): x(0), y(0), z(0) {}
    Point(double x, double y, double z) : x(x), y(y), z(z) {}
};

int main()
{
    Vector<Point> vec;
    vec.emplace_back(1,2,3);
    std::cout << vec[0].x << ' ' << vec[0].y << ' ' << vec[0].z;
}