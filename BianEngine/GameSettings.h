#pragma once

class BIAN_API GameSettings
{
private:
	static GameSettings* inst;
	static GameSettings* Instance() { return inst; }
public:
	GameSettings();
	~GameSettings();
private:
	WCHAR FullGameName[MAX_NAME_STRING];
	WCHAR ShortGameName[MAX_NAME_STRING];
	HICON MainIcon;
	WCHAR BootTime[MAX_NAME_STRING];
public:
	static WCHAR* GetFullGameName() { return inst->FullGameName; }
	static VOID SetFullGameName(UINT id) { LoadString(HInstance(), id, inst->FullGameName, MAX_NAME_STRING); }

	static WCHAR* GetShortGameName() { return inst->FullGameName; }
	static VOID SetShortGameName(UINT id) { LoadString(HInstance(), id, inst->ShortGameName, MAX_NAME_STRING); }

	static HICON GetMainIcon() { return inst->MainIcon; }
	static VOID SetGameIcon(UINT id) { LoadIcon(HInstance(), MAKEINTRESOURCE(id)); }

	static WCHAR* GetBootTime() { return inst->BootTime; }
};