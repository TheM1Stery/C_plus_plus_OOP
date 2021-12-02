#include "ConsoleWriter.h"


ConsoleWriter::ConsoleWriter(const std::string& format)
	: Writer(format) {}

void ConsoleWriter::Write(const std::string& message)  {
	std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	//file_stream << std::localtime()
	std::cout << '[' << std::put_time(std::localtime(&now), m_format.c_str()) << ']' << ' ' << message << '\n';
}
