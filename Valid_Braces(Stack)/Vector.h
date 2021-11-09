#pragma once
#include <iostream>
#include <initializer_list>
//
//template<typename T> std::ostream& operator << (std::ostream& stream, Vector<T> vec)
//{
//
//}


template<typename Vector> class VectorIterator
{
public:
    using Type = typename Vector::Type;

    VectorIterator(Type* iterator) : iterator(iterator) {}

    VectorIterator& operator ++()
    {
        iterator++;

        return *this;
    }

    VectorIterator& operator ++(int)
    {
        VectorIterator copy(*this);
        ++(*this);
        return copy;
    }

    Type& operator *()
    {
        return *iterator;
    }

    bool operator==(const VectorIterator& copy)
    {
        return iterator == copy.iterator;
    }

    bool operator!=(const VectorIterator& copy)
    {
        return iterator != copy.iterator;
    }

private:
    Type* iterator;
};



template<typename T> class Vector
{
    size_t actual_size; // the size that array actually has
    size_t fixed_size; // the size which the user gets
    T* vector;
public:

    using Type = T;
    using Iterator = VectorIterator<Vector>;


    Vector() // default constructor 
    {
        actual_size = 0;
        fixed_size = 0;
        //vector = new T[actual_size];
        vector = nullptr;
    }
    Vector(size_t actual_size)
        : actual_size(actual_size), fixed_size(0)   // constructor which reserves memory
    {
        if (actual_size < 0)
        {
            this->actual_size = 0;
            //vector = new T[this->actual_size];
            vector = static_cast<T*>(::operator new[](this->actual_size * sizeof(T)));
            return;
        }
        vector = static_cast<T*>(::operator new[](actual_size));
    }
    Vector(std::initializer_list<T> list)  // constructor with initliazer list
        : actual_size(list.size()), fixed_size(list.size())
    {
        //vector = new T[list.size()];
        vector = static_cast<T*>(::operator new[](list.size() * sizeof(T)));
        int i = 0;
        for (auto& item : list)
        {
            vector[i++] = item;
        }
    }
    Vector(const Vector& arr) // Copy constructor
    {
        //vector = new T[arr.actual_size];
        vector = static_cast<T*>(::operator new[](arr.actual_size * sizeof(T)));
        for (int i = 0; i < arr.fixed_size; i++)
        {
            vector[i] = arr.vector[i];
        }
        actual_size = arr.actual_size;
        fixed_size = arr.fixed_size;
    }


    Vector(Vector&& arr) // Move constructor
    {
        vector = arr.vector;
        fixed_size = arr.fixed_size;
        actual_size = arr.actual_size;

        arr.actual_size = 0;
        arr.fixed_size = 0;
        arr.vector = nullptr;
    }


    Vector& operator=(const Vector& arr) // copy assignment
    {
        ::operator delete[](vector);
        //vector = new T[arr.actual_size];
        vector = static_cast<T*>(::operator new[](arr.actual_size * sizeof(T)));
        for (int i = 0; i < arr.fixed_size; i++)
        {
            vector[i] = arr.vector[i];
        }
        actual_size = arr.actual_size;
        fixed_size = arr.fixed_size;
        return *this;
    }

    Vector& operator = (Vector&& arr) // move assignment
    {
        ::operator delete[](vector);
        //vector = static_cast<T*>(::operator new[](arr.actual_size * sizeof(T)));
        /*for (int i = 0; i < arr.fixed_size; i++)
        {
            vector[i] = std::move(arr.vector[i]);
        }*/

        vector = arr.vector;
        fixed_size = arr.fixed_size;
        actual_size = arr.actual_size;

        arr.actual_size = 0;
        arr.fixed_size = 0;
        arr.vector = nullptr;
        return *this;
    }


    size_t size() const   // get the size of the Vector    (fixed_size)
    {
        return fixed_size;
    }
    size_t capacity() const    // get the capacity of the Vector  (actual_size)
    {
        return actual_size;
    }
    void reserve(size_t reserved_size) // Reserve memory for the Vector
    {
        if (empty())
        {
            ::operator delete[](vector);
            //vector = new T[reserved_size];
            vector = static_cast<T*>(::operator new[](reserved_size * sizeof(T)));
            actual_size = reserved_size;
            return;
        }
        if (reserved_size <= capacity())
        {
            return;
        }
        //T* new_arr = new T[reserved_size];
        T* new_arr = static_cast<T*>(::operator new[](reserved_size * sizeof(T)));
        for (int i = 0; i < fixed_size; i++)
        {
            new_arr[i] = std::move(vector[i]);
        }
        ::operator delete[](vector);
        vector = new_arr;
        actual_size = reserved_size;
    }
    T& operator[](int index) // access the element of the array
    {
        return vector[index];
    }

    const T& operator[](int index) const
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
    void push_back(const T& element) // put the element to the end of the array
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
        vector[fixed_size] = std::move(element);
        fixed_size++;
    }


    template<typename... args> T& emplace_back(args&&... argss)
    {
        if (capacity() == size())
        {
            if (capacity() == 0)
            {
                actual_size++;
            }
            reserve(actual_size * 2);
        }
        vector[fixed_size] = T(std::forward<args>(argss)...);
        return vector[fixed_size++];
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


    Vector operator +(const Vector& vec)
    {
        Vector c_vec(*this);
        for (int i = 0; i < vec.fixed_size; i++)
        {
            c_vec.push_back(vec[i]);
        }
        return c_vec;
    }

    Vector& operator+=(const Vector& vec)
    {
        for (int i = 0; i < vec.fixed_size; i++)
        {
            push_back(vec[i]);
        }
        return *this;
    }

    Vector operator *(int count)
    {
        Vector vec(*this);
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = 0; j < size(); j++)
            {
                vec.push_back(vec[i]);
            }
        }
        return vec;
    }

    Vector& operator *=(int count)
    {
        size_t c_size = size();
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = 0; j < c_size; j++)
            {
                push_back(vector[i]);
            }
        }
        return *this;
    }

    T& front()
    {
        
        return vector[0];

    }
    T& back()
    {
        
        return vector[fixed_size - 1];
    }

    const T& front() const
    {
        
        return vector[0];

    }
    const T& back() const
    {
        
        return vector[fixed_size - 1];
    }


    Iterator begin() const
    {
        return vector;
    }

    Iterator end() const
    {
        return (vector + fixed_size);
    }


    ~Vector() // destructor
    {
        ::operator delete[](vector);
    }


};
