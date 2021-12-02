#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Writer.h"
#include <iostream>
#include <chrono>
#include <iomanip>

class ConsoleWriter : public Writer {

public:
	ConsoleWriter(const std::string& format);

	void Write(const std::string& message) override;


};