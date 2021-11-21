#define _CRT_SECURE_NO_WARNINGS
#include "Smartphone.h"

#include <iostream>

#include <chrono>
#include <iomanip>

Smartphone::Smartphone(const std::string& name, size_t id, const std::string& manufacturer)
	: Device(name, id), m_manufacturer(manufacturer) {}

void Smartphone::take_photo()
{
	if (m_state)
	{
		std::cout << "Photo taken\n";
		return;
	}
	std::cout << "Failed to take the photo. Try to turn on your phone\n";
}

void Smartphone::record_video()
{
	if (m_state)
	{
		std::cout << "Video recorded\n";
		return;
	}
	std::cout << "Failed to record the video. Try to turn on your phone\n";
}

void Smartphone::set_alarm(int hours)
{
	if (m_state)
	{
		const std::chrono::time_point<std::chrono::system_clock> current = std::chrono::system_clock::now();
		const std::time_t value = std::chrono::system_clock::to_time_t(current + std::chrono::hours(hours));
		std::cout << "Your alarm was set to " << std::put_time(std::localtime(&value), "%D %T.\n");
		return;
	}
	std::cout << "Failed to set the alarm. Try to turn on your phone\n";
}


std::string Smartphone::manufacturer()
{
	return m_manufacturer;
}