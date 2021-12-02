#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Writer.h"
#include <fstream>
#include <chrono>
#include <iomanip>
class FileWriter : public Writer {

	std::ofstream file_stream;
public:
	FileWriter(const std::string& format, const char* filename);

	void Write(const std::string& message) override;


};