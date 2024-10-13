#include "BianEngine.h"

GameSettings* GameSettings::inst;

GameSettings::GameSettings()
{
	inst = this;

	wcscpy_s(inst->FullGameName, L"undefined");
	wcscpy_s(inst->ShortGameName, L"undefined");
	wcscpy_s(inst->BootTime, Time::GetDateTimeString(TRUE).c_str());
}

GameSettings::~GameSettings()
{

}
