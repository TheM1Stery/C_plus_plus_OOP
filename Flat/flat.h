#pragma once

#include "human.h"
#include "Vector.h"
#include <string.h>
class Flat
{
    Vector<Human> residents;
    char* number_of_the_flat; // id
    int number_of_rooms; // number of rooms
    bool balcony; // is there a balcony in the flat
public:
    Flat();
    Flat(const char* number_of_the_flat, int number_of_rooms, bool balcony);
    Flat(const Flat& flat);
    
    void add_resident(Human& human)
    {
        if (human.get_fathers_name() == nullptr || human.get_age() == 0 || human.get_name() == nullptr || human.get_surname() == nullptr)
        {
            return;
        }
        residents.push_back(human);
    }

    void remove_resident(Human& human)
    {
        int index = -1;
        for (int i = 0; i < residents.size(); i++)
        {
            if (!strcmp(residents[i].get_name(), human.get_name()))
            {
                index = i; 
            }
        }
        if (index == -1)
        {
            return;
        }
        residents.erase(index);
    }





    void build_balcony()
    {
        balcony = true;
    }
    void destroy_balcony()
    {
        balcony = false;
    }





    


    
};