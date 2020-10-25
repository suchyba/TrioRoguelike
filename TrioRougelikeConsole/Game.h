#pragma once
#include <vector>
#include "CreatureGameObject.h"
#include "ItemGameObject.h"
#include "PlayerGameObject.h"
#include "GameObject.h"


class Game final 
{
private:
	Game();
	vector<CreatureGameObject*> creatureList;
	vector<ItemGameObject*> itemList;
	vector<GameObject*> otherObjectsList;
	PlayerGameObject* player;
public:
	static void mainLoop();
	static void init();
};