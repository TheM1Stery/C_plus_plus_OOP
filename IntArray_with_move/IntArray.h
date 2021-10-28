#pragma once
#include <iostream>
#include <initializer_list>
class IntArray
{
	size_t actual_size; // the size that array actually has
	size_t fixed_size; // the size which the user gets
	int* int_array;
public:

	friend std::ostream& operator <<(std::ostream& stream, IntArray& arr);
	friend std::istream& operator >> (std::istream& stream, IntArray& arr);

	IntArray(); // default constructor
	IntArray(int actual_size); // constructor which reserves memory
	IntArray(std::initializer_list<int> list); // constructor with initliazer list
	IntArray(const IntArray& arr); // Copy constructor
	IntArray(IntArray&& arr);


	IntArray& operator= (IntArray&& arr);
	IntArray& operator= (const IntArray& arr);



	size_t size(); // get the size of the IntArray    (fixed_size)
	size_t capacity(); // get the capacity of the IntArray  (actual_size)
	void reserve(size_t); // Reserve memory for the IntArray
	int& operator[](int index); // access the element of the array
	void operator=(std::initializer_list<int> list); // reassign the values of the array using initiliazer list
	int& at(int index); // access the element of the array
	bool empty(); // check if the array is empty
	void push_back(int element); // put the element to the end of the array
	void assign(int count, int value); // asssign values to the array
	void assign(std::initializer_list<int> list); // assign values to the array using initiliazer list
	void pop_back(); // remove the last element
	void erase(int index); // erase the element at the given index
	
	IntArray operator+(IntArray& arr);
	IntArray& operator+=(IntArray& arr);
	IntArray operator*(int number);
	IntArray& operator*=(int number);
	void operator()(int number);

	
	~IntArray(); // destructor, just deletes the array


};
