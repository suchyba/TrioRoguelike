#include "Game.h"
#include "WallGameObject.h"
#include <Windows.h>
#include "GameObject.h"
#include "FloorGameObject.h"
#include "BleedingEffectGameObject.h"
#include "EnemyGameObject.h"
#include "WeaponGameObject.h"

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
	while (true)
	{
		logMessage("iteration");
		
		
		// odœwierzanie obiektów dynamicznych
		for (auto obj : dynamicList)
		{
			if(obj)
				obj->onRefresh();
		}



		if(!c1->isAlive() || !c2->isAlive())
			return;
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

	templateItemList.insert({ "GHHD", new WeaponGameObject(3, (EffectGameObject*)templateEffectObjectList["BLEFF"]->clone(),"GhulHand", GraphicalSymbol('L', 4, 0), 10) });
	
	templateCreatureList.insert({ "GH", new EnemyGameObject(20, 10, 5, 1, "Ghul", GraphicalSymbol('&', 4, 0), {(ItemGameObject*) templateItemList.at("GHHD")->clone()}) });
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