#include "Game.h"
#include "DisplayConsole.h"
#include "DisplayAllegro.h"
#include "WallGameObject.h"
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
#include <Windows.h>
#include <fstream>
#include <string>
#include <conio.h>

map<string, const GameObject*> Game::templateOtherObjectsList;
map<string, const CreatureGameObject*> Game::templateCreatureList;
map<string, const ItemGameObject*> Game::templateItemList;
map<string, const EffectGameObject*> Game::templateEffectObjectList;

Map* Game::gameMap;
bool Game::nextLevel;
bool Game::gameOver;
Display* Game::displayControl;

void Game::mainLoop()
{
	logMessage("Entering main loop");
	while (true)
	{
		// obsługa menu głównego
		bool start = false;
		while (!start)
		{
			// wyświetlanie menu
			int i = 0;
			switch (displayControl->drawMenu())
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
				displayControl->showInstructions();
				break;
			}
			case 3:
			{
				displayControl->showAuthors();
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
		//PlayerGameObject* p = new PlayerGameObject(0, 0, 20, 4, 10, 0, 2, 0, "Gracz", GraphicalSymbol('@', 7, 0));
		PlayerGameObject* p = new PlayerGameObject(0, 0, 20, 4, 10, 0, 2, 0, "Gracz", GraphicalSymbol(al_load_bitmap("images/player.png")));
		gameMap->setPlayer(p);

		//przygotowanie mapy
		gameMap->generateMap();
		gameMap->randomizePlayerPos();

		// rozpocz�cie samej rozgrywki
		while (true)
		{
			//logMessage("Iteration");
			// wy�wietlanie interfejsu
			
			bool quit = false;

			int key = displayControl->drawInterface(gameMap, gameMap->getPlayer());
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
				displayControl->drawOver();
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
	displayControl = new DisplayAllegro();

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
	/*templateOtherObjectsList.insert({ "WL", new WallGameObject("Wall", GraphicalSymbol((char)219, 8, 0)) });
	templateOtherObjectsList.insert({ "FL", new FloorGameObject("FLOOR", GraphicalSymbol((char)176, 2, 0)) });
	templateOtherObjectsList.insert({ "EN", new EndGameObject("End", GraphicalSymbol('%', 1, 0)) });

	templateEffectObjectList.insert({ "BLEFF", new BleedingEffectGameObject(2, 3, 1, 5, "Bleeding", GraphicalSymbol('!', 4, 0)) });
	templateEffectObjectList.insert({ "HEAL", new RegenerationEffectGameObject(1, 3, 2, "Regeneration", GraphicalSymbol('+', 10, 0)) });
	templateEffectObjectList.insert({ "HEALPLUS", new RegenerationEffectGameObject(1, 4, 5, "Regeneration+", GraphicalSymbol('+', 2, 0)) });

	templateItemList.insert({ "GHHD", new WeaponGameObject(3, (EffectGameObject*)templateEffectObjectList["BLEFF"]->clone(),"Ghul Hand", GraphicalSymbol('L', 4, 0), 2, 5) });
	templateItemList.insert({ "GRSW", new WeaponGameObject(7, (EffectGameObject*)templateEffectObjectList["BLEFF"]->clone(),"Great Sword", GraphicalSymbol('t', 8, 0), 10, 16) });
	templateItemList.insert({ "AXE", new WeaponGameObject(10, (EffectGameObject*)templateEffectObjectList["BLEFF"]->clone(),"Axe", GraphicalSymbol('P', 8, 0), 12, 19) });
	templateItemList.insert({ "HLARM", new ArmorGameObject(10, (EffectGameObject*)templateEffectObjectList["HEAL"]->clone(), "Heal Chain Armor", GraphicalSymbol((char)177, 10, 0), 4) });
	templateItemList.insert({ "HLMT", new ArmorGameObject(8, (EffectGameObject*)templateEffectObjectList["HEALPLUS"], "Healing Helmet", GraphicalSymbol('n', 10, 0), 3) });

	templateCreatureList.insert({ "GH", new EnemyGameObject(20, 10, 5, 1, "Ghul", GraphicalSymbol('&', 4, 0), {(ItemGameObject*)templateItemList.at("GHHD")->clone()}) });
	templateCreatureList.insert({ "YA", new EnemyGameObject(30, 12, 7, 3, "Yasuo", GraphicalSymbol('Y', 11, 0), {	(ItemGameObject*)templateItemList.at("HLMT")->clone(), 
																													(ItemGameObject*)templateItemList.at("HLARM")->clone(), 
																													(ItemGameObject*)templateItemList.at("GRSW")->clone()}) });
	templateCreatureList.insert({ "IT", new EnemyGameObject(50, 15, 10, 0, "IT", GraphicalSymbol('I', 14, 0)) });
	templateCreatureList.insert({ "GH", new EnemyGameObject(20, 10, 5, 2, "Ghul", GraphicalSymbol('&', 4, 0), {	(ItemGameObject*)templateItemList.at("GHHD")->clone(), 
																												(ItemGameObject*)templateItemList.at("HLARM")->clone()}) });*/
	templateOtherObjectsList.insert({ "WL", new WallGameObject("Wall", GraphicalSymbol(al_load_bitmap("images/wall.png"))) });
	templateOtherObjectsList.insert({ "FL", new FloorGameObject("FLOOR", GraphicalSymbol(al_load_bitmap("images/floor.png"))) });
	templateOtherObjectsList.insert({ "EN", new EndGameObject("End", GraphicalSymbol(al_load_bitmap("images/sprite.png"))) });

	templateEffectObjectList.insert({ "BLEFF", new BleedingEffectGameObject(2, 3, 1, 5, "Bleeding", GraphicalSymbol(al_load_bitmap("images/sprite.png"))) });
	templateEffectObjectList.insert({ "HEAL", new RegenerationEffectGameObject(1, 3, 2, "Regeneration", GraphicalSymbol(al_load_bitmap("images/sprite.png"))) });
	templateEffectObjectList.insert({ "HEALPLUS", new RegenerationEffectGameObject(1, 4, 5, "Regeneration+", GraphicalSymbol(al_load_bitmap("images/sprite.png"))) });

	templateItemList.insert({ "GHHD", new WeaponGameObject(3, (EffectGameObject*)templateEffectObjectList["BLEFF"]->clone(),"Ghul Hand", GraphicalSymbol(al_load_bitmap("images/ghullhand.png")), 2, 5) });
	templateItemList.insert({ "GRSW", new WeaponGameObject(7, (EffectGameObject*)templateEffectObjectList["BLEFF"]->clone(),"Great Sword", GraphicalSymbol(al_load_bitmap("images/sprite.png")), 10, 16) });
	templateItemList.insert({ "AXE", new WeaponGameObject(10, (EffectGameObject*)templateEffectObjectList["BLEFF"]->clone(),"Axe", GraphicalSymbol(al_load_bitmap("images/sprite.png")), 12, 19) });
	templateItemList.insert({ "HLARM", new ArmorGameObject(10, (EffectGameObject*)templateEffectObjectList["HEAL"]->clone(), "Heal Chain Armor", GraphicalSymbol(al_load_bitmap("images/healingarmor.png")), 4) });
	templateItemList.insert({ "HLMT", new ArmorGameObject(8, (EffectGameObject*)templateEffectObjectList["HEALPLUS"], "Healing Helmet", GraphicalSymbol(al_load_bitmap("images/sprite.png")), 3) });

	templateCreatureList.insert({ "GH", new EnemyGameObject(20, 10, 5, 1, "Ghul", GraphicalSymbol(al_load_bitmap("images/ghull.png")), {(ItemGameObject*)templateItemList.at("GHHD")->clone()}) });
	templateCreatureList.insert({ "YA", new EnemyGameObject(30, 12, 7, 3, "Yasuo", GraphicalSymbol(al_load_bitmap("images/sprite.png")), {	(ItemGameObject*)templateItemList.at("HLMT")->clone(),
																													(ItemGameObject*)templateItemList.at("HLARM")->clone(), 
																													(ItemGameObject*)templateItemList.at("GRSW")->clone()}) });
	templateCreatureList.insert({ "IT", new EnemyGameObject(50, 15, 10, 0, "IT", GraphicalSymbol(al_load_bitmap("images/sprite.png"))) });
	templateCreatureList.insert({ "GH", new EnemyGameObject(20, 10, 5, 2, "Ghul", GraphicalSymbol(al_load_bitmap("images/sprite.png")), {	(ItemGameObject*)templateItemList.at("GHHD")->clone(),
																												(ItemGameObject*)templateItemList.at("HLARM")->clone()}) });

	templateCreatureList.insert({ "SPRITE", new EnemyGameObject(20, 10, 10, 1, "Sprite", GraphicalSymbol(al_load_bitmap("images/sprite.png")), {(ItemGameObject*)templateItemList.at("AXE")->clone()}) });	
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
	delete displayControl;
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