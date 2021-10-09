#include <iostream>
#include <string.h>
#define SIZE 100
#define GARBAGE "AMOGUUUUUS"
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
	Student(const char* name, int day, int month, int year, const char* number, const char* city_S,
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

	const char* get_school_city()
	{
		if (city_s == nullptr)
		{
			return "0";
		}
		return city_s;
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

	void set_student_group(const char* group)
	{
		if (group == nullptr)
		{
			return;
		}
		strcpy_s(this->group, SIZE, group);
	}

	const char* get_student_group()
	{
		if (group == nullptr)
		{
			return "0";
		}
		return group;
	}

	//friend std::ostream& operator << (std::ostream& stream, Student*& student);
	void info()
	{
		std::cout << "Student's name: " << get_name() << '\n';
		std::cout << "Student's day of birth: " << get_day() << '.' << get_month() << '.' << get_year() << '\n';
		std::cout << "Student's number: " << get_number() << '\n';
		std::cout << "Student's city: " << get_student_city() << '\n';
		std::cout << "Student's country: " << get_student_country() << '\n';
		std::cout << "Student's school: " << get_school() << '\n';
		std::cout << "Student's group: " << get_student_group() << '\n';
		std::cout << "Student's school's city: " << get_student_city() << '\n';
		std::cout << "Student's school's country: " << get_school_country() << '\n';
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


class Point
{
	float x, y, z;
public:
	Point()
	{
		x = 0, y = 0, z = 0;
	}
	// Point() : x(this->x), y(this->y), z(this->z)
	// {
	// }
	Point(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	//friend std::ostream& operator<< (std::ostream& stream, Point*& point);
	void info()
	{
		std::cout << "x: " << x << '\n';
		std::cout << "y: " << y << '\n';
		std::cout << "z: " << z << '\n';
	}
	void set_x(float x)
	{
		this->x = x;
	}
	float get_x()
	{
		return x;
	}
	void set_y(float y)
	{
		this->y = y;
	}
	float get_y()
	{
		return y;
	}
	void set_z(float z)
	{
		this->z = z;
	}
	float get_z()
	{
		return z;
	}
};


// std::ostream& operator<< (std::ostream& stream, Point*& point)
// {
// 	stream << "Current position: \n";
// 	stream << "x: " << point->x << '\n';
// 	stream << "y: " << point->y << '\n';
// 	stream << "z: " << point->z << '\n';

// }

// std::ostream& operator<< (std::ostream& stream, Student*& student)
// {
// 	stream << "Student's name: " << student->name << '\n';
// 	stream << "Student's day of birth: " << student->day << '.' << student->month << '.' << student->year << '\n';
// 	stream << "Student's number: " << student->number << '\n';
// 	stream << "Student's city: " << student->city_S << '\n';
// 	stream << "Student's country: " << student->country_S << '\n';
// 	stream << "Student's school: " << student->school << '\n';
// 	stream << "Student's group: " << student->group << '\n';
// 	stream << "Student's school's city: " << student->city_s << '\n';
// 	stream << "Student's school's country " << student->country_s << '\n';
// 	return stream;
// }



int main()
{
	//Student* student = new Student("Name", 26, 5, 2003, "000000", "City", "Country", "School", "City", "Country", "Group");
	////std::cout << student;
	//student->info();
	//student->set_number("727272");
	//std::cout << '\n';
	//student->info();
	//delete student;
	Point* point = new Point(10, 20, 30);
	point->info();

}
