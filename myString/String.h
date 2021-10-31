#pragma once

#include <cstddef>
#include <initializer_list>
#include <ostream>
class String
{
    size_t m_length;
    size_t m_capacity;
    char* string;
    friend std::ostream& operator<<(std::ostream& stream, String& str);
    friend std::ostream& operator<<(std::ostream& stream, String&& str);
public:
    String(); // default constructor
    String(const char* str); // constructor from c-style array
    String(const char* str, size_t size);
    String(std::initializer_list<char> list); // ctor from initializer list
    String(size_t count, char r); // a char symbol repeated count times and then assigned to the String
    String(size_t size); // reserving capacity for String
    String(const String& string); // copy constructor
    String(String&& string); // move constructor
    String& operator=(const String& str);
    String& operator=(String&& str);




    
    void reserve(size_t size);

    // size and length are the same methods, they return m_length
    size_t size() const ; 
    size_t length() const ; 

    size_t capacity() const ; // return the current allocated size of the string



    String substr(size_t pos);
    String substr(size_t pos, size_t count);
    int compare(const String& str) const;
    bool operator >(const String& str) const;
    bool operator <(const String& str) const;
    bool operator ==(const String& str) const;
    void reverse();
    void append(const char* str);
    void append(const String& string);
    String operator + (const char* str);
    String operator+ (const String& string);
    String& operator += (const char* str);
    String& operator+= (const String& string);
    String operator * (size_t count);
    char& operator[](size_t index);
    const char& operator[](size_t index) const ;
    void push_back(char chr); 
    void pop_back();
    void erase(size_t index);
    void erase(size_t st_index, size_t end_index);
    char* data() const;
    size_t find(char search) const ;
    size_t find(const String& string) const;

    


    ~String();
};

