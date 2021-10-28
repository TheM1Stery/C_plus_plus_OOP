#pragma once

#include <cstddef>
#include <initializer_list>

class String
{
    size_t length;
    size_t capacity;
    char* string;
public:
    String(); // default constructor
    String(const char* str); // constructor from c-style array
    String(std::initializer_list<char> list); // ctor from initializer list
    String(size_t size); // reserving capacity for String
    String(const String& string); // copy constructor
    String(String&& string); // move constructor

    String& operator=(const String& str);
    String& operator=(String&& str);



    size_t size();
    size_t length();

    int compare(const String& str, const String& str2);
    void reverse(String& str);
    void reserve(size_t size);
    void append(const String& string);
    String operator+= (const String& string);
    String operator+ (const String& string);
    char& operator[](size_t index);
    void push_back(); 
    void pop_back();
    void erase(int index);
    void erase(int st_index, int end_index);


    


    ~String();
};

