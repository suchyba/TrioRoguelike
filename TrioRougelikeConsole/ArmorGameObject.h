#pragma once
#include "ItemGameObject.h"

class ArmorGameObject : public ItemGameObject
{
private:
	int damage;
public:
	ArmorGameObject(int Value, const EffectGameObject* Effect, string Name, GraphicalSymbol Symbol, int Armor);
	virtual GameObject* clone() const override;
	virtual int onDamege(int damage, CreatureGameObject& self) override;
};
