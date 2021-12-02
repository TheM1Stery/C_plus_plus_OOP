#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ConsoleWriter.h"
#include "FileWriter.h"
#include "Logger.h"



int main()
{

	std::string format = "%D %T";
	/*ConsoleWriter cwriter(format);
	FileWriter fwriter(format, "Logs\\log.txt");*/
	ConsoleWriter* cwriter = new ConsoleWriter(format);
	FileWriter* fwriter = new FileWriter(format, "Logs\\log.txt");
	Logger logger{ cwriter, fwriter };
	/*logger.AddWriter(cwriter);
	logger.AddWriter(fwriter);*/
	logger.Log(LogLevel::info, "Seymur joined the system");
	logger.Log(LogLevel::warn, "Seymur isn't allowed to come here");
	logger.Log(LogLevel::error, "User Seymur couldn't be deleted. Terminating the program");
	delete cwriter;
	delete fwriter;
	



}