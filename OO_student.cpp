#include <iostream>
#include <string.h>


class Student
{
	char* name;
	int day, month, year;
	char* number;
	char* city_S;
	char* country_S;
	char* school;
	char* city_s;
	char* country_s;
	char* group;
public:
	Student()
	{
		constexpr size_t size = 100;
		char* name = new char[size];
		char* number = new char[size];
		char* city_S = new char[size];
		char* country_S = new char[size];
		char* school = new char[size];
		char* city_s = new char[size];
		char* country_s = new char[size];
		char* group = new char[size];
		int day = 0, month = 0, year = 0;
	}
	Student(const char* name,int day, int month, int year, const char* number, const char* city_S,
	const char* country_S, const char* school, const char* city_s, const char* country_s, const char* group)
	{
		constexpr size_t size = 100;
		char* name = new char[size];
		char* number = new char[size];
		char* city_S = new char[size];
		char* country_S = new char[size];
		char* school = new char[size];
		char* city_s = new char[size];
		char* country_s = new char[size];
		char* group = new char[size];
	}



	~Student()
	{
		delete[] name;
		delete[] number;
		delete[] city_S;
		delete[] country_S;
		delete[] school;
		delete[] city_s;
		delete[] country_s;
		delete[] group;
	}
};





int main()
{

}
