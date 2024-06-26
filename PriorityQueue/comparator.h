#pragma once



template<typename T>struct less
{

	bool operator()(const T& left, const T& right)
	{
		return left < right;
	}
};

template<typename T> struct greater
{
	bool operator()(const T& left, const T& right)
	{
		return left > right;
	}
};