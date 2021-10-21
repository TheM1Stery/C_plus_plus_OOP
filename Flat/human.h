#pragma once

enum class GENDER
{
    MALE,
    FEMALE,
    OTHER
};

class Human
{
    char* name;
    char* surname;
    char* fathers_name;
    int age;
    GENDER gender;
public:
    Human();
    Human(const char* name, const char* surname, const char* fathers_name, int age, GENDER gender);
    Human(const Human& human);
    
    void operator=(const Human& human);




    const char* get_name();
    void set_name(const char* name);

    const char* get_surname();
    void set_surname(const char* name);

    const char* get_fathers_name();
    void set_fathers_name(const char* name);

    int get_age();
    void set_age(int age);

    GENDER get_gender();
    void set_gender(GENDER gender);
   

    
    
    ~Human();
    
};