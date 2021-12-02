#include "Logger.h"


std::string Logger::GetLogLevel(LogLevel log_type) {
	switch (log_type) {
	case LogLevel::error:
		return "Error: ";
	case LogLevel::info:
		return "Info: ";
	case LogLevel::warn:
		return "Warning: ";
	}
}

Logger::Logger() = default;
Logger::Logger(std::initializer_list<Writer*> list) {
	writers = list;
}

void Logger::AddWriter(Writer * writer) {
	writers.push_back(writer);
}

void Logger::Log(LogLevel log, const std::string & message) {

	for (int i = 0; i < writers.size(); i++)
	{
		writers[i]->Write(GetLogLevel(log) + message);
	}
}

Logger& Logger::operator= (std::initializer_list<Writer*> list) {

	writers = list;
	return *this;
}
