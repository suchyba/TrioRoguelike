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
#include <cstdio>

map<string, const GameObject*> Game::templateOtherObjectsList;
map<string, const CreatureGameObject*> Game::templateCreatureList;
map<string, const ItemGameObject*> Game::templateItemList;
map<string, const EffectGameObject*> Game::templateEffectObjectList;
vector<DynamicGameObject*> Game::dynamicList;

void Game::mainLoop()
{
	logMessage("Entering main loop");
	auto c1 = dynamic_cast<CreatureGameObject*>(dynamicList[0]);
	auto c2 = dynamic_cast<CreatureGameObject*>(dynamicList[1]);
	c1->onAttack(*c2);

	int i = 0;

	while (true)
	{
		logMessage("Iteration");
		
		
		// odœwierzanie obiektów dynamicznych
		for (auto obj : dynamicList)
		{
			if(obj)
				obj->onRefresh();
		}



		if(!c1->isAlive() || !c2->isAlive() || i > 20)
			return;
		++i;
	}
}

void Game::init()
{
	logMessage("Entering init");
	registerObjects();
	dynamicList.push_back((CreatureGameObject*) templateCreatureList.at("GH")->clone());
	dynamicList.push_back((CreatureGameObject*) templateCreatureList.at("GH")->clone());
}

void Game::registerObjects()
{
	logMessage("Registering objects");
	templateOtherObjectsList.insert({ "WA", new WallGameObject("Wall", GraphicalSymbol((char)219, 1, 0)) });
	templateOtherObjectsList.insert({ "FL", new GameObject("Floor", GraphicalSymbol((char)176, 2, 0)) });
	templateOtherObjectsList.insert({ "DR", new GameObject("Door", GraphicalSymbol((char)219, 6, 0)) });

	templateEffectObjectList.insert({ "BLEFF", new BleedingEffectGameObject(3, 3, 1, 15, "Bleeding", GraphicalSymbol('!', 4, 0)) });
	templateEffectObjectList.insert({ "HEAL", new RegenerationEffectGameObject(1, 10, 2, "Regeneration", GraphicalSymbol('+', 10, 0)) });

	templateItemList.insert({ "GHHD", new WeaponGameObject(3, (EffectGameObject*)templateEffectObjectList["BLEFF"]->clone(),"Ghul Hand", GraphicalSymbol('L', 4, 0), 13, 20) });
	templateItemList.insert({ "HLARM", new ArmorGameObject(10, (EffectGameObject*)templateEffectObjectList["HEAL"]->clone(), "Heal Chain Armor", GraphicalSymbol((char)177, 10, 0), 4)});
	
	templateCreatureList.insert({ "GH", new EnemyGameObject(20, 10, 5, 2, "Ghul", GraphicalSymbol('&', 4, 0), {(ItemGameObject*) templateItemList.at("GHHD")->clone(), (ItemGameObject*)templateItemList.at("HLARM")->clone()}) });
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
}

void Game::start()
{
	logMessage("Game started!");
	init();
	mainLoop();
	quit();
}


int Game::drawMenu()
{
	enum KEYCODES { UP = 72, DOWN = 80, ENTER=13 };
	char c = 254;
	int chosenOption = 1;
	int keyy = -1;
	while (1)
	{
		system("cls");
		cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
		cout << "                             ______ _____ _   _ _____  _____   _     _____ _   __ _____ " << endl;
		cout << "                             | ___ \\  _  | | | |  __ \\|  ___| | |   |_   _| | / /|  ___|" << endl;
		cout << "                             | |_/ / | | | | | | |  \\/| |__   | |     | | | |/ / | |__  " << endl;
		cout << "                             |    /| | | | | | | | __ |  __|  | |     | | |    \\ |  __| " << endl;
		cout << "                             | |\\ \\\\ \\_/ / |_| | |_\\ \\| |___  | |_____| |_| |\\  \\| |___ " << endl;
		cout << "                             \\_| \\_|\\___/ \\___/ \\____/\\____/  \\_____/\\___/\\_| \\_/\\____/" << endl<<endl;

		cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
		cout << "" << endl;


		printf("			     [%c]		  Rozpocznij Gre \n ", chosenOption==1 ? c : ' ');
		printf("			     [%c]		  Instrukcja gry \n ", chosenOption==2 ? c : ' ');
		printf("			     [%c]		     Autorzy\n ", chosenOption==3 ? c : ' ');
		printf("			     [%c]		      Wyjdz \n ", chosenOption==4 ? c : ' ');





		keyy = _getch();	     


		switch (keyy)
		{
		case DOWN:
		{
			if (chosenOption == 4)
				chosenOption = 1;
			else
				++chosenOption;

			break;
		}
		case UP:
		{
			if (chosenOption == 1)
				chosenOption = 4;
			else
				--chosenOption;

			break;
		}
		case ENTER:
		{
			return chosenOption;
		}
		}
	}
	return -1;

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
void Game:: showAuthors()
{
	cout << "Autorzy Gry: " << endl;
	cout << "Suchecki Bartlomiej" <<endl;
	cout << "Tomkiel Sebastian" <<endl;
	cout << "Zywalewski Daniel" <<endl;
}
void Game::  showInstructions()
{
	cout<< "Instrukcja Gry:"<<endl;
	cout<< ""<<endl;
	cout<< ""<<endl;
	cout<< ""<<endl;
	cout<< ""<<endl;
}