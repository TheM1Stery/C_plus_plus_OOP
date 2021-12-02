#pragma once

#include "WriterInterface.h"

class Writer : public WriterInterface {
protected:
	std::string m_format;
	Writer(const std::string& format);
		
public:

	std::string GetFormat();

};