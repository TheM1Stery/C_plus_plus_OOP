#include <iostream>
#include "IntArray.h"
#include <vector>


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


	
		IntArray arr{ 1,2,3 };
		std::cout << arr[0] << '\n';

		arr(3);
		std::cout << arr;
		IntArray arr2;
		arr2 = std::move(arr);

		IntArray arr3;
		arr3 = arr2;
	
	
	
	
	
	
	
	
	

	


}