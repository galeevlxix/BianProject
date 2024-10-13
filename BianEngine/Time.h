#pragma once
#include <string>

namespace Time
{
	std::wstring BIAN_API GetTime(BOOL stripped = FALSE);
	std::wstring BIAN_API GetDate(BOOL stripped = FALSE);
	std::wstring BIAN_API GetDateTimeString(BOOL stripped = FALSE);
}