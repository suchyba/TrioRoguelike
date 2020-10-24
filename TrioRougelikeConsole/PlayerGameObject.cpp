#include "PlayerGameObject.h"

PlayerGameObject::PlayerGameObject(int inventoryHeight, int inventoryWidth, int hp, int activeInventorySize, 
	int experienceToSecondLvl, int startStrength, int startArmor, int startMagicPow) : 
	experienceToNextLevel(experienceToSecondLvl), magicPower(startMagicPow), strength(startStrength), level(1), 
	CreatureGameObject(hp, startArmor, 0, activeInventorySize)
{
	for (int i = 0; i < inventoryWidth; i++)
	{
		inventory.push_back(new vector<ItemGameObject*>());
		for (int j = 0; j < inventoryHeight; ++j)
		{
			inventory[i]->push_back(NULL);
		}
	}
}
