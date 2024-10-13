#pragma once
#include "BianEngine.h"
#include "IBianApplication.h"

extern IBianApplication* EntryApplication();

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	auto EntryApp = EntryApplication();
	
	GameSettings settings;
	
	EntryApp->SetupGameSettings();
	
	Logger logger;

	EntryApp->OnLoad();

	// Listen for Message Events
	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			//отправить сообщения в окно
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			EntryApp->OnUpdate();
		}
	}

	return 0;
}