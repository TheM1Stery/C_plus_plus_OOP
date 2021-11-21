#include "GamingLaptop.h"

GamingLaptop::GamingLaptop(const std::string& name, size_t id, const std::string& manufacturer, double cpu_frequency)
	: Laptop(name, id, manufacturer), m_cpu_frequency(cpu_frequency)
{
	m_overclock_frequency_limit = cpu_frequency * 1.5;
	m_extreme_cooling = false;
	m_network_priority = false;
	overclocked = false;
	base_cpu_frequency = cpu_frequency;
}


void GamingLaptop::toggle_extreme_cooling()
{
	m_extreme_cooling = !m_extreme_cooling;
}

void GamingLaptop::toggle_network_priority()
{
	m_network_priority = !m_network_priority;
}

void GamingLaptop::overclock(double add_freq)
{
	if (m_cpu_frequency + add_freq >= m_overclock_frequency_limit)
	{
		std::cout << "New frequency is higher than the limit. Check the frequency limit in the settings" << std::endl;
		return;
	}

	if (!m_extreme_cooling)
	{
		std::cout << "To overclock you need to have extreme cooling enabled" << std::endl;
		return;
	}
	m_cpu_frequency += add_freq;
	overclocked = true;
}


void GamingLaptop::revert_back_to_base_freq()
{
	m_cpu_frequency = base_cpu_frequency;
	overclocked = false;
}


std::string GamingLaptop::is_overclocked()
{
	return overclocked ? "This laptop is overclocked" : "This laptop isn't overclocked";
}

double GamingLaptop::current_cpu_frequency()
{
	return m_cpu_frequency;
}

double GamingLaptop::overclock_freq_limit()
{
	return m_overclock_frequency_limit;
}

std::string GamingLaptop::network_priority()
{
	return m_network_priority ? "Network priority is ON" : "Network priority is OFF";
}

std::string GamingLaptop::extreme_cooling()
{
	return m_extreme_cooling ? "Extreme cooling is ON" : "Extreme cooling is OFF";
}









