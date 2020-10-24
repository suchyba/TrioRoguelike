#include "CreatureGameObject.h"
#include "ItemGameObject.h"

CreatureGameObject::CreatureGameObject(int hp, int armor, int exp, int activeItemsCount) : healthPoints(hp), baseArmor(armor), baseHealthPoints(hp), experience(exp)
{
	for (int i = 0; i < activeItemsCount; ++i)
		activeInventory.push_back(NULL);
}

void CreatureGameObject::onHit(int dmg)
{
	int bonusArmor = 0;
	for (ItemGameObject* item : activeInventory)
	{
		if (item)
			bonusArmor += item->getArmor();
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
	for (ItemGameObject* item : activeInventory)
	{
		if (item)
			item->onDamege(damage);
	}
}

void CreatureGameObject::onDeath()
{
	alive = false;
}

void CreatureGameObject::onAttack(CreatureGameObject& opponent)
{
	int damage = 0;

	for (ItemGameObject* item : activeInventory)
		if (item)
			damage += item->getDamage();

	opponent.onHit(damage);

	for (ItemGameObject* item : activeInventory)
		if (item)
			item->onAttack(opponent);
}

void CreatureGameObject::onRefresh()
{
}

void CreatureGameObject::onInteraction()
{
}

void CreatureGameObject::onCollide(GameObject& sender)
{

}

int CreatureGameObject::getHealthPoints() const
{
	return healthPoints;
}

int CreatureGameObject::getBaseHealthPoints() const
{
	return baseHealthPoints;
}

int CreatureGameObject::getBaseArmor() const
{
	return baseArmor;
}

ItemGameObject* CreatureGameObject::getItemFromSlot(int slot) const
{
	ItemGameObject* item = NULL;
	if (slot < activeInventory.size())
		item = activeInventory[slot];
	return item;
}

bool CreatureGameObject::isAlive() const
{
	return alive;
}

int CreatureGameObject::getExperience() const
{
	return experience;
}

void CreatureGameObject::addEffect(const EffectGameObject& effect)
{
	activeEffects.push_back(effect);
}

bool CreatureGameObject::equipItem(ItemGameObject item, int slot)
{
	if (slot < activeInventory.size())
	{
		if (activeInventory[slot] == NULL)
			activeInventory[slot] = &item;
	}
	return false;
}

CreatureGameObject::~CreatureGameObject()
{
	for (ItemGameObject* item : activeInventory)
		delete item;
}
