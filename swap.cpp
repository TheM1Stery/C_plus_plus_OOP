#include <iostream>
#include "Vector.h"
#include "swap.h"


void print_vector(Vector<int> vec)
{
    for (int i =0; i < vec.size(); i++)
    {
        std::cout << vec[i] << ' ';
    }
    std::cout << '\n';
}


int main()
{
    Vector<int> vec{1,2,3,4,5};
    Vector<int> vec2{1,2,3};
    vec.push_back(10);
    vec2.push_back(20);
    print_vector(vec);
    print_vector(vec2);
    swap(vec, vec2);
    print_vector(vec);
    print_vector(vec2);
}



