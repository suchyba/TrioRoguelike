#pragma once
#include "EffectGameObject.h"

class RegenerationEffectGameObject : public EffectGameObject
{
protected:
	int offset;
	int frameFromStart = 0;
	int regeneratedHP;
public:
	RegenerationEffectGameObject(int Offset, int Duration, int RegeneredHP, string Name, GraphicalSymbol Symbol);
	virtual bool onRefresh(GameObject& object) override;
	virtual GameObject* clone() const override;
};