#pragma once

#include "Exception.h"


class LimitException : public Exception
{
public:
	LimitException(const char* message) : Exception(message) {}
	const char* What() override
	{
		return message;
	}
};