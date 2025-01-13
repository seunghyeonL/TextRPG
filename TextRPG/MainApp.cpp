#include "MainApp.h"
#include "GameManager.h"
#include "Level_Logo.h"

MainApp::MainApp()
{
	
}

void MainApp::Initialize()
{
	m_pGameManager = GameManager::Create();

	Open_Level();
}

void MainApp::Update()
{
	if (GetKeyState(VK_LEFT) & 0x8000)
	{

	}
		//m_bCheckQuit = false;

	m_pGameManager->Update();
}

void MainApp::Render()
{
	m_pGameManager->Render();
}

void MainApp::Open_Level()
{
	m_pGameManager->Change_Level(Level_Logo::Create());
}

MainApp* MainApp::Create()
{
	MainApp* pInstance = new MainApp();

	pInstance->Initialize();
	

	return pInstance;
}

void MainApp::Free()
{

}
