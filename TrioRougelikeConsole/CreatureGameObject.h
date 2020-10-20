#pragma once
#include "DynamicGameObject.h"
#include "ItemGameObject.h"

class CreatureGameObject : public DynamicGameObject
{
protected:
	int healthPoints;
	int baseArmor;
	ItemGameObject* activeInventory;
	int activeInventorySize;
	bool alive = true;
public:
	CreatureGameObject(int hp, int armor, int activeItemsCount);
	virtual void onHit(int dmg);
	virtual void onDeath();
	virtual void onAttack(CreatureGameObject* opponent);
	virtual void onRefresh();
	virtual void onInteraction();
	~CreatureGameObject();
};