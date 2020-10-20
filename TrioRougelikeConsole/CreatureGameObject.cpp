#include "CreatureGameObject.h"

CreatureGameObject::CreatureGameObject(int hp, int armor, int activeItemsCount) : healthPoints(hp), baseArmor(armor), activeInventorySize(activeItemsCount)
{
	activeInventory = new ItemGameObject[activeInventorySize];
}

void CreatureGameObject::onHit(int dmg)
{
	int bonusArmor = 0;
	for (int i = 0; i < activeInventorySize; ++i)
	{
		bonusArmor += activeInventory[i].getArmor();
	}
	int damage = dmg - (baseArmor + bonusArmor);

	if (damage > 0)
	{
		healthPoints -= damage;
	}
	if (healthPoints <= 0)
	{
		onDeath();
		return;
	}
	for (int i = 0; i < activeInventorySize; ++i)
	{
		activeInventory[i].onDamege(damage);
	}
}

void CreatureGameObject::onDeath()
{
	alive = false;
}

void CreatureGameObject::onAttack(CreatureGameObject* opponent)
{
	int damage = 0;
	for (int i = 0; i < activeInventorySize; ++i)
	{
		damage += activeInventory[i].getDamage();
	}
	opponent->onHit(damage);
	for (int i = 0; i < activeInventorySize; ++i)
		activeInventory[i].onAttack(opponent);
}

CreatureGameObject::~CreatureGameObject()
{
	delete[] activeInventory;
}
