#include "Vector.h"
#include <iostream>






int main()
{
    Vector<Vector<int>> vec{{1,2,3}, {4,5,6}, {7,8,9}};
    for (auto& item: vec)
    {
        for (auto& item2 : item)
        {
            std::cout << item2 << ' ';
        }
        std::cout << '\n';
    }
}