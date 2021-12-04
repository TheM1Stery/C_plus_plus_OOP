#include <iostream>
#include <array>
#include "FixedArray.h"

int main()
{
	FixedArray<int, 3> arr = {{1,2,3}};
	
	for (auto iterator =  arr.begin(); iterator != arr.end(); ++iterator){
		auto& item = *iterator;
		std::cout << item << ' ';
	}

	
}