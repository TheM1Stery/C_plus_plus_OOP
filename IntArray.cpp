#include "IntArray.h"
#include <stdexcept>
#include <initializer_list>

IntArray::IntArray()
{
	actual_size = 0;
	fixed_size = 0;
	int_array = new int[actual_size];
}

IntArray::IntArray(int actual_size) : actual_size(actual_size), fixed_size(0)
{
	if (actual_size < 0)
	{
		this->actual_size = 0;
		int_array = new int[this->actual_size];
		return;
	}
	int_array = new int[actual_size];
}


IntArray::IntArray(std::initializer_list<int> list) : actual_size(list.size()), fixed_size(list.size())
{
	int_array = new int[list.size()];
	int i = 0;
	for (auto& item : list)
	{
		int_array[i++] = item;
	}
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

void IntArray::reserve(size_t reserved_size)
{
	if (empty())
	{
		delete[] int_array;
		int_array = new int[reserved_size];
		actual_size = reserved_size;
		return;
	}
	if (reserved_size <= capacity())
	{
		return;
	}
	int* new_arr = new int[reserved_size];
	for (int i = 0; i < fixed_size; i++)
	{
		new_arr[i] = int_array[i];
	}
	delete[] int_array;
	int_array = new_arr;
	actual_size = reserved_size;
}



void IntArray::push_back(int element) // append
{
	if (capacity() == size())
	{
		if (capacity() == 0)
		{
			actual_size++;
		}
		reserve(actual_size * 2);
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


int& IntArray::operator[](int index)
{
	return int_array[index];
}

void IntArray::operator=(std::initializer_list<int> list)
{
	if (list.size() > actual_size)
	{
		reserve(list.size());
	}
	int i = 0;
	for (auto& item : list)
	{
		int_array[i++] = item;
	}
	fixed_size = list.size();
}

int& IntArray::at(int index)
{
	if (index < 0 || index >= fixed_size)
	{
		throw std::out_of_range("out of range");
	}
	return int_array[index];
}

void IntArray::assign(int count, int value)
{
	if (count > actual_size)
	{
		reserve(count);
	}
	for (int i = 0; i < count; i++)
	{
		int_array[i] = value;
	}
	fixed_size = count;
}

void IntArray::assign(std::initializer_list<int> list)
{
	if (list.size() > actual_size)
	{
		reserve(list.size());
	}
	int i = 0;
	for (auto& item : list)
	{
		int_array[i++] = item;
	}
	fixed_size = list.size();
}


IntArray IntArray::operator+(IntArray& arr)
{
	IntArray res_arr(*this);

	for (int i = 0; i < arr.size(); i++)
	{
		res_arr.push_back(arr[i]);
	}
	return res_arr;
	
}

IntArray& IntArray::operator+=(IntArray& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		this->push_back(arr[i]);
	}
	return *this;
}


IntArray IntArray::operator*(int number)
{
	IntArray res_arr(*this);
	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < size(); j++)
		{
			res_arr.push_back(res_arr[j]);
		}
	}
	return res_arr;
}

IntArray& IntArray::operator*=(int number)
{
	size_t copy = size();
	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < copy; j++)
		{
			this->push_back((*this)[j]);
		}
	}
	return *this;
}


IntArray::~IntArray()
{
	delete[] int_array;
}