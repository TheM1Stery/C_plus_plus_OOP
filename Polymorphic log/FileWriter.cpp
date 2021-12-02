#include "FileWriter.h"



FileWriter::FileWriter(const std::string& format, const char* filename)
	: Writer(format) {}

void FileWriter::Write(const std::string& message)  {
	file_stream.open("Logs\\log.txt", std::ios::app);
	std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	//file_stream << std::localtime()
	file_stream << '[' << std::put_time(std::localtime(&now), m_format.c_str()) << ']' << ' ' << message << '\n';
	file_stream.close();
}
