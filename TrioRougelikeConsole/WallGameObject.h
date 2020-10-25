#pragma once
#include "GameObject.h"
#include "Colliding.h"
#include "GraphicalSymbol.h"

class WallGameObject : public GameObject, public Colliding
{
public:
	virtual void onCollide(GameObject& sender) override;
	WallGameObject(string Name, GraphicalSymbol Symbol);
};