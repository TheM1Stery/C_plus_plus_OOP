#include <iostream>
#include "human.h"
#include "house.h"
#include "flat.h"
#include <vector>

int main()
{
	
	Human human{ "Seymur", "Bagirov", "Merdanovic", 18, GENDER::MALE };
	Flat flat({ &human }, "32", 3, true, 8);
	House house({ &flat }, "address-1", 10, true);


	Human human2("Duduw", "Duduwovic", "Duduwbek", 1337, GENDER::OTHER);
	

	
	
}