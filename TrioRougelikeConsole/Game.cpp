#include "Game.h"
#include "Bars.h"
#include "Draw.h"
#include "WallGameObject.h"
#include <Windows.h>
#include "GameObject.h"
#include "FloorGameObject.h"
#include "BleedingEffectGameObject.h"
#include "RegenerationEffectGameObject.h"
#include "EnemyGameObject.h"
#include "WeaponGameObject.h"
#include "ArmorGameObject.h"
#include "PlayerGameObject.h"
#include "Map.h"
#include "EndGameObject.h"
#include "CreateMap.h"
#include <conio.h>
#include <cstdio>

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
		// ob�uga menu g��wnego
		bool start = false;
		while (!start)
		{
			// tutaj wy�wietlanie menu
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

		// rozpocz�cie samej rozgrywki
		while (true)
		{
			logMessage("Iteration");
			// wy�wietlanie interfejsu

			int key = _getch();
			int x = 0, y = 0;
			switch (key)
			{
			case 'W':
			{
				//ruch playera w g�r�
				y = -1;
				break;
			}
			case 'S':
			{
				// w d�
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
				// ustawianie pozycji pocz�tkowej gracza

			}
			if (gameOver)
			{
				// tutaj rysowanie game over
				break;
			}

			// od�wierzanie obiekt�w dynamicznych
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
	templateItemList.insert({ "HLARM", new ArmorGameObject(10, (EffectGameObject*)templateEffectObjectList["HEAL"]->clone(), "Heal Chain Armor", GraphicalSymbol((char)177, 10, 0), 4)});
	templateItemList.insert({ "HLMT", new ArmorGameObject(8, (EffectGameObject*)templateEffectObjectList["HEAL"], "Healing Helmer", GraphicalSymbol('n', 10, 0), 3) });
	
	templateItemList.insert({ "GRSW", new WeaponGameObject(7, (EffectGameObject*)templateEffectObjectList["BLEFF"]->clone(),"Great Sword", GraphicalSymbol('t', 4, 0), 10, 16) });
	templateItemList.insert({ "AXE", new WeaponGameObject(10, (EffectGameObject*)templateEffectObjectList["BLEFF"]->clone(),"Axe", GraphicalSymbol('P', 4, 0), 12, 19) });
	templateCreatureList.insert({ "GH", new EnemyGameObject(20, 10, 5, 2, "Ghul", GraphicalSymbol('&', 4, 0), {(ItemGameObject*) templateItemList.at("GHHD")->clone(), (ItemGameObject*)templateItemList.at("HLARM")->clone()}) });
	templateCreatureList.insert({ "YA", new EnemyGameObject(30, 12, 7, 1, "Yasuo", GraphicalSymbol('Y', 4, 0), { (ItemGameObject*)templateItemList.at("HLMT")->clone()}) });
	templateCreatureList.insert({ "IT", new EnemyGameObject(50, 15, 10, 0, "IT", GraphicalSymbol('I', 4, 0)) });

	CreatureGameObject* ghul = (CreatureGameObject*)templateCreatureList.at("GH")->clone();
	GameObject* floor = (GameObject*)templateOtherObjectsList.at("FL")->clone();
	WallGameObject* wall = (WallGameObject*)templateOtherObjectsList.at("WA")->clone();
	WeaponGameObject* GreatSword = (WeaponGameObject*)templateItemList.at("GRSW")->clone();
	WeaponGameObject* Axe = (WeaponGameObject*)templateItemList.at("AXE")->clone();

	ArmorGameObject* Helmet = (ArmorGameObject*)templateItemList.at("HLMT")->clone();
	CreatureGameObject* Yasuo = (CreatureGameObject*)templateCreatureList.at("YA")->clone();
	CreatureGameObject* IT = (CreatureGameObject*)templateCreatureList.at("YA")->clone();
	PlayerGameObject* player = new PlayerGameObject(0, 0, 10, 0, 0, 10, 10, 10, "Gracz", GraphicalSymbol('@', 2, 3));
	Map* map1 = new Map(2, 3);
	map1->setFloor(*floor);
	createMap(map1, ghul,floor,wall,GreatSword,Helmet,Yasuo,Axe,IT);
	drawMap(map1);
	drawStats(player);

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

void Game::menuThread()
{
	int option = 0;

	while (1)
	{
		option = drawMenu();
		switch (option)
		{
		case 1:
		{
			start();
			cout << "Wcisnij dowolny klawisz by kontynuowac";
			int g = _getch();

			break;
		}
		case 2:
		{
			system("cls");
			showInstructions();
			cout << "Wcisnij dowolny klawisz by kontynuowac";
			int g = _getch();
			continue;
		}
		case 3:
		{
			system("cls");
			showAuthors();
			cout << "Wcisnij dowolny klawisz by kontynuowac";
			int g = _getch();
			continue;
		}
		case 4:
		{
			exit(0);
		}
		}
	}
}
