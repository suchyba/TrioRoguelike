#pragma once
#include "GameObject.h"

/// <summary>
/// Klasa dla obiekt�w, z kt�rymi mo�na wchodzi� w interakcj�.
/// </summary>
class InteractionableGameObject : public GameObject
{
public:
	/// <summary>
	/// Metoda wywo�ywana w momencie, gdy inny obiekt wchodzi w interakcj� z obecnym obeiktem.
	/// </summary>
	virtual void onInteraction() = 0;
};
