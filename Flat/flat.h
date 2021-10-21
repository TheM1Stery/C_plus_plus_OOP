#pragma once

#include "human.h"
#include "Vector.h"
#include <string.h>
class Flat
{
    Vector<Human*> residents;
    char* number_of_the_flat; // id
    int number_of_rooms; // number of rooms
    bool balcony; // is there a balcony in the flat
    int floor;
public:
    Flat();
    Flat(std::initializer_list<Human*> human,  const char* number_of_the_flat, int number_of_rooms, bool balcony, int floor);
    Flat(const Flat& flat);
    void operator=(const Flat& flat);
    void add_resident(Human* human);
    void remove_resident(Human* human);
    
    void set_number_of_rooms(int number);
    int get_number_of_rooms();

    size_t get_number_of_residents();

    void print_residents();

    void search_residents(const char* name);


    const char* get_number_of_the_flat();

    void set_number_of_the_flat(const char* number);
    

    int get_floor();

    void set_floor(int floor);




    void build_balcony();

    void destroy_balcony();
    


    ~Flat();
    


    


    
};