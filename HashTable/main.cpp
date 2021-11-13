#include <iostream>
#include <unordered_map>
#include "HashTable.h"



int main()
{
	HashTable<std::string, int> table;
	table["Hello"] = 1337;
	std::cout << table.at("Salam") << '\n';
	
	
}


