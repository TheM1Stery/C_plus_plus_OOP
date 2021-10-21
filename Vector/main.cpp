#include "Vector.h"
#include <iostream>


int main()
{
    Vector<int> vec{1,2};
    Vector<int> vec2{3,4};
    vec = vec2;
    std::cout << vec[0] << ' ' << vec[1];
}