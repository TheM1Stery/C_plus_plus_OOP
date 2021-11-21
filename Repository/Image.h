#pragma once

#include <string>

class Image
{
	size_t m_size; // in bytes
	
	std::string m_extension;
	std::string m_resolution;
	std::string m_date_created;

public:
	Image() = default;
	explicit Image(size_t size, int width, int height, short day, short month, short year, const std::string& extension);
		
	size_t size();

	std::string extension();

	std::string resolution();

	std::string date_created();
};