#pragma once
#include "DynamicGameObject.h"
#include "Colliding.h"

class ItemGameObject;

class CreatureGameObject : public DynamicGameObject, public Colliding
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
	virtual void onRefresh() override;
	virtual void onInteraction() override;
	virtual void onCollide(GameObject sender) override;
	~CreatureGameObject();
};