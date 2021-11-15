#pragma once

#include <string>

class Audio
{
	size_t m_size; // in bytes
	size_t m_duration; // in seconds
	size_t m_bitrate;
	std::string m_artist;
	std::string m_title;
	std::string m_extension;
public:
	explicit Audio(size_t size, size_t duration, size_t bitrate, const std::string& artist, const std::string& title, const std::string& extension);

	size_t size();

	size_t duration();

	size_t bitrate();

	std::string artist();

	std::string title();
	
	std::string extension();
};