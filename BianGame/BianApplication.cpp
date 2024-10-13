#include "pch.h"
#include "BianApplication.h"
#include "WinEntry.h"

ENTRYAPP(BianApplication)

BianApplication::BianApplication()
{

}

BianApplication::~BianApplication()
{

}

VOID BianApplication::SetupGameSettings()
{
	GameSettings::SetFullGameName(IDS_GAMENAME);
	GameSettings::SetShortGameName(IDS_SHORTGAMENAME);
	GameSettings::SetGameIcon(IDI_MAINICON);
}

VOID BianApplication::OnLoad()
{
	Logger::PrintLog(L"Loaded");
}

VOID BianApplication::OnUpdate()
{
	Logger::PrintLog(L"OnProcess");
}
