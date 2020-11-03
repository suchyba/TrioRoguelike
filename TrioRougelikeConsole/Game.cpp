#include "Game.h"
#include "WallGameObject.h"
#include <Windows.h>
#include "GameObject.h"
#include "FloorGameObject.h"
#include "BleedingEffectGameObject.h"
#include "RegenerationEffectGameObject.h"
#include "EnemyGameObject.h"
#include "WeaponGameObject.h"
#include "ArmorGameObject.h"
#include <conio.h>
#include "PlayerGameObject.h"
#include "Map.h"
#include "EndGameObject.h"

map<string, const GameObject*> Game::templateOtherObjectsList;
map<string, const CreatureGameObject*> Game::templateCreatureList;
map<string, const ItemGameObject*> Game::templateItemList;
map<string, const EffectGameObject*> Game::templateEffectObjectList;

Map* Game::gameMap;
bool Game::nextLevel;
bool Game::gameOver;

void Game::mainLoop()
{
	logMessage("Entering main loop");
	while (true)
	{
		// ob³uga menu g³ównego
		bool start = false;
		while (!start)
		{
			// tutaj wyœwietlanie menu
			int i = 0;
			switch (i)
			{
			default:
				break;
			case 1:
			{
				start = true;
				break;
			}
			case 2:
			{
				// instrukcja
				break;
			}
			case 3:
			{
				// autorzy
				break;
			}
			case 4:
			{				
				return;
			}
			}
		}
		start = false;

		// tworzenie gracza
		gameMap->setPlayer(new PlayerGameObject(0, 0, 20, 4, 10, 0, 2, 0, "Gracz", GraphicalSymbol('@', 1, 0)));

		//przygotowanie mapy
		gameMap = new Map(10, 10, *dynamic_cast<FloorGameObject*>(templateOtherObjectsList.at("FLOOR")->clone()));
		gameMap->generateMap();

		// rozpoczêcie samej rozgrywki
		while (true)
		{
			logMessage("Iteration");
			// wyœwietlanie interfejsu

			int key = _getch();
			int x = 0, y = 0;
			switch (key)
			{
			case 'W':
			{
				//ruch playera w górê
				y = -1;
				break;
			}
			case 'S':
			{
				// w dó³
				y = 1;
				break;
			}
			case 'A':
			{
				// w lewo
				x = -1;
				break;
			}
			case 'D':
			{
				// w prawo
				x = 1;
				break;
			}
			default:
				break;
			}

			// poruszenie graczem
			gameMap->move(*gameMap->getPlayer(), x, y);

			if (nextLevel)
			{
				nextLevel = false;
				gameMap->generateMap();
				// ustawianie pozycji pocz¹tkowej gracza

			}
			if (gameOver)
			{
				// tutaj rysowanie game over
				break;
			}

			// odœwierzanie obiektów dynamicznych
			gameMap->refreshDynamic();
		}

		
		// usuwanie martwego gracza
		gameMap->clearDesign();
		delete gameMap->getPlayer();
	}
}

void Game::init()
{
	logMessage("Entering init");
	registerObjects();
	nextLevel = false;
	gameOver = false;
	
}

void Game::mainMenu()
{

}

void Game::registerObjects()
{
	logMessage("Registering objects");
	templateOtherObjectsList.insert({ "WA", new WallGameObject("Wall", GraphicalSymbol((char)219, 1, 0)) });
	templateOtherObjectsList.insert({ "FL", new FloorGameObject("Floor", GraphicalSymbol((char)176, 2, 0)) });
	templateOtherObjectsList.insert({ "DR", new GameObject("Door", GraphicalSymbol((char)219, 6, 0)) });
	templateOtherObjectsList.insert({ "END", new EndGameObject("End", GraphicalSymbol('%', 1, 0)) });

	templateEffectObjectList.insert({ "BLEFF", new BleedingEffectGameObject(3, 3, 1, 15, "Bleeding", GraphicalSymbol('!', 4, 0)) });
	templateEffectObjectList.insert({ "HEAL", new RegenerationEffectGameObject(1, 10, 2, "Regeneration", GraphicalSymbol('+', 10, 0)) });

	templateItemList.insert({ "GHHD", new WeaponGameObject(3, (EffectGameObject*)templateEffectObjectList["BLEFF"]->clone(),"Ghul Hand", GraphicalSymbol('L', 4, 0), 13, 20) });
	templateItemList.insert({ "HLARM", new ArmorGameObject(10, (EffectGameObject*)templateEffectObjectList["HEAL"]->clone(), "Heal Chain Armor", GraphicalSymbol((char)177, 10, 0), 4) });

	templateCreatureList.insert({ "GH", new EnemyGameObject(20, 10, 5, 2, "Ghul", GraphicalSymbol('&', 4, 0), {(ItemGameObject*)templateItemList.at("GHHD")->clone(), (ItemGameObject*)templateItemList.at("HLARM")->clone()}) });
}

void Game::logMessage(string message)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	cout << "[GAME] " << message << endl;
	SetConsoleTextAttribute(hConsole, 7);
}
void Game::logError(string message)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);
	cout << "[GAME] " << message << endl;
	SetConsoleTextAttribute(hConsole, 7);
}

void Game::quit()
{
	logMessage("Game is shutting down");

	templateEffectObjectList.clear();
	templateCreatureList.clear();
	templateItemList.clear();
	templateOtherObjectsList.clear();

	delete gameMap;
}

void Game::start()
{
	logMessage("Game started!");
	init();

	mainLoop();

	quit();
}

Map* Game::getMap()
{
	return gameMap;
}

void Game::nextMap()
{
	nextLevel = true;
}

void Game::GameOver()
{
	gameOver = true;
}
