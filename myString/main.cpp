#include <iostream>
#include "String.h"
#include <string>





int main()
{
    

    String my_str = "Hello world";
    String my_str2 = "Jello world";
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
    String my_str3 = "world";
    std::cout << my_str.find(my_str3);
    

}