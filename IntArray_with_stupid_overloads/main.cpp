#include <iostream>
#include "IntArray.h"
#include <random>
#include <ctime>


std::default_random_engine eng(time(nullptr));
std::uniform_int_distribution<int> range(10, 100);


//void print_array(IntArray& arr)
//{
//	for (int i = 0; i < arr.size(); i++)
//	{
//		std::cout << arr[i] << ' ';
//	}
//	std::cout << '\n';
//}

std::ostream& operator << (std::ostream& stream, IntArray& arr)
{
	for (int i = 0; i < arr.fixed_size; i++)
	{
		stream << arr.int_array[i] << ' ';
	}
	stream << '\n';
	return stream;
}

std::istream& operator>>(std::istream& stream, IntArray& arr)
{
	int count;
	std::cout << "How many elements will you add\n> ";
	stream >> count;
	if (arr.actual_size < arr.fixed_size + count)
	{
		arr.reserve(count);
	}
	arr.fixed_size += count;
	for (int i = 0; i < count; i++)
	{
		stream >> arr.int_array[i];
	}
	return stream;
}







int main()
{
	// IntArray arr;
	// fill(arr, 3);
	// print_array(arr);
	// arr[0] = 1337;
	// print_array(arr);
	/*IntArray arr{1,2,3,4,5,6,7};
	print_array(arr);
	*/
	
	IntArray arr{1,2,3};
	IntArray arr2{1,2,3,4};
	IntArray arr3 = arr + arr2;
	std::cout << arr3;
	
	
	
	
	

	


}