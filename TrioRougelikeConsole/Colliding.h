#pragma once
#include "GameObject.h"

class Colliding
{
private:

public:
	void virtual onCollide(GameObject sender) = 0;
};