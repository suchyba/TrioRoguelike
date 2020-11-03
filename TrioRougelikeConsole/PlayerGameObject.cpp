#include "PlayerGameObject.h"

PlayerGameObject::PlayerGameObject(int inventoryHeight, int inventoryWidth, int hp, int activeInventorySize,
	int experienceToSecondLvl, int startStrength, int startArmor, int startMagicPow, string Name, GraphicalSymbol Symbol) :
	experienceToNextLevel(experienceToSecondLvl), magicPower(startMagicPow), strength(startStrength), level(1),
	CreatureGameObject(hp, startArmor, 0, activeInventorySize, Name, Symbol)
{
	for (int i = 0; i < inventoryWidth; i++)
	{
		inventory.push_back(new vector<ItemGameObject*>());
		for (int j = 0; j < inventoryHeight; ++j)
		{
			inventory[i]->push_back(NULL);
		}

		//	DEBUG
		cout << "[" << name << "] Created PlayerGameObject (hp=" << hp << ", armor=" << startArmor << ", actItems=" << activeInventorySize << ", expToNxt=" << experienceToNextLevel
			<< ", magicPow=" << magicPower << ", strength=" << strength << ", inventory=" << inventoryWidth << "x" << inventoryHeight << ")" << endl;
		//	END DEBUG
	}
}

int PlayerGameObject::getLevel() const
{
	return level;
}
GameObject* PlayerGameObject::clone() const
{
	return new PlayerGameObject(*this);
}

PlayerGameObject::~PlayerGameObject()
{
	for (vector<ItemGameObject*>* row : inventory)
		for (auto cell : *row)
			if (cell)
				delete cell;
}
