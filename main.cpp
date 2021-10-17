#include <iostream>
#include "IntArray.h"
#include <random>
#include <ctime>


std::default_random_engine eng(time(nullptr));
std::uniform_int_distribution<int> range(10, 100);


void print_array(IntArray& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}

void selection_sort(IntArray& arr)
{
	if (arr.empty())
	{
		return;
	}
	for (int i = 0; i < arr.size() - 1; i++)
	{
		int temp = i;
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[j] < arr[temp])
			{
				temp = j;
			}
		}
		std::swap(arr[i], arr[temp]);
	}

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
	while (true)
	{
		IntArray arr{ 1,2,3 };
		IntArray arr2 = arr * 2;
	}
	
	
	
	

	


}