#pragma once
#include "GameObject.h"

class FloorGameObject : public GameObject
{
public:
	/// <summary>
	/// Konstruktor obiektu
	/// </summary>
	/// <param name="Name">Nazwa obiektu</param>
	/// <param name="Symbol">Reprezentacja graficzna obiektu</param>
	FloorGameObject(string Name, GraphicalSymbol Symbol);
	/// <summary>
	/// Metoda tworz�ca kopi� obiektu.
	/// </summary>
	/// <returns>Kopia obiektu</returns>
	virtual GameObject* clone() const override;

	/// <summary>
	/// Wirtualny destruktor
	/// </summary>
	virtual ~FloorGameObject();
	FloorGameObject(string Name, GraphicalSymbol Symbol);
};