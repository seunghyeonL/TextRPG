#include "Input_Manager.h"
#include "MainApp.h"

void DisableCursorBlinking();
bool IsAnyKeyPressed();

int main()
{
	HINSTANCE hInstance = GetModuleHandle(nullptr);
	HWND hWnd = GetConsoleWindow();

	auto* pInputManager = Input_Manager::Create(hInstance, hWnd);

	DisableCursorBlinking();

	MainApp* pMainApp = MainApp::Create();

	while (true)
	{
		pMainApp->Update();
		pMainApp->Render();
		
		if (pInputManager->Key_Up(DIK_A)) {
			std::cout << "A key released!" << std::endl;
			Sleep(1010);
		}

		while (!IsAnyKeyPressed())
			Sleep(10);
		
		system("cls");
	}
}

bool IsAnyKeyPressed() 
{
	for (int key = 0; key < 256; ++key) 
	{
		if (GetAsyncKeyState(key) & 0x8000)
			return true;
	}
	return false;
}

void DisableCursorBlinking()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(hConsole, &cursorInfo);

	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hConsole, &cursorInfo);
}