#pragma once
#include <iostream>
class IntArray
{
	size_t actual_size; // the size that array actually has
	size_t fixed_size; // the size which the user gets
	int* int_array;
public:
	IntArray(); // default constructor
	IntArray(int actual_size); // constructor which reservers memory
	IntArray(const IntArray& arr); // Copy constructor
	


	
	size_t size(); // get the size of the IntArray    (fixed_size)
	size_t capacity(); // get the capacity of the IntArray  (actual_size)
	void reserve(size_t); // Reserve memory for the IntArray
	int& at(int index); // access the element of the array
	bool empty(); // check if the array is empty
	void push_back(int element); // put the element to the end of the array
	void assign(int index, int item); // change the value of the element at the given index
	void pop_back(); // remove the last element
	void erase(int index); // erase the element at the given index
	~IntArray();
	

};

