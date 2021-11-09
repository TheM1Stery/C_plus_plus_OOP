#pragma once

#include <cstddef>
#include <initializer_list>


template<typename T, size_t size> class CircularArray
{
    size_t m_start;
    size_t m_end;
    size_t m_length;
public:
    T* arr;
    CircularArray() : m_start(0), m_end(0), m_length(0)
    {
        arr = static_cast<T*>(::operator new[](size * sizeof(T)));
    }
    CircularArray(std::initializer_list<T> list)
    {
        arr = static_cast<T*>(::operator new[](size * sizeof(T)));
        m_start = 0;
        m_end = 0;
        m_length = 0;
        for (const auto& item : list)
        {
            push(item);
        }
    }

    CircularArray(const CircularArray& copy)
    {
        m_start = copy.m_start;
        m_end = copy.m_end;
        m_length = copy.m_length;
        arr = static_cast<T*>(::operator new[](size * sizeof(T)));
        for (int i = 0; i < size; i++)
        {
            arr[i] = copy.arr[i];
        }
    }

    CircularArray(CircularArray&& move)
    {
        arr = move.arr;
        m_start = move.m_start;
        m_end = move.m_end;
        m_length = move.m_length;

        move.m_start = 0;
        move.m_end = 0;
        move.m_length = 0;
        move.arr = nullptr;
    }

    CircularArray& operator =(const CircularArray& copy)
    {
        ::operator delete[](arr);
        m_start = copy.m_start;
        m_end = copy.m_end;
        m_length = copy.m_length;
        arr = static_cast<T*>(::operator new[](size * sizeof(T)));
        for (int i = 0; i < size; i++)
        {
            arr[i] = copy.arr[i];
        }
        return *this;
    }
    CircularArray& operator = (CircularArray&& move)
    {
        ::operator delete[](arr);
        arr = move.arr;
        m_start = move.m_start;
        m_end = move.m_end;
        m_length = move.m_length;

        move.m_start = 0;
        move.m_end = 0;
        move.m_length = 0;
        move.arr = nullptr;
        return *this;
    }

    


    void reverse()
    {
        for (int i = 0; i < size / 2; i++)
        {
            std::swap(arr[i], arr[size - i - 1]);
        }
    }

    
    
    void push(const T& elem)
    {
        
        if(m_length == 0)
        {
            arr[m_start] = elem;
            m_length++;
            return;
        }
        
        if (m_end + 1 >= size)
        {
            m_end = -1;
        }
        arr[m_end + 1] = elem;
        m_end++;
        if (m_length != size)
        {
            m_length++;
        }
        
    }

    void pop() // Из-за того что Circular Array работает по принципу FIFO(First in, First out) будем удалять самый первый элемент
    {
        m_start++; // инкрементируем m_start, массив будет начинаться с индекса m_start
        m_length--;
        m_end = m_end + m_length;
    }

    void pop(size_t index)
    {
        if (index >= m_length)
        {
            return;
        }
        for (int i = index; i < m_length; i++)
        {
            this->operator[](i) = this->operator[](i + 1);
        }
        m_length--;
        m_end = m_end + m_length;
    }


    void remove(const T& elem)
    {
        int index = -1;
        for (int i = 0; i < m_length; i++)
        {
            if (this->operator[](i) == elem)
            {
                index = i;
            }
        }
        if (index == -1)
        {
            return;
        }
        pop(index);
    }

    template<size_t SIZE, size_t SIZE2> CircularArray<T, SIZE> operator +(const CircularArray<T, SIZE2>& copy)
    {
        CircularArray<T, SIZE> res;
        for (int i = 0; i < m_length; i++)
        {
            res.push(this->operator[](i));
        }
        for (int i = 0; i < copy.length(); i++)
        {
            res.push(copy[i]);
        }
        return res;

    }

    //size_t start()
    //{
    //    return m_start;
    //}
    //size_t end()
    //{
    //    return m_end;
    //}

    size_t length() const
    {
        return m_length;
    }

    T& operator [](size_t index) const
    {         
        return arr[(m_start + index) % size];
    }



    ~CircularArray()
    {
        ::operator delete[](arr);
    }
};