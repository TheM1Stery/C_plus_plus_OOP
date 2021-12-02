#include "Writer.h"

Writer::Writer(const std::string& format)
	: m_format(format) {}



std::string Writer::GetFormat() {
	return m_format;
}