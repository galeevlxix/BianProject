#include "BianEngine.h"
#include <fstream>
#include <chrono>
#include <ctime>
#include <ShlObj.h>
#pragma warning(disable : 38)

Logger* Logger::inst;

Logger::Logger()
{
	inst = this;
}

Logger::~Logger()
{

}



VOID Logger::PrintLog(const WCHAR* fmt, ...)
{
	WCHAR buffer[4096];
	va_list args;

	va_start(args, fmt);
	vswprintf_s(buffer, fmt, args);
	va_end(args);

	std::wfstream outfile;
	outfile.open(std::wstring(LogDirectory() + L"/" + LogFile()), std::ios_base::app);
	if (outfile.is_open())
	{
		std::wstring s = buffer;
		outfile << L"[" << Time::GetDateTimeString() << L"]  " << s << std::endl;
		outfile.close();
	}
	else
	{
		MessageBox(NULL, L"Невозможно открыть logfile.", NULL, NULL);
	}
}

std::wstring Logger::LogDirectory()
{
	WCHAR Path[1024];
	WCHAR* AppDataLocal;
	SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &AppDataLocal);
	wcscpy_s(Path, AppDataLocal);
	wcscat_s(Path, L"\\");
	wcscat_s(Path, GameSettings::GetFullGameName());
	CreateDirectory(Path, NULL);
	wcscat_s(Path, L"\\Log");
	CreateDirectory(Path, NULL);
	return Path;
}

std::wstring Logger::LogFile()
{
	WCHAR File[1024];
	wcscpy_s(File, GameSettings::GetFullGameName());
	wcscat_s(File, GameSettings::GetBootTime());
	wcscat_s(File, L".log");
	return File;
}
