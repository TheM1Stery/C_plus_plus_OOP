#include "Image.h"


Image::Image(size_t size, int width, int height, short day, short month, short year, const std::string& extension)
	: m_size(size), m_extension(extension)
{
	m_resolution = std::to_string(width) + " x " + std::to_string(height);
	m_date_created = std::to_string(day) + '.' + std::to_string(month) + '.' + std::to_string(year);
}


size_t Image::size()
{
	return m_size;
}


std::string Image::extension()
{
	return m_extension;
}


std::string Image::resolution()
{
	return m_resolution;
}


std::string Image::date_created()
{
	return m_date_created;
}
