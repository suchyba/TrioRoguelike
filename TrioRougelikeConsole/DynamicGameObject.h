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
	/// <summary>
	/// Opcjonalna metoda wywo³ywana, kiedy obiekt wp³ywa na inny obiekt.
	/// </summary>
	/// <param name="object">Obiekt na którym obiekt wywiera akcjê</param>
	/// <returns>True - jeœli meltoda jest obs³ugiwana, False - jeœli nie (domyœlnie)</returns>
	virtual bool onRefresh(GameObject& object);
};