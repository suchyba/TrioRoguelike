#pragma once
#include "GameObject.h"
#include "CreatureGameObject.h"

class ItemGameObject : public GameObject
{
protected:
	int bonusArmor;
	int damage;
	int value;
public:
	int getArmor() const;
	int getDamage() const;
	int getValue() const;

	virtual void onAttack(CreatureGameObject* opponent);
	virtual void onDamege(int damage);
	virtual void onActivation();
};