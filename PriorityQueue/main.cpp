#include <iostream>
#include "selectionsort.h"
#include "PriorityQueue.h"
#include "comparator.h"
void print_vector(Vector<int>& vec)
{
	for (auto& item : vec)
	{
		std::cout << item << ' ';
	}
	std::cout << '\n';
}



int main()
{
	PriorityQueue<int,greater<int>> queue;
	queue.push(12321332);
	queue.push(999);
	queue.push(123);
	queue.push(-1);
	queue.push(134531513);
	std::cout << queue.top() << ' ' << queue.back() << '\n';
	queue.pop();
	std::cout << queue.top() << ' ' << queue.back() << '\n';
	// Vector<int> vec = queue.get_container();
	// print_vector(vec); 
}