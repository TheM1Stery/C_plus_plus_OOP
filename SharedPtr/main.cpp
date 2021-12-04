#include <iostream>
#include "SharedPtr.h"

void increment(SharedPtr<int> ptr) {

	(*ptr)++;
	std::cout << ptr.get_count() << '\n';
}





int main() {
	
	SharedPtr<int> ptr(new int{ 5 });
	std::cout << *ptr << '\n';
	increment(ptr);
	std::cout << *ptr << '\n';
	std::cout << ptr.get_count() << '\n';
	
	
}