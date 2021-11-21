#pragma once

#include "Laptop.h"

#include <cstddef>

class GamingLaptop : public Laptop
{
	bool overclocked;
	bool m_network_priority;
	bool m_extreme_cooling;
	double m_cpu_frequency;
	double m_overclock_frequency_limit;
	double base_cpu_frequency;
public:
	GamingLaptop(const std::string& name, size_t id, const std::string& manufacturer, double cpu_frequency);
	
	void toggle_extreme_cooling();

	void toggle_network_priority();
	
	void overclock(double add_freq);

	void revert_back_to_base_freq();

	std::string is_overclocked();

	double current_cpu_frequency();

	double overclock_freq_limit();

	std::string network_priority();

	std::string extreme_cooling();

	
	

};