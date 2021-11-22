#pragma once
#include "Exception.h"



class OutOfRange : public Exception
{
public:
	OutOfRange(const char* message) : Exception(message) {}
	const char* What() override
	{
		return message;
	}
};