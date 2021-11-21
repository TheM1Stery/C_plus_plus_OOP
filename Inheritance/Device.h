#pragma once

#include <string>

class Device
{
	std::string m_name;
	size_t m_id;
protected:
	Device(const std::string& name, size_t id);
	bool m_state = false; // true - ON, false - OFF
public:
	void on();
	
	void off();
	
	std::string get_current_state(); // true - ON, false - OFF
	

	std::string name();

	size_t id();
};