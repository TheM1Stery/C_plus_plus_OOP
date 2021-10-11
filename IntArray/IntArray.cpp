#include "IntArray.h"



IntArray::IntArray()
{
	actual_size = 0;
	fixed_size = 0;
	int_array = new int[actual_size];
}

IntArray::IntArray(int actual_size) : actual_size(actual_size)
{
	fixed_size = 0;
	if (actual_size < 0)
	{
		this->actual_size = 0;
		int_array = new int[this->actual_size];
		return;
	}
	int_array = new int[actual_size];
}





IntArray::IntArray(const IntArray& arr)
{
	
	int_array = new int[arr.actual_size];
	for (int i = 0; i < arr.fixed_size; i++)
	{
		int_array[i] = arr.int_array[i];
	}
	actual_size = arr.actual_size;
	fixed_size = arr.fixed_size;
}

size_t IntArray::size()
{
	return fixed_size;
}

size_t IntArray::capacity()
{
	return actual_size;
}

bool IntArray::empty()
{
	if (!size())
	{
		return true;
	}
	return false;
}

void IntArray::reserve(size_t resevered_size)
{
	if (empty())
	{
		delete[] int_array;
		int_array = new int[resevered_size];
		actual_size = resevered_size; 
	}

}

void IntArray::push_back(int element) // append
{
	if (capacity() == size())
	{
		if (capacity() == 0)
		{
			actual_size++;
		}
		int* new_arr = new int[actual_size * 2];
		for (int i = 0; i < actual_size; i++)
		{
			new_arr[i] = int_array[i];
		}
		delete[] int_array;
		int_array = new_arr;
		actual_size *= 2;
	}
	int_array[fixed_size] = element;
	fixed_size++;
}

void IntArray::pop_back()
{
	if (!empty())
	{
		fixed_size--;
	}
}

void IntArray::erase(int index)
{
	if (empty())
	{
		return;
	}
	for (int i = index; i < fixed_size - 1; i++)
	{
		int_array[i] = int_array[i + 1];
	}
	fixed_size--;
}


int& IntArray::at(int index)
{
	return int_array[index];
}

void IntArray::assign(int index, int item)
{
	if (index >= size())
	{
		return;
	}
	int_array[index] = item;
}


IntArray::~IntArray()
{
	delete[] int_array;
}