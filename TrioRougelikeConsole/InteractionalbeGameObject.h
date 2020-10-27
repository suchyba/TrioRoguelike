#pragma once
#include "GameObject.h"

/// <summary>
/// Klasa dla obiektów, z którymi mo¿na wchodziæ w interakcjê.
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
	/// Metoda wywo³ywana w momencie, gdy inny obiekt wchodzi w interakcjê z obecnym obeiktem.
	/// </summary>
	virtual void onInteraction() = 0;
	/// <summary>
	/// Metoda czysto abstrakcyjna tworz¹ca kopiê obiektu.
	/// </summary>
	/// <returns>Kopia obiektu</returns>
	virtual GameObject* clone() const override = 0;
	/// <summary>
	/// Wirtualny destruktor
	/// </summary>
	virtual ~InteractionableGameObject();
};
