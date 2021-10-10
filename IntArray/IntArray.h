#pragma once

class IntArray
{

	size_t actual_size; // the size that array actually has
	size_t fixed_size; // the size which the user gets
	int* int_array;
public:
	IntArray();
	IntArray(int actual_size);
	IntArray(const IntArray& arr);

	int size();
	void push_back(int element);
	


};

