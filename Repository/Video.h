#pragma once


#include <string>

class Video
{
	size_t m_size; // in bytes
	size_t m_duration; // in seconds
	std::string m_date_created;
	std::string m_extension;
public:
	explicit Video(size_t size, size_t duration, short day, short month, short year, const std::string& m_extension);

	size_t size();

	size_t duration();


	std::string date_created();

	std::string extension();

	
};