#pragma once
#include <iostream>

#include "reservoir.h"
#include <initializer_list>

template<typename T> class Vector
{
    size_t actual_size; // the size that array actually has
    size_t fixed_size; // the size which the user gets
    T* vector;
public:
    Vector() // default constructor 
    {
        actual_size = 0;
        fixed_size = 0;
        vector = new T[actual_size];
    }
    Vector(size_t actual_size)
        : actual_size(actual_size), fixed_size(0)   // constructor which reserves memory
    {
        if (actual_size < 0)
        {
            this->actual_size = 0;
            vector = new T[this->actual_size];
            return;
        }
        vector = new T[actual_size];
    }
    Vector(std::initializer_list<T> list)  // constructor with initliazer list
        : actual_size(list.size()), fixed_size(list.size())
    {
        vector = new T[list.size()];
        int i = 0;
        for (auto& item : list)
        {
            vector[i++] = item;
        }
    }
    Vector(const Vector& arr) // Copy constructor
    {
        vector = new T[arr.actual_size];
        for (int i = 0; i < arr.fixed_size; i++)
        {
            vector[i] = arr.vector[i];
        }
        actual_size = arr.actual_size;
        fixed_size = arr.fixed_size;
    }


    Vector& operator=(const Vector& arr)
    {
        delete[] vector;
        vector = new T[arr.actual_size];
        for (int i = 0; i < arr.fixed_size; i++)
        {
            vector[i] = arr.vector[i];
        }
        actual_size = arr.actual_size;
        fixed_size = arr.fixed_size;
        return *this;
    }


    size_t size()    // get the size of the Vector    (fixed_size)
    {
        return fixed_size;
    }
    size_t capacity() // get the capacity of the Vector  (actual_size)
    {
        return actual_size;
    }
    void reserve(size_t reserved_size) // Reserve memory for the Vector
    {
        if (empty())
        {
            delete[] vector;
            vector = new T[reserved_size];
            actual_size = reserved_size;
            return;
        }
        if (reserved_size <= capacity())
        {
            return;
        }
        T* new_arr = new T[reserved_size];
        for (int i = 0; i < fixed_size; i++)
        {
            new_arr[i] = vector[i];
        }
        delete[] vector;
        vector = new_arr;
        actual_size = reserved_size;
    }
    T& operator[](int index) // access the element of the array
    {
        return vector[index];
    }
    void operator=(std::initializer_list<T> list) // reassign the values of the array using initiliazer list
    {
        if (list.size() > actual_size)
        {
            reserve(list.size());
        }
        int i = 0;
        for (auto& item : list)
        {
            vector[i++] = item;
        }
        fixed_size = list.size();
    }


    T& at(int index) // access the element of the array
    {
        if (index < 0 || index >= fixed_size)
        {
            throw std::out_of_range("out of range");
        }
        return vector[index];
    }
    bool empty() // check if the array is empty
    {
        if (!size())
        {
            return true;
        }
        return false;
    }
    void push_back(T& element) // put the element to the end of the array
    {
        if (capacity() == size())
        {
            if (capacity() == 0)
            {
                actual_size++;
            }
            reserve(actual_size * 2);
        }
        vector[fixed_size] = element;
        fixed_size++;
    }

    void push_back(T&& element) // put the element to the end of the array
    {
        if (capacity() == size())
        {
            if (capacity() == 0)
            {
                actual_size++;
            }
            reserve(actual_size * 2);
        }
        vector[fixed_size] = element;
        fixed_size++;
    }

    void assign(int count, T& value) // asssign values to the array
    {
        if (count > actual_size)
        {
            reserve(count);
        }
        for (int i = 0; i < count; i++)
        {
            vector[i] = value;
        }
        fixed_size = count;
    }


    void assign(int count, T&& value) // asssign values to the array
    {
        if (count > actual_size)
        {
            reserve(count);
        }
        for (int i = 0; i < count; i++)
        {
            vector[i] = value;
        }
        fixed_size = count;
    }


    void assign(std::initializer_list<T> list) // assign values to the array using initiliazer list
    {
        if (list.size() > actual_size)
        {
            reserve(list.size());
        }
        int i = 0;
        for (auto& item : list)
        {
            vector[i++] = item;
        }
        fixed_size = list.size();
    }
    void pop_back() // remove the last element
    {
        if (!empty())
        {
            fixed_size--;
        }
    }
    void erase(int index) // erase the element at the given index
    {
        if (empty())
        {
            return;
        }
        for (int i = index; i < fixed_size - 1; i++)
        {
            vector[i] = vector[i + 1];
        }
        fixed_size--;
    }

    void remove(const char* name)
    {
        int index = -1;
        for (int i = 0; i < size(); i++)
        {
            if (!strcmp(name, vector[i].get_name())) 
            {
                index = i;
            }
        }

        if (index == -1)
        {
            return;
        }

        erase(index);
    }

    T& operator[] (const char* name)
    {
        int index = -1;
        for (int i = 0; i < size(); i++)
        {
            if (!strcmp(name, vector[i].get_name()))
            {
                index = i;
            }
        }

        if (index == -1)
        {
            return;
        }
        
        return operator[](index);
    }
    





    ~Vector()
    {
        delete[] vector;
    }


};
