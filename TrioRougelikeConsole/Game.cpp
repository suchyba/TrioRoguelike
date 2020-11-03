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
#include "CreateMap.h"

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
	Map* map1 = new Map(2, 3);
	map1->setFloor(*floor);
	createMap(map1, ghul,floor,wall,GreatSword,Helmet,Yasuo,Axe,IT);
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