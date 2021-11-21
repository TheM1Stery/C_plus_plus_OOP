#include "Laptop.h"



Laptop::Laptop(const std::string& name, size_t id, const std::string& manufacturer)
	: Device(name, id), m_manufacturer(manufacturer) {}

void Laptop::open_browser()
{
	if (m_state && touchpad)
	{
		std::cout << "Browser opened\n";
		return;
	}
	std::cout << "Failed to open browser.\n";
}

void Laptop::toggle_touchpad()
{
	touchpad = !touchpad;
}

std::string Laptop::touchpad_status()
{
	return touchpad ? "Touchpad is active" : "Touchpad is off";
}