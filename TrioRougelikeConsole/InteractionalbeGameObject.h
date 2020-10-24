#pragma once
#include "GameObject.h"

/// <summary>
/// Klasa dla obiektów, z którymi mo¿na wchodziæ w interakcjê.
/// </summary>
class InteractionableGameObject : public GameObject
{
public:
	/// <summary>
	/// Metoda wywo³ywana w momencie, gdy inny obiekt wchodzi w interakcjê z obecnym obeiktem.
	/// </summary>
	virtual void onInteraction() = 0;
};
