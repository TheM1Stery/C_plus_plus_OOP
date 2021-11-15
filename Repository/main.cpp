#include <iostream>

//#define VECTOR
//#define LLIST
#define RAW


#include "Repository.h"
#include "Image.h"






int main()
{
	
	Repository<Image> repo;
	repo.emplace_back(1000, 1280, 720, 26, 5, 2003, "png");
	repo.emplace_back(1000, 1280, 720, 26, 5, 2004, "jpg");
	std::cout << repo[0].extension() << '\n';
	std::cout << repo[1].extension() << '\n';
	repo.erase(0);
	std::cout << repo[0].extension() << '\n';
	//std::cout << repo[1].size();
	
	
}

