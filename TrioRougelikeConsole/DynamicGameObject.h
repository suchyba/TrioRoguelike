#pragma once
#include "InteractionalbeGameObject.h"

/// <summary>
/// Klasa dla obiekt�w, kt�re od�wierzaj� si� w ka�dej klatce gry.
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
	/// Metowa wywo�ywana podczas od�wierzenia gry.
	/// </summary>
	virtual void onRefresh() = 0;
	/// <summary>
	/// Opcjonalna metoda wywo�ywana, kiedy obiekt wp�ywa na inny obiekt.
	/// </summary>
	/// <param name="object">Obiekt na kt�rym obiekt wywiera akcj�</param>
	/// <returns>True - je�li meltoda jest obs�ugiwana, False - je�li nie (domy�lnie)</returns>
	virtual bool onRefresh(GameObject& object);
};