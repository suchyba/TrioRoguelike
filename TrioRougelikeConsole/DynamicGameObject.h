#pragma once
#include "InteractionalbeGameObject.h"

/// <summary>
/// Klasa dla obiektów, które odœwierzaj¹ siê w ka¿dej klatce gry.
/// </summary>
class DynamicGameObject : public InteractionableGameObject
{
public:
	/// <summary>
	/// Konstruktor
	/// </summary>
	/// <param name="Name">Nazwa obiektu</param>
	/// <param name="Symbol">Graficzna reprezentacja obiektu</param>
	DynamicGameObject(string Name, GraphicalSymbol Symbol);
	/// <summary>
	/// Metowa wywo³ywana podczas odœwierzenia gry.
	/// </summary>
	virtual void onRefresh() = 0;
};