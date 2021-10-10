#include "IntArray.h"



IntArray::IntArray()
{
	actual_size = 32;
	fixed_size = 0;
	int_array = new int[actual_size];
}

IntArray::IntArray(int actual_size) : actual_size(actual_size)
{
	fixed_size = 0;
	if (actual_size < 0)
	{
		this->actual_size = 32;
		int_array = new int[this->actual_size];
		return;
	}
	int_array = new int[actual_size];
}





IntArray::IntArray(const IntArray& arr)
{
	
	int* new_arr = new int[arr.actual_size];
	for (int i = 0; i < arr.fixed_size; i++)
	{
		new_arr[i] = arr.int_array[i];
	}
	actual_size = arr.actual_size;
	fixed_size = arr.fixed_size;
}

int IntArray::size()
{
	return fixed_size;
}

void IntArray::push_back(int element)
{

}
