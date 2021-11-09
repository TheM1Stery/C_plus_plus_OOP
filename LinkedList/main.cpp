#include <iostream>
#include "LinkedList.h"
#include "Vector.h"
#include <list>

void print_all_nodes(const LinkedList<int>& list)
{
	for (auto& item : list)
	{
		std::cout << item << ' ';
	}
	std::cout << '\n';
}

void advance(LinkedList<int>::Iterator& it, int count)
{
	for (int i = 0; i < count; i++)
	{
		++it;
	}
}

void prev(LinkedList<int>::Iterator& it, int count)
{
	for (int i = 0; i < count; i++)
	{
		--it;
	}
}



int main()
{
	/*while (true)
	{
		LinkedList<int> list;
		list.push_back(10);
		list.push_back(20);
		list.push_back(30);

		LinkedList<int> list2;
		list2.push_back(20);
		list2.push_back(30);
		list2.push_back(50);

		list2 = std::move(list);
	}*/

	/*LinkedList<int> list({ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 });
	std::cout << list.begin().operator*();
	list.reverse();*/
	

	
	
	/*it = list.insert(it, 30);

	print_all_nodes(list);*/

	
	LinkedList<int> list{ 1,2,3,4,5,6,7 };

	print_all_nodes(list);

	LinkedList<int>::Iterator it = list.begin();
	advance(it, list.length() - 1);
	it = list.insert(it, 20);

	print_all_nodes(list);
	it = list.insert(it, 30);
	print_all_nodes(list);
	it = list.insert(it, 70);
	print_all_nodes(list);
	it = list.erase(it);
	std::cout << *it << '\n';
	print_all_nodes(list);
	it = list.erase(it);
	std::cout << *it << '\n';
	print_all_nodes(list);
	
	



	

	
	
	
	
	 
	
}