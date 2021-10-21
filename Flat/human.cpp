#include "human.h"
#include <string.h>
#include <iostream>
#define SIZE 100

Human::Human() : age(0), gender(GENDER::MALE)
{
    name = new char[SIZE];
    surname = new char[SIZE];
    fathers_name = new char[SIZE];
}


Human::Human(const char* name, const char* surname, const char* fathers_name, int age, GENDER gender)
{
    this->name = new char[100];
    this->surname = new char[100];
    this->fathers_name = new char[100];
    strcpy_s(this->name, SIZE, name);
    strcpy_s(this->surname, SIZE, surname);
    strcpy_s(this->fathers_name, SIZE, fathers_name);
    this->age = age;
    this->gender = gender;
}


Human::Human(const Human& human)
{
    name = new char[100];
    surname = new char[100];
    fathers_name = new char[100];
    strcpy_s(name, SIZE, human.name);
    strcpy_s(surname, SIZE, human.surname);
    strcpy_s(fathers_name, SIZE, human.fathers_name);
    age = human.age;
    gender = human.gender;
}

void Human::operator=(const Human& human)
{
    delete[] name;
    delete[] surname;
    delete[] fathers_name;
    name = new char[100];
    surname = new char[100];
    fathers_name = new char[100];
    strcpy_s(name, SIZE, human.name);
    strcpy_s(surname, SIZE, human.surname);
    strcpy_s(fathers_name, SIZE, human.fathers_name);
    age = human.age;
    gender = human.gender;
}


const char* Human::get_name()
{
    return name;
}

void Human::set_name(const char* name)
{
    if (name == nullptr)
    {
        return;
    }
    strcpy_s(this->name, SIZE, name);
}

const char* Human::get_surname()
{
    return name;
}

void Human::set_surname(const char* name)
{
    if (name == nullptr)
    {
        return;
    }
    strcpy_s(this->name, SIZE, name);
}



int Human::get_age()
{
    if (age != 0)
    {
        return age;
    }
}

void Human::set_age(int age)
{
    if (age == 0 || this->age != 0)
    {
        return;
    }
    this->age = age;
    
}




GENDER Human::get_gender()
{
    return gender;
}

void Human::set_gender(GENDER gender)
{
    this->gender = gender;
}


const char* Human::get_fathers_name()
{
    return fathers_name;
}

void Human::set_fathers_name(const char* father)
{
    strcpy_s(fathers_name, 100, father);
}


Human::~Human()
{
    delete[] name;
    delete[] surname;
    delete[] fathers_name;
}
