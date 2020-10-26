#pragma once
#include "ItemGameObject.h"

class WeaponGameObject : public ItemGameObject
{
private:
	int bonusArmor;
public:
	WeaponGameObject(int Value, const EffectGameObject* Effect, string Name, GraphicalSymbol Symbol, int MinDamage, int MaxDamage);
	virtual GameObject* clone() const override;
	virtual void onAttack(CreatureGameObject& opponent) override;
};