#include "flat.h"

Flat::Flat() : number_of_rooms(0), balcony(false), floor(0)
{
    number_of_the_flat = new char[100];
}


Flat::Flat(std::initializer_list<Human> human,  char* number_of_the_flat, int number_of_rooms, bool balcony, int floor) : Flat()
{
    residents = human;
    strcpy_s(this->number_of_the_flat, 100, number_of_the_flat);
    this->number_of_rooms = number_of_rooms;
    this->balcony = balcony;
    this->floor = floor;
}

Flat::Flat(const Flat& flat)
{
    number_of_the_flat = new char[100];
    strcpy_s(number_of_the_flat, 100, flat.number_of_the_flat);
    balcony = flat.balcony;
    number_of_rooms = flat.number_of_rooms;
    residents = flat.residents;
    floor = flat.floor;
}

void Flat::add_resident(Human& human)
{
    if (human.get_fathers_name() == nullptr || human.get_age() == 0 || human.get_name() == nullptr || human.get_surname() == nullptr)
    {
        return;
    }
    residents.push_back(human);
}

void Flat::remove_resident(Human& human)
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


int Flat::get_number_of_rooms()
{
    return number_of_rooms;
}

void Flat::set_number_of_rooms(int number_of_rooms)
{
    if (number_of_rooms < 0 || this->number_of_rooms != 0)
    {
        return;
    }
    this->number_of_rooms = number_of_rooms;

}


const char* Flat::get_number_of_the_flat()
{
    if (number_of_the_flat != nullptr)
    {
        return number_of_the_flat;
    }
    return "0";
}


void Flat::set_number_of_the_flat(const char* number)
{
    if (number == nullptr)
    {
        return;
    }
    strcpy_s(number_of_the_flat, 100, number);
}




void Flat::build_balcony()
{
    balcony = true;
}
void Flat::destroy_balcony()
{
    balcony = false;
}



void Flat::print_residents()
{
    for (int i = 0; i < residents.size(); i++)
    {
        std::cout << i + 1 << ". " << residents[i].get_name() << '\n';
    }
}

void Flat::search_residents(const char* name)
{
    Vector<Human> humans;
    for (int i = 0; i < residents.size(); i++)
    {
        char* temp = strstr(residents[i].get_name(), name);
        if (temp != nullptr)
        {
            humans.push_back(residents[i]);
        }
    }

    for (int i = 0; i < humans.size(); i++)
    {
        std::cout << i + 1 << ". " << humans[i].get_name() << '\n';
    }
}

void Flat::set_floor(int floor)
{
    if (this->floor != 0)
    {
        return;
    }
    this->floor = floor;
}

int Flat::get_number_of_residents()
{
    return residents.size();
}


Flat::~Flat()
{
    delete[] number_of_the_flat;
}