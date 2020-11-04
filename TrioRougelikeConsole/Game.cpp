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
#include <fstream>
#include <string>

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
			switch (drawMenu())
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
				showInstructions();
				break;
			}
			case 3:
			{
				showAuthors();
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
		PlayerGameObject* p = new PlayerGameObject(0, 0, 20, 4, 10, 0, 2, 0, "Gracz", GraphicalSymbol('@', 7, 0));
		gameMap->setPlayer(p);

		//przygotowanie mapy
		gameMap->generateMap();
		gameMap->randomizePlayerPos();

		// rozpocz�cie samej rozgrywki
		while (true)
		{
			//logMessage("Iteration");
			// wy�wietlanie interfejsu
			drawMap(gameMap);
			drawStats(gameMap->getPlayer());

			bool quit = false;

			int key = _getch();
			int x = 0, y = 0;
			switch (key)
			{
			case 'w':
			{
				//ruch playera w g�r�
				x = -1;
				break;
			}
			case 's':
			{
				// w d�
				x = 1;
				break;
			}
			case 'a':
			{
				// w lewo
				y = -1;
				break;
			}
			case 'd':
			{
				// w prawo
				y = 1;
				break;
			}
			case 27:
			{
				quit = true;
				break;
			}
			default:
				continue;
			}

			// poruszenie graczem
			gameMap->move(*gameMap->getPlayer(), x, y);

			// od�wierzanie obiekt�w dynamicznych
			gameMap->refreshDynamic();

			if (nextLevel)
			{
				nextLevel = false;
				gameMap->generateMap();
				// ustawianie pozycji pocz�tkowej gracza
				gameMap->randomizePlayerPos();
			}
			if (gameOver)
			{
				// tutaj rysowanie game over
				gameOver = false;
				drawOver();
				break;
			}
			if (quit)
			{
				break;
			}

		}


		// usuwanie martwego gracza
		gameMap->clearDesign();
	}
}

void Game::init()
{
	logMessage("Entering init");
	registerObjects();

	logMessage("Creating Map object");
	FloorGameObject* f = dynamic_cast<FloorGameObject*>(templateOtherObjectsList.at("FL")->clone());
	gameMap = new Map(3, 3, *f);

	registerRooms();

	nextLevel = false;
	gameOver = false;
}

