#include <iostream>
#include "LinkedList.h"

void print_all_nodes(LinkedList<int>& list)
{
	for (auto& item : list)
	{
		std::cout << item << ' ';
	}
	std::cout << '\n';
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
	
	LinkedList<int> list({1,2,3,4,5,6,7});
    list.push_back(10);
	list.push_back(20);
    list.push_back(30);
    list.push_back(40);
	list.push_back(50);
    list.push_back(60);
    list.push_back(70);
	list.push_back(80);
    list.push_back(90);
	print_all_nodes(list);
	
	print_all_nodes(list);

	print_all_nodes(list);

	print_all_nodes(list);

	print_all_nodes(list);

	
	
	

}