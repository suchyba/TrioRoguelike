#pragma once
#include "InteractionalbeGameObject.h"

class EndGameObject : public InteractionableGameObject
{
public:
	EndGameObject(string Name, GraphicalSymbol Symbol);
	// Odziedziczono za poœrednictwem elementu InteractionableGameObject
	virtual void onInteraction() override;
	virtual GameObject* clone() const override;
};

