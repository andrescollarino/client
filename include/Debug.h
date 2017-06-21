#pragma once

#include <sstream>
#include <fstream>
#include <ctime>
#include <exception>
#include <string>

#define LOG_FILE "log.txt"

#define DEBUG_LOG(x) Debug::Log(x)
#define DEBUG_WARNING(x) Debug::LogWarning(x,__FILE__,__LINE__)
#define DEBUG_ERROR(x) Debug::LogError(x,__FILE__,__LINE__,__FUNCTION__ )
#define DEBUG_EXCEPTION(x) Debug::LogError(x)

namespace Debug
{
	void Log(const char* message);
	void Log(const std::string& message);

	void LogWarning(const char* message,const char* file,const int line);
	void LogWarning(const std::string& message,const char* file,const int line);

	void LogError(const char* message,const char* file,const int line,const char * func);
	void LogError(const std::string& message,const char* file,const int line,const char * func);

	void LogException(const std::exception& error);
};
