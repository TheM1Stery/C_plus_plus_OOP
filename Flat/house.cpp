#include "house.h"



House::House() : number_of_floors(0), elevator(0)
{
    address_of_the_house = new char[100];
}

House::House(std::initializer_list<Flat*> flats, const char* address_of_the_house, int number_of_floors, bool elevator)
: House()
{
    this->flats = flats;
    strcpy_s(this->address_of_the_house, 100, address_of_the_house);
    this->number_of_floors = number_of_floors;
    this->elevator = elevator;
}

House::House(const House& house)
{
    address_of_the_house = new char[100];
    strcpy_s(address_of_the_house, 100, house.address_of_the_house);
    flats = house.flats;
    number_of_floors = house.number_of_floors;
    elevator = house.elevator;

}

const char* House::get_address()
{
    return address_of_the_house;
}

void House::set_address(const char* address)
{
    if (address == nullptr)
    {
        return;
    }
    strcpy_s(address_of_the_house, 100, address);
}

size_t House::get_number_of_flats()
{
    return flats.size();
}

int House::get_number_of_floors()
{
    return number_of_floors;
}


void House::set_number_of_floors(int floors)
{
    number_of_floors = floors;
}


void House::build_elevator()
{
    elevator = true;
}

void House::remove_elevator()
{
    elevator = false;
}





House::~House()
{
    delete[] address_of_the_house;
}





