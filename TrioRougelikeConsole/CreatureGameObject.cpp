#include "CreatureGameObject.h"
#include "ItemGameObject.h"

CreatureGameObject::CreatureGameObject(int hp, int armor, int exp, int activeItemsCount, string Name, GraphicalSymbol Symbol) : healthPoints(hp), baseArmor(armor), baseHealthPoints(hp), experience(exp),
DynamicGameObject(Name, Symbol)
{
	//	DEBUG
	cout << getTag() <<"Created CreatureGameObject (hp=" << hp << ", armor=" << armor << ", actItems=" << activeItemsCount << ")" << endl;
	//	END DEBUG

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

	cout << getTag() << "Taking " << damage << " damage (tried: " << dmg << ")" << endl;

	if (damage > 0)
	{
		healthPoints -= damage;
	}
	cout << getTag() << healthPoints << "/" << baseHealthPoints << endl;

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
	cout << getTag() << "Died" << endl;
}

void CreatureGameObject::onAttack(CreatureGameObject& opponent)
{
	int damage = 0;

	for (ItemGameObject* item : activeInventory)
		if (item)
			damage += item->getDamage();

	cout << getTag() << "Attacking " << opponent.getName() << " for " << damage << " damage" << endl;


	for (int i = 0; i < activeInventory.size(); ++i)
		if (activeInventory[i])
			activeInventory[i]->onAttack(opponent);

	opponent.onHit(damage);
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
	activeEffects.push_back(EffectGameObject(effect));
	cout << getTag() << "Effect applied on this creature: " << effect.getName() << endl;
	activeEffects.back().onRefresh(*this);
}

bool CreatureGameObject::equipItem(ItemGameObject item, int slot)
{
	if (slot < activeInventory.size())
	{
		if (activeInventory[slot] == NULL)
		{
			cout << "[" << name << "] Equipping " << item.getName() << " in slot " << slot << endl;
			activeInventory[slot] = new ItemGameObject(item);
			item.onEquipping(*this);
		}
	}
	return false;
}

void CreatureGameObject::directDmg(int dmg)
{
	healthPoints -= dmg;
	cout << getTag() << "Taking direct damage: " << dmg << endl;
	cout << getTag() << healthPoints << "/" << baseHealthPoints << endl;
	if (healthPoints < 0)
	{
		onDeath();
	}
}

CreatureGameObject::~CreatureGameObject()
{
	for (ItemGameObject* item : activeInventory)
		delete item;
}
