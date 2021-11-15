#include "Video.h"



Video::Video(size_t size, size_t duration, short day, short month, short year, const std::string& extension)
	: m_size(size), m_duration(duration), m_extension(extension)
{
	m_date_created = std::to_string(day) + '.' + std::to_string(month) + '.' + std::to_string(year);
}


size_t Video::size()
{
	return m_size;
}


size_t Video::duration()
{
	return m_duration;
}

std::string Video::date_created()
{
	return m_date_created;
}

std::string Video::extension()
{
	return m_extension;
}