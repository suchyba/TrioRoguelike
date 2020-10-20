#pragma once
#include "GameObject.h"

class InteractionableGameObject : public GameObject
{
public:
	virtual void onInteraction() = 0;
};
