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

    Reservoir(const char* name, const char* type, double depth, double width, double length);

    Reservoir(const Reservoir& reservoir);

    Reservoir& operator=(const Reservoir& reservoir);

    const char* get_name();

    const char* get_type();


    double get_area();

    double get_volume();            

    int compare_name(Reservoir& compared_reservoir);

    int compare_area(Reservoir& compared_reservoir);

    ~Reservoir();
};
