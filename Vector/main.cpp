#include <iostream>
#include <unordered_map>





int main()
{
    std::unordered_map<std::string, int> map;
    map["Hello"];
    std::cout << map["Hello"];
}