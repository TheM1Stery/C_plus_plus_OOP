#include "reservoir.h"
#include <string.h>
Reservoir::Reservoir()
{
    name = new char[100];
    type = new char[100];
    depth = 50;
    width = 50;
    length = 50;
    area = length * width;
    volume = depth * length * width;
    strcpy_s(name, 100, "Default");
    strcpy_s(type, 100, "Pond");
}

Reservoir::Reservoir(const char* name, const char* type, double depth, double width, double area) : Reservoir()
{
    this->depth = depth;
    this->width = width;
    this->length = length;
    area = length * width;
    volume = depth * length * width;
    strcpy_s(this->name, 100, name);
    strcpy_s(this->type, 100, type);
}

Reservoir::Reservoir(const Reservoir& reservoir)
{
    name = new char[100];
    type = new char[100];
    depth = reservoir.depth;
    width = reservoir.width;
    length = reservoir.length;
    area = reservoir.area;
    volume = reservoir.volume;
}

Reservoir& Reservoir::operator=(const Reservoir& reservoir)
{
    delete[] name;
    delete[] type;
    depth = reservoir.depth;
    width = reservoir.width;
    length = reservoir.length;
    area = reservoir.area;
    volume = reservoir.volume;
}

const char* Reservoir::get_name()
{
    return name;
}

const char* Reservoir::get_type()
{
    return type;
}

double Reservoir::get_area()
{
    return area; 
}

double Reservoir::get_volume()
{
    return volume;
}


int Reservoir::compare_name(Reservoir& reservoir)
{
    return strcmp(name, reservoir.name);
}

int Reservoir::compare_area(Reservoir& reservoir)
{
    if (area > reservoir.get_area())
    {
        return 1;
    }
    if (area < reservoir.get_area())
    {
        return -1;
    }
    return 0;
}




Reservoir::~Reservoir()
{
    delete[] name;
    delete[] type;
}
