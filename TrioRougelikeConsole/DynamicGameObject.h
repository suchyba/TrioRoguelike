#pragma once
#include "InteractionalbeGameObject.h"

/// <summary>
/// Klasa dla obiektów, które odœwierzaj¹ siê w ka¿dej klatce gry.
/// </summary>
class DynamicGameObject : public InteractionableGameObject
{
public:
	/// <summary>
	/// Metowa wywo³ywana podczas odœwierzenia gry.
	/// </summary>
	virtual void onRefresh() = 0;
};