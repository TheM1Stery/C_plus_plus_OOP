#include "Audio.h"



Audio::Audio(size_t size, size_t duration, size_t bitrate, const std::string& artist, const std::string& title, const std::string& extension)
	: m_size(size), m_duration(duration), m_bitrate(bitrate), m_artist(artist), m_title(title), m_extension(extension)
{}


size_t Audio::size()
{
	return m_size;
}

size_t Audio::duration()
{
	return m_duration;
}

size_t Audio::bitrate()
{
	return m_bitrate;
}

std::string Audio::artist()
{
	return m_artist;
}

std::string Audio::title()
{
	return m_title;
}

std::string Audio::extension()
{
	return m_extension;
}