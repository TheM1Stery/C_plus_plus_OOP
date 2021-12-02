#pragma once


#include <string>


struct WriterInterface{
	virtual void Write(const std::string& message) = 0;
	virtual ~WriterInterface() = default;
};