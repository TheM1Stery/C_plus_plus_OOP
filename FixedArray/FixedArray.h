#pragma once

#include <cstddef>
#include <initializer_list>
#include "MyExceptions.h"




template<typename FixedArray> class FixedArrayIterator{
public:
	using Type = typename FixedArray::Type;
	
	FixedArrayIterator(Type* iterator) : iterator(iterator) {}

	FixedArrayIterator& operator ++(){
		++iterator;
		return *this;
	}
	
	FixedArrayIterator operator ++(int){
		FixedArrayIterator cpy(*this);
		++(*this);
		return cpy;
	}

	FixedArrayIterator& operator --(){
		--iterator;
		return *this;
	}

	FixedArrayIterator operator --(int){
		FixedArrayIterator cpy(*this);
		--(*this);
		return cpy;
	}

	
	Type& operator* (){
		return *iterator;
	}

	Type* operator->(){
		return iterator;
	}

	Type& operator[](size_t index){
		return *(iterator + index);
	}

	size_t operator + (const FixedArrayIterator& it){
		return iterator + it.iterator;
	}

	size_t operator - (const FixedArrayIterator& it){
		return iterator - it.iterator;
	}

	bool operator == (const FixedArrayIterator& it){
		return iterator == it.iterator;
	} 

	bool operator != (const FixedArrayIterator& it){
		return iterator != it.iterator;
	}

	

	

private:
	Type* iterator;
};




template<typename T, std::size_t SIZE> class FixedArray
{
	T array[SIZE]{};
	size_t m_length = 0;
public:
	using Type = T;
	using Iterator = FixedArrayIterator<FixedArray>;
	FixedArray(T(&&a)[SIZE])
	{
		int i = 0;
		for (i = 0; i < SIZE; i++)
		{
			array[i] = a[i];
		}
		m_length = i;
	}

	T& operator[](size_t index)
	{
		return array[index];
	}

	const T& operator[](size_t index) const 
	{
		return array[index];
	}

	void PushBack(const T& elem)
	{
		if (m_length + 1 > SIZE)
		{
			throw LimitException("Your array is full");
		}
		array[m_length] = elem;
		m_length++;
	}
	

	T& At(size_t index)
	{
		if (index >= SIZE)
		{
			throw OutOfRange("Array index out of bounds");
		}
		return array[index];
	}
	const T& At(size_t index) const
	{
		if (index >= SIZE)
		{
			throw OutOfRange("Array index out of bounds");
		}
		return array[index];
	}

	Iterator begin(){
		return array;
	}

	Iterator end(){
		return array + SIZE;
	}

	

	




};