#pragma once

#include "Device.h"


class Smartphone : public Device
{
	std::string m_manufacturer;
public:
	Smartphone(const std::string& name, size_t id, const std::string& manufacturer);
	
	void take_photo(); // to be improved

	void record_video(); // to be improved
	
	void set_alarm(int hours); // to be improved
		
	std::string manufacturer();
};