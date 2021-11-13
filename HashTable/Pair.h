#pragma once

template<typename F, typename S> class Pair
{
public:
	Pair(const F& first, const S& second) : first(first), second(second) {}
	F first;
	S second;
};