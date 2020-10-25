#include "Game.h"
#include "WallGameObject.h"
#include <Windows.h>
#include "GameObject.h"
//#include <iostream>
//#include <map>

//using namespace std;

map<string, const GameObject&> Game::templateOtherObjectsList;
map<string, const CreatureGameObject&> Game::templateCreatureList;
map<string, const ItemGameObject&> Game::templateItemList;

void Game::mainLoop()
{
	logMessage("Entering main loop");
	while (true)
	{
		logMessage("First iteration");
		return;
	}
}

void Game::init()
{
	logMessage("Entering init");
	registerObjects();
}

void Game::registerObjects()
{
	logMessage("Registering objects");
	templateOtherObjectsList.insert({ "WALL", WallGameObject("Wall", GraphicalSymbol((char)219, 1, 0)) });

	templateCreatureList.insert({ "GH", CreatureGameObject(3, 10, 5, 0, "Ghul", GraphicalSymbol('&', 4, 0)) });
}

void Game::logMessage(string message)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	cout << "[GAME] " << message << endl;
	SetConsoleTextAttribute(hConsole, 7);
}

void Game::quit()
{
	logMessage("Game is shutting down");
}

void Game::start()
{
	logMessage("Game started!");
	init();
	mainLoop();
	quit();
}