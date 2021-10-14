#pragma once




class NumberBook
{
    char* name;
    char* home_number;
    char* work_number;
    char* mobile_number;
    char* additional_info;
public:

    NumberBook();
    NumberBook(const char* name, const char* home_number, const char* work_number, 
    const char* mobile_number, const char* additional_info);



    ~NumberBook();
    
};