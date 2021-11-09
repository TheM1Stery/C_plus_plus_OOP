#include <iostream>
#include "CircularArray.h"

template<size_t SIZE> void print(CircularArray<int, SIZE>& arr)
{
	for (int i = 0; i < arr.length(); i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}


//template<size_t SIZE> void print2(CircularArray<int, SIZE>& arr)
//{
//	for (int i = 0; i < arr.length(); i++)
//	{
//		std::cout << arr.arr[i] << ' ';
//	}
//	std::cout << '\n';
//}



int main()
{
	
	CircularArray<int, 5> arr{ 1,2,3,4,5 };
	CircularArray<int, 3> arr2{ 6,7,8 };
	arr.reverse();
	arr.push(1337);
	print(arr);
	arr.pop();
   print(arr);
	arr.push(1337);
	print(arr);
	arr.remove(2);
	print(arr);
	CircularArray<int, 10> arr3 = arr.operator+<10,3>(arr2);
	print(arr3);
	
	
	
}