#pragma once

class Exception
{
	
public:
	virtual const char* What() = 0;
protected:
	const char* message;
	Exception(const char* msg) : message(msg) {}
};