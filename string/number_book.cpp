#include "number_book.h"
#include <string.h>

#define SIZE 100


NumberBook::NumberBook()
{
    name = new char[SIZE];
    home_number = new char[SIZE];
    work_number = new char[SIZE];
    mobile_number = new char[SIZE];
    additional_info = new char[SIZE];
}

NumberBook::NumberBook(const char* name, const char* home_number, const char* work_number, 
    const char* mobile_number, const char* additional_info) : NumberBook()
{
    strcpy_s(this->name, SIZE, name);
    strcpy_s(this->home_number, SIZE, home_number);
    strcpy_s(this->work_number, SIZE, work_number);
    strcpy_s(this->mobile_number, SIZE, mobile_number);
    strcpy_s(this->additional_info, SIZE, additional_info);
    
}




NumberBook::~NumberBook()
{
    delete[] name;
    delete[] home_number;
    delete[] work_number;
    delete[] mobile_number;
    delete[] additional_info;
}