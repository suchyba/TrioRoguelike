#pragma once
#include <map>
#include "CreatureGameObject.h"
#include "ItemGameObject.h"
#include "PlayerGameObject.h"
#include "GameObject.h"
#include "EffectGameObject.h"

using namespace std;

class Game final
{
private:
	Game();
	static map<string, const CreatureGameObject*> templateCreatureList;
	static map<string, const ItemGameObject*> templateItemList;
	static map<string, const GameObject*> templateOtherObjectsList;
	static map<string, const EffectGameObject*> templateEffectObjectList;
	
	static vector<DynamicGameObject*> creatureList;
	static PlayerGameObject* player;

	static void mainLoop();
	static void init();
	static void registerObjects();
	static void logMessage(string message);
	static void logError(string message);
	static void quit();
public:
	static void start();
};