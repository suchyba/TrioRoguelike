#pragma once
#include "ItemGameObject.h"

class WeaponGameObject : public ItemGameObject
{
private:
	int bonusArmor;
protected:

public:
	WeaponGameObject(int Value, const EffectGameObject* Effect, string Name, GraphicalSymbol Symbol, int Damage);
	virtual GameObject* clone() const override;
	virtual void onAttack(CreatureGameObject& opponent) override;
};