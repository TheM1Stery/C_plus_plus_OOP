#include <iostream>
#include <unordered_map>
//#include "HashTable.h" // HashTable with 2D vector
// HashTable with vector of linked Lists
#include "HashTableLL.h"  
template<typename K, typename T> void print_map(const HashTable<K, T>& map)
{
	for (auto& item : map.keys())
	{
		std::cout << item << ": " << map.at(item) << "\n";
	}
}


int main()
{
	
	HashTable<std::string, int> table = { {"Hello",2}, {"Hello", 5} };
	
	HashTable<std::string,int> table2 = table;
	print_map(table2);
	
	
	
	
	
	
	

}


