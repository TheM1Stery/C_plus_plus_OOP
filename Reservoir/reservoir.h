#pragma once

#include "Vector.h"


class Reservoir
{
    char* name;
    char* type;
    double depth;
    double width;
    double length;
    double area;
    double volume;
public:
    Reservoir();

    Reservoir(double depth, double width, double length);

    Reservoir(const Reservoir& reservoir);

    double get_area();

    double get_volume();
    
    int compare(Reservoir& compared_reservoir);

    int compare_area(Reservoir& compared_reservoir);

    ~Reservoir();
};