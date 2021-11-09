#pragma once


#include "Vector.h"
#include "selectionsort.h"
#include "comparator.h"

template<typename T, typename Compare = less<T>> class PriorityQueue
{
	Vector<T> queue; 
public:
	
	void push(const T& element)
	{
		queue.push_back(element);
		selectionSort<T>(queue.begin(), queue.end(), Compare());
	}
	void push(T&& element)
	{
		queue.push_back(element);
		selectionSort<T>(queue.begin(), queue.end(), Compare());
	}

	void pop()
	{
		queue.erase(0);
	}


	const T& top() const 
	{
		if (empty())
		{
			throw;
		}
		return queue.front();
	}


	const T& back() const 
	{
		if (empty())
		{
			throw;
		}
		return queue.back();
	}


	bool empty() const 
	{
		return queue.size() == 0;
	}

	void size() const
	{
		return queue.size();
	}

	Vector<T> get_container() const
	{
		return queue;
	}


};