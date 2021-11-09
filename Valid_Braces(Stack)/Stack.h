#pragma once

#include "Vector.h"


template<typename T> class Stack
{
	Vector<T> stack;
public:
	T& top()
	{
		return stack.back();
	}

	const T& top() const
	{
		return stack.back();

	}
	
	bool empty() const 
	{
		return stack.size() == 0;
	}

	void push(const T& elem)
	{
		stack.push_back(elem);
	}
	void push(T&& elem)
	{
		stack.push_back(elem);
	}

	void pop()
	{
		stack.pop_back();
	}



	
	size_t size() const
	{
		return stack.size();
	}

};