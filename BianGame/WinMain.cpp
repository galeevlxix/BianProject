#include "pch.h"

#pragma region GlobalVariables
WCHAR WindowClass[MAX_NAME_STRING];
WCHAR WindowTitle[MAX_NAME_STRING];

INT WindowWidth;
INT WindowHeight;

HICON hIcon;
HICON hIconSm;
#pragma endregion

#pragma region Pre-Declarations
VOID InitializeVariables();
VOID CreateWindowClass();
bool InitializeWindow();
VOID MessageLoop();
LRESULT CALLBACK WindowProcess(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam);
#pragma endregion

#pragma region OnProcess
LRESULT CALLBACK WindowProcess(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, message, wparam, lparam);
}
#pragma endregion

#pragma region OnLoad
//int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
//{
//	InitializeVariables();
//	CreateWindowClass();
//	if (!InitializeWindow()) return 0;
//	MessageLoop();
//	return 0;
//}

VOID InitializeVariables()
{
	LoadString(HInstance(), IDS_GAMENAME, WindowTitle, MAX_NAME_STRING);
	LoadString(HInstance(), IDS_WINDOWCLASS, WindowClass, MAX_NAME_STRING);

	hIcon = (HICON)LoadImage(HInstance(), MAKEINTRESOURCE(IDI_MAINICON), IMAGE_ICON, 32, 32, 0);
	hIconSm = (HICON)LoadImage(HInstance(), MAKEINTRESOURCE(IDI_MAINICON), IMAGE_ICON, 16, 16, 0);

	WindowWidth = 800;
	WindowHeight = 450;
}

VOID CreateWindowClass()
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WindowProcess;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = HInstance();
	wcex.hIcon = hIcon;
	wcex.hIconSm = hIconSm;
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
	wcex.lpszClassName = WindowClass;
	wcex.lpszMenuName = nullptr;

	RegisterClassEx(&wcex);
}

bool InitializeWindow()
{
	//Create and Display the Window
	HWND hWnd = CreateWindow(
		WindowClass,
		WindowTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		0,
		WindowWidth,
		WindowHeight,
		nullptr,
		nullptr,
		HInstance(),
		nullptr);

	if (!hWnd)
	{
		MessageBox(0, L"Failed to Create Window!", 0, 0);
		return false;
	}

	ShowWindow(hWnd, SW_SHOW);
	return true;
}

VOID MessageLoop()
{
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
	}
}
#pragma endregion

