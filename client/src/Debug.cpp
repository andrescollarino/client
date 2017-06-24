#include "Debug.h"

#include <iostream>
namespace
{
	std::string GetTime()
	{
		time_t t = time(0);
    	struct tm* now = localtime(&t);
    	std::ostringstream tmp;

    	tmp << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday;

    	return tmp.str();
	}

	void WriteFileInternal(std::string text)
	{
		std::ofstream file(LOG_FILE , std::ofstream::app);

		file << text << std::endl;
		file.close();

		std::cout << text << std::endl;
	}
};

void Debug::Log(const char* message)
{
	WriteFileInternal( GetTime() + " : " + std::string(message));
}

void Debug::Log(const std::string& message)
{
	WriteFileInternal(GetTime() + " : " + message);
}

void Debug::LogWarning(const char* message,const char* file,const int line)
{
	WriteFileInternal(GetTime() + " Warning " + std::string(file) + "(" + std::to_string(line) + "): "  + std::string(message));
}

void Debug::LogWarning(const std::string& message,const char* file,const int line)
{
	WriteFileInternal(GetTime() + " Warning " + std::string(file) + "(" + std::to_string(line) + "): "  + message);
}

void Debug::LogError(const char* message,const char* file,const int line,const char* func)
{
	WriteFileInternal(GetTime() + " Error " + std::string(func) + " " + std::string(file) + "(" + std::to_string(line) + "): "  + std::string(message));
}

void Debug::LogError(const std::string& message,const char* file,const int line,const char* func)
{
	WriteFileInternal(GetTime() + " Error " + std::string(func) + " " + std::string(file) + "(" + std::to_string(line) + "): "  + message);
}

void Debug::LogException(const std::exception& error)
{
	WriteFileInternal(GetTime() + " Exception :" + error.what());
}
