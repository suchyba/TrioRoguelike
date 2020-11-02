#pragma once
#include "GameObject.h"
#include "Colliding.h"
#include "GraphicalSymbol.h"

class WallGameObject : public GameObject, public Colliding
{
public:
	/// <summary>
	/// Metoda wywo³ywana w przypadku, gdy jakiœ obiekt zderza siê z obiektem.
	/// </summary>
	/// <param name="sender">Obiekt, który siê zderza</param>
	virtual void onCollide(GameObject& sender) override;
	/// <summary>
	/// Konstruktor obiektu
	/// </summary>
	/// <param name="Name">Nazwa obiektu</param>
	/// <param name="Symbol">Reprezentacja graficzna obiektu</param>
	WallGameObject(string Name, GraphicalSymbol Symbol);
	/// <summary>
	/// Metoda tworz¹ca kopiê obiektu.
	/// </summary>
	/// <returns>Kopia obiektu</returns>
	virtual GameObject* clone() const override;

	/// <summary>
	/// Wirtualny destruktor
	/// </summary>
	virtual ~WallGameObject();
};