void Game::registerObjects()
{
	logMessage("Registering objects");
	templateOtherObjectsList.insert({ "WL", new WallGameObject("Wall", GraphicalSymbol((char)219, 1, 0)) });
	templateOtherObjectsList.insert({ "FL", new FloorGameObject("FLOOR", GraphicalSymbol((char)176, 2, 0)) });
	templateOtherObjectsList.insert({ "DR", new GameObject("Door", GraphicalSymbol((char)219, 6, 0)) });
	templateOtherObjectsList.insert({ "EN", new EndGameObject("End", GraphicalSymbol('%', 1, 0)) });

	templateEffectObjectList.insert({ "BLEFF", new BleedingEffectGameObject(2, 3, 1, 5, "Bleeding", GraphicalSymbol('!', 4, 0)) });
	templateEffectObjectList.insert({ "HEAL", new RegenerationEffectGameObject(1, 10, 2, "Regeneration", GraphicalSymbol('+', 10, 0)) });

	templateItemList.insert({ "GHHD", new WeaponGameObject(3, (EffectGameObject*)templateEffectObjectList["BLEFF"]->clone(),"Ghul Hand", GraphicalSymbol('L', 4, 0), 2, 5) });
	templateItemList.insert({ "HLARM", new ArmorGameObject(10, (EffectGameObject*)templateEffectObjectList["HEAL"]->clone(), "Heal Chain Armor", GraphicalSymbol((char)177, 10, 0), 4) });
	templateItemList.insert({ "HLMT", new ArmorGameObject(8, (EffectGameObject*)templateEffectObjectList["HEAL"], "Healing Helmer", GraphicalSymbol('n', 10, 0), 3) });

	templateItemList.insert({ "GRSW", new WeaponGameObject(7, (EffectGameObject*)templateEffectObjectList["BLEFF"]->clone(),"Great Sword", GraphicalSymbol('t', 7, 0), 10, 16) });
	templateItemList.insert({ "AXE", new WeaponGameObject(10, (EffectGameObject*)templateEffectObjectList["BLEFF"]->clone(),"Axe", GraphicalSymbol('P', 7, 0), 12, 19) });
	templateCreatureList.insert({ "GH", new EnemyGameObject(20, 10, 5, 1, "Ghul", GraphicalSymbol('&', 4, 0), {(ItemGameObject*)templateItemList.at("GHHD")->clone()}) });
	templateCreatureList.insert({ "YA", new EnemyGameObject(30, 12, 7, 2, "Yasuo", GraphicalSymbol('Y', 4, 0), { (ItemGameObject*)templateItemList.at("HLMT")->clone(), (ItemGameObject*)templateItemList.at("HLARM")->clone()}) });
	templateCreatureList.insert({ "IT", new EnemyGameObject(50, 15, 10, 0, "IT", GraphicalSymbol('I', 4, 0)) });


	templateItemList.insert({ "HLARM", new ArmorGameObject(10, (EffectGameObject*)templateEffectObjectList["HEAL"]->clone(), "Heal Chain Armor", GraphicalSymbol((char)177, 10, 0), 4) });

	templateCreatureList.insert({ "GH", new EnemyGameObject(20, 10, 5, 2, "Ghul", GraphicalSymbol('&', 4, 0), {(ItemGameObject*)templateItemList.at("GHHD")->clone(), (ItemGameObject*)templateItemList.at("HLARM")->clone()}) });

	/*CreatureGameObject* ghul = (CreatureGameObject*)templateCreatureList.at("GH")->clone();
	FloorGameObject* floor = (FloorGameObject*)templateOtherObjectsList.at("FL")->clone();
	WallGameObject* wall = (WallGameObject*)templateOtherObjectsList.at("WA")->clone();
	WeaponGameObject* GreatSword = (WeaponGameObject*)templateItemList.at("GRSW")->clone();
	WeaponGameObject* Axe = (WeaponGameObject*)templateItemList.at("AXE")->clone();

	ArmorGameObject* Helmet = (ArmorGameObject*)templateItemList.at("HLMT")->clone();
	CreatureGameObject* Yasuo = (CreatureGameObject*)templateCreatureList.at("YA")->clone();
	CreatureGameObject* IT = (CreatureGameObject*)templateCreatureList.at("YA")->clone();*/
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

void Game::registerRooms()
{
	logMessage("Registering Rooms");
	ifstream rooms;
	rooms.open("Rooms.rm", ios_base::in);
	if (!rooms.is_open())
	{
		logError("Can't open Rooms.rm file.");
		exit(-1);
	}
	string r;
	rooms >> r;
	int rooms_count = stoi(r);
	for (int i = 0; i < rooms_count; ++i)
	{
		// wchodzę do pokoju
		rooms >> r;
		logMessage("Reading room: " + r);

		vector<vector<vector<GameObject*>>> temp;
		for (int x = 0; x < 10; ++x)
		{
			vector<vector<GameObject*>> tmp;
			for (int y = 0; y < 10; ++y)
			{
				vector<GameObject*> tmp2;
				for (int z = 0; z < 3; ++z)
				{
					tmp2.push_back(NULL);
				}
				tmp.push_back(tmp2);
			}
			temp.push_back(tmp);
		}

		for (int z = 0; z < 3; ++z)
		{
			// wchodzę do kolejnych warstw
			rooms >> r;
			logMessage("Reading layer: " + r);

			for (int x = 0; x < 10; ++x)
			{
				for (int y = 0; y < 10; ++y)
				{
					rooms >> r;

					if (r == "NL")
						continue;

					GameObject* g = NULL;

					switch (z)
					{
					case 0:
					{
						// podłoga
						auto itr = templateOtherObjectsList.find(r);
						if (itr != templateOtherObjectsList.end())
							g = templateOtherObjectsList.at(r)->clone();
						break;
					}
					case 1:
					{
						// itemki
						auto itr = templateItemList.find(r);
						if (itr != templateItemList.end())
							g = templateItemList.at(r)->clone();
						break;
					}
					case 2:
					{
						// stworki
						auto itr = templateCreatureList.find(r);
						if (itr != templateCreatureList.end())
							g = templateCreatureList.at(r)->clone();
						break;
					}
					}
					if (!g)
					{
						logError("Can't find object: " + r);
						rooms.close();
						exit(-1);
					}
					else
					{
						temp[x][y][z] = g->clone();
					}
				}
			}
		}
		Room room(temp);
		gameMap->addRoom(room);
	}
	rooms.close();
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