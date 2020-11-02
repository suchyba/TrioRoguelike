#pragma once
#include "GameObject.h"

/// <summary>
/// Klasa dla obiekt�w, z kt�rymi mo�na wchodzi� w interakcj�.
/// </summary>
class InteractionableGameObject : public GameObject
{
public:
	/// <summary>
	/// Konstruktor
	/// </summary>
	/// <param name="Name">Nazwa obiektu</param>
	/// <param name="Symbol">Graficzna reprezentacja obiektu</param>
	InteractionableGameObject(string Name, GraphicalSymbol Symbol);
	/// <summary>
	/// Metoda wywo�ywana w momencie, gdy inny obiekt wchodzi w interakcj� z obecnym obeiktem.
	/// </summary>
	virtual void onInteraction() = 0;
	/// <summary>
	/// Metoda czysto abstrakcyjna tworz�ca kopi� obiektu.
	/// </summary>
	/// <returns>Kopia obiektu</returns>
	virtual GameObject* clone() const override = 0;
	/// <summary>
	/// Wirtualny destruktor
	/// </summary>
	virtual ~InteractionableGameObject();
};
