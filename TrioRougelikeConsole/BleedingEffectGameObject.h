#pragma once
#include "EffectGameObject.h"

class BleedingEffectGameObject : public EffectGameObject
{
protected:
	int offset;
	int duration;
	int frameFromStart = 0;
	int minDamage, maxDamage;
public:
	BleedingEffectGameObject(int Offset, int Duration, int MinDamage, int MaxDamage, string Name, GraphicalSymbol Symbol);
	virtual bool onRefresh(GameObject& object) override;
	int getDuration() const;
	virtual GameObject* clone() const override;
};
