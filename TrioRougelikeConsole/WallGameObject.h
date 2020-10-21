#pragma once
#include "GameObject.h"
#include "Colliding.h"

class WallGameObject : public GameObject, public Colliding
{
public:
	virtual void onCollide(GameObject sender) override;
};