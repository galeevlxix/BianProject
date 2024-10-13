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
	
}

VOID BianApplication::OnUpdate()
{
	
}
