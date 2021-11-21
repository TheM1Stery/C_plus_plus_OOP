#pragma once

#include "Device.h"

#include <iostream>


class Laptop : public Device
{
	std::string m_manufacturer;
	bool touchpad = true; // true = ON, false = OFF
public:
	Laptop(const std::string& name, size_t id, const std::string& manufacturer);
		
	void open_browser();
	

	void toggle_touchpad();
	

	std::string touchpad_status();
	
	
};