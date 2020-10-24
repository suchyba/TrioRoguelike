#pragma once
#include "InteractionalbeGameObject.h"

/// <summary>
/// Klasa dla obiekt�w, kt�re od�wierzaj� si� w ka�dej klatce gry.
/// </summary>
class DynamicGameObject : public InteractionableGameObject
{
public:
	/// <summary>
	/// Metowa wywo�ywana podczas od�wierzenia gry.
	/// </summary>
	virtual void onRefresh() = 0;
};