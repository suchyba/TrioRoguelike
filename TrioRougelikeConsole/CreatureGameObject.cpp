#include "CreatureGameObject.h"
#include "ItemGameObject.h"
#include "Game.h"

CreatureGameObject::CreatureGameObject(int hp, int armor, int exp, int activeItemsCount, string Name, GraphicalSymbol Symbol) :
	healthPoints(hp), baseArmor(armor), baseHealthPoints(hp), experience(exp),
	DynamicGameObject(Name, Symbol)
{
	//	DEBUG
	//cout << getTag() << "Created CreatureGameObject (hp=" << hp << ", armor=" << armor << ", actItems=" << activeItemsCount << ")" << endl;
	//	END DEBUG

	for (int i = 0; i < activeItemsCount; ++i)
		activeInventory.push_back(NULL);
}

CreatureGameObject::CreatureGameObject(int hp, int armor, int exp, int activeItemsCount, string Name, GraphicalSymbol Symbol, const vector<ItemGameObject*>& itemList) :
	healthPoints(hp), baseArmor(armor), baseHealthPoints(hp), experience(exp),
	DynamicGameObject(Name, Symbol)
{
	//	DEBUG
//	cout << getTag() << "Created CreatureGameObject (hp=" << hp << ", armor=" << armor << ", actItems=" << activeItemsCount << ") with items: ";
//	for (auto item : itemList)
//		cout << item->getName() << "|";
//  cout << endl;
	//	END DEBUG

	activeInventory = vector<ItemGameObject*>(itemList);

	for (int i = 0; i < activeItemsCount - itemList.size(); ++i)
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

	for (ItemGameObject* item : activeInventory)
	{
		if (item)
			damage = item->onDamege(damage, *this);
	}
	//cout << getTag() << "Taking " << damage << " damage (tried: " << dmg << ")" << endl;

	if (damage > 0)
	{
		healthPoints -= damage;
	}
	//cout << getTag() << healthPoints << "/" << baseHealthPoints << endl;

	if (healthPoints <= 0)
	{
		onDeath();
		Game::getMap()->removeFromMap(*this);
		return;
	}
}

void CreatureGameObject::onDeath()
{
	alive = false;
	activeEffects.clear();

	//cout << getTag() << "Died" << endl;

	Game::getMap()->getPlayer()->addExp(experience);
}

void CreatureGameObject::onAttack(CreatureGameObject& opponent)
{
	int damage = 0;

	for (ItemGameObject* item : activeInventory)
		if (item)
			damage += item->getMinDamage() + (rand() % (item->getMaxDamage() - item->getMinDamage() + 1));

	//cout << getTag() << "Attacking " << opponent.getName() << " for " << damage << " damage" << endl;


	for (int i = 0; i < activeInventory.size(); ++i)
		if (activeInventory[i])
			activeInventory[i]->onAttack(opponent);
	try
	{
		opponent.onHit(damage);
	}
	catch (const std::exception&)
	{

	}
	
}

void CreatureGameObject::onRefresh()
{
	for (auto effect : activeEffects)
	{
		if (effect && alive)
			effect->onRefresh(*this);
	}
	if(!alive)
		Game::getMap()->removeFromMap(*this);
}

void CreatureGameObject::onInteraction()
{
}

void CreatureGameObject::onCollide(GameObject& sender)
{
	auto creature = dynamic_cast<CreatureGameObject*>(&sender);
	if (creature)
	{
		creature->onAttack(*this);
	}
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

int CreatureGameObject::getActiveInventorySize() const
{
	return activeInventory.size();
}

int CreatureGameObject::getActiveEffectsSize() const
{
	return activeEffects.size();
}

const EffectGameObject* CreatureGameObject::getEffectFromSlot(int slot) const
{
	EffectGameObject* effect = NULL;
	if (slot < activeEffects.size())
		effect = activeEffects[slot];
	return effect;
}

int CreatureGameObject::getFirstEmptySlot() const
{
	for (int i = 0; i < activeInventory.size(); ++i)
	{
		if (!activeInventory[i])
			return i;
	}
	return -1;
}

void CreatureGameObject::addEffect(const EffectGameObject& effect)
{
	for (auto eff : activeEffects)
		if (eff->getName() == effect.getName())
			return;

	activeEffects.push_back((EffectGameObject*)effect.clone());
	//cout << getTag() << "Effect applied on this creature: " << effect.getName() << endl;
	activeEffects.back()->onRefresh(*this);
}

void CreatureGameObject::removeEffect(string Name)
{
	for (int i = 0; i < activeEffects.size(); ++i)
	{
		if (activeEffects[i]->getName() == Name)
		{
			activeEffects.erase(activeEffects.begin() + i);
			//cout << getTag() << "Effect " << Name << " has been removed from creature." << endl;
		}
	}
}

bool CreatureGameObject::equipItem(ItemGameObject* item, int slot)
{
	if (slot < activeInventory.size())
	{
		if (activeInventory[slot] == NULL)
		{
			//cout << "[" << name << "] Equipping " << item->getName() << " in slot " << slot << endl;
			activeInventory[slot] = (ItemGameObject*)item->clone();
			item->onEquipping(*this);
		}
	}
	return false;
}

void CreatureGameObject::directDmg(int dmg)
{
	healthPoints -= dmg;
	if (healthPoints > baseHealthPoints)
		healthPoints = baseHealthPoints;
	//cout << getTag() << "Taking direct damage: " << dmg << endl;
	//cout << getTag() << healthPoints << "/" << baseHealthPoints << endl;
	if (healthPoints <= 0)
	{
		onDeath();
	}
}

CreatureGameObject::~CreatureGameObject()
{
	activeInventory.clear();
	activeEffects.clear();
}
