#pragma once
#include "InteractionalbeGameObject.h"

class DynamicGameObject : public InteractionableGameObject
{
public:
	virtual void onRefresh() = 0;
};