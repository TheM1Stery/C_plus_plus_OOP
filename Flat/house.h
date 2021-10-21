#pragma once


#include "flat.h"


class House
{
    Vector<Flat> flats;
    char* address_of_the_house;
    int number_of_floors;
    bool elevator; // is there a elevator in the house



public:
    House();
    House(std::initializer_list<Flat> flat, const char* address_of_the_house, int number_of_floors, bool elevator);
    House(const House& house);



    const char* get_address();
    
    void set_address(const char* address);

    int get_number_of_flats();
        
    int get_number_of_floors();

    void set_number_of_floors(int floors);

    void build_elevator();
    void remove_elevator();


    
    ~House();

};