#include <iostream>
#include "String.h"
#include <string>





int main()
{
    

    String my_str = "Bello world";
    String my_str2 = "Aello world";
    /*std::cout << my_str + "\n";
    std::cout << my_str.compare(my_str2) << '\n';
    my_str.append(" and my friends");
    std::cout << my_str.capacity() << ' ' << my_str.size() << '\n';
    std::cout << my_str;
    String my_str3 = "";
    my_str3 += (my_str + " and my friends");
    if (my_str < my_str2)
    {
        std::cout << "higher";
    }*/
    if(my_str2 > my_str)
    {
        std::cout << "Higher";
    }

}