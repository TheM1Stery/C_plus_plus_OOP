#include <iostream>
#include <string.h>
#define SIZE 100

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

		this->day = day;
		this->month = month;
		this->year = year;

		
		this->name = new char[size];
		this->number = new char[size];
		this->city_S = new char[size];
		this->country_S = new char[size];
		this->school = new char[size];
		this->city_s = new char[size];
		this->country_s = new char[size];
		this->group = new char[size];

		strcpy_s(this->name, size, name);
		strcpy_s(this->number, size, number);
		strcpy_s(this->city_S, size, city_S);
		strcpy_s(this->country_S, size, country_S);
		strcpy_s(this->school, size, school);
		strcpy_s(this->city_s, size, city_s);
		strcpy_s(this->country_s, size, country_s);
		strcpy_s(this->group, size, group);
		
	}


	void set_day(int day)
	{
		if (day < 1 || day > 31)
		{
			return;
		}
		this->day = day;
	}

	int get_day()
	{
		if (day < 1 || day > 31)
		{
			return 0;
		}
		return day;
	}

	void set_month(int month)
	{
		if (month < 1 || month > 12)
		{
			return;
		}
		this->month = month;
	}

	int get_month()
	{
		if (month < 1 || month > 12)
		{
			return 0;
		}
		return month;
	}

	void set_year(int year)
	{
		if (year < 1)
		{
			return;
		}
		this->year = year;
	}

	int get_year()
	{
		if (year < 1)
		{
			return 0;
		}
		return year;
	}

	void set_name(const char* name)
	{
		if (name == nullptr)
		{
			return;
		}
		strcpy_s(this->name, SIZE, name);
	}

	const char* get_name()
	{
		if (name == nullptr)
		{
			return "0";
		}
		return name;
	}

	void set_number(const char* number)
	{
		if (number == nullptr)
		{
			return;
		}
		strcpy_s(this->number, SIZE, number);
	}

	const char* get_number()
	{
		if (number == nullptr)
		{
			return "0";
		}
		return number;
	}

	void set_student_city(const char* city_S)
	{
		if (city_S == nullptr)
		{
			return;
		}
		strcpy_s(this->city_S, SIZE, city_S);
	}

	const char* get_student_city()
	{
		if (city_S == nullptr)
		{
			return "0";
		}
		return city_S;
	}
	void set_student_country(const char* country_S)
	{
		if (country_S == nullptr)
		{
			return;
		}
		strcpy_s(this->country_S, SIZE, country_S);
	}

	const char* get_student_country()
	{
		if (country_S == nullptr)
		{
			return "0";
		}
		return country_S;
	}

	void set_school(const char* school)
	{
		if (school == nullptr)
		{
			return;
		}
		strcpy_s(this->school, SIZE, school);
	}

	const char* get_school()
	{
		if (school == nullptr)
		{
			return "0";
		}
		return school;
	}

	void set_school_city(const char* city_s)
	{
		if (city_s == nullptr)
		{
			return;
		}
		strcpy_s(this->city_s, SIZE, city_s);
	}
	
	const char* get_school_city(const char* city_s)
	{
		if (city_s == nullptr)
		{
			return "0";
		}
		strcpy_s(this->city_s, SIZE, city_s);
	}

	void set_school_country(const char* country_s)
	{
		if (country_s == nullptr)
		{
			return;
		}
		strcpy_s(this->country_s, SIZE, country_s);
	}

	const char* get_school_country()
	{
		if (country_s == nullptr)
		{
			return "0";
		}
		return country_s;
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
