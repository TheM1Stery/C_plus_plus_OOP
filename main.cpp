#include <iostream>
#include <array>
#include "FixedArray.h"

int main()
{
	FixedArray<int, 5> arr{ {1,2,3,4,5} };
	try {
		arr.At(1337);
	}
	catch (Exception& err)
	{
		std::cout << err.What();
	}
	
}