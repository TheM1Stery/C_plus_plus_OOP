#include <iostream>
#include "reservoir.h"
#include "Vector.h"

int main()
{
    Reservoir res{ "Programmer", "Lake", 100, 100, 100 };
    Reservoir res2{ "Programmer2", "River", 100, 100, 100 };
    Vector<Reservoir> vec{ res,res2 };
    std::cout << vec[0].get_name() << '\n';
    std::cout << vec["Programmer"].get_name() << '\n';

    std::cout << vec[1].get_name() << '\n';
    std::cout << vec["Programmer2"].get_name() << std::endl;
    std::cout << vec.size() << '\n';

    vec.remove("Programmer");
    std::cout << vec.size() << '\n';
    std::cout << vec[0].get_name();



    const Vector<Reservoir>vec2{ vec };
    std::cout << vec2[0].get_name() << '\n';
    std::cout << vec2["Programmer"].get_name() << '\n';

    std::cout << vec2[1].get_name() << '\n';
    std::cout << vec2["Programmer2"].get_name() << std::endl;
    std::cout << vec2.size() << '\n';

    
}