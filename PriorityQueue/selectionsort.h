#pragma once



#include "Vector.h"
template <typename T> using iter = typename Vector<T>::Iterator;


template<typename T, typename Compare> void selectionSort(iter<T> begin,iter<T> end, Compare compare)
{
	size_t size = end - begin;
	for (int i = 0; i < size - 1; i++)
	{
		int temp = i;
		for (int j = i + 1; j < size; j++)
		{
			if (compare(begin[temp], begin[j]))
			{
				temp = j;
			}
		}
		std::swap(begin[temp], begin[i]);
	}
}