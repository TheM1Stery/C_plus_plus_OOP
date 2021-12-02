#pragma once

#include "LogLevel.h"
#include "Writer.h"
#include <vector>


class Logger {

	std::string GetLogLevel(LogLevel log_type);
	std::vector<Writer*> writers;
public:
	Logger();
	Logger(std::initializer_list<Writer*> list);
	void AddWriter(Writer* writer);

	void Log(LogLevel log, const std::string& message);
	Logger& operator =(std::initializer_list<Writer*> list);


};
