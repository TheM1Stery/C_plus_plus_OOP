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

    const char* get_name() const;

    const char* get_type() const;


    double get_area() const;

    double get_volume() const;            

    int compare_name(Reservoir& compared_reservoir) const;

    int compare_area(Reservoir& compared_reservoir) const;

    ~Reservoir();
};
