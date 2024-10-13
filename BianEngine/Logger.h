#pragma once

#include <string>

class BIAN_API Logger
{
private :
	static Logger* inst;
public:
	static Logger* Instance() { return inst; }

	Logger();
	~Logger();

	static std::wstring LogDirectory();
	static std::wstring LogFile();
	static VOID PrintLog(const WCHAR* fmt, ...);
};