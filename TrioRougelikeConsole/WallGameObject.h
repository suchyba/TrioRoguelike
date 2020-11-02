#pragma once
#include "GameObject.h"
#include "Colliding.h"
#include "GraphicalSymbol.h"

class WallGameObject : public GameObject, public Colliding
{
public:
	/// <summary>
	/// Metoda wywo�ywana w przypadku, gdy jaki� obiekt zderza si� z obiektem.
	/// </summary>
	/// <param name="sender">Obiekt, kt�ry si� zderza</param>
	virtual void onCollide(GameObject& sender) override;
	/// <summary>
	/// Konstruktor obiektu
	/// </summary>
	/// <param name="Name">Nazwa obiektu</param>
	/// <param name="Symbol">Reprezentacja graficzna obiektu</param>
	WallGameObject(string Name, GraphicalSymbol Symbol);
	/// <summary>
	/// Metoda tworz�ca kopi� obiektu.
	/// </summary>
	/// <returns>Kopia obiektu</returns>
	virtual GameObject* clone() const override;

	/// <summary>
	/// Wirtualny destruktor
	/// </summary>
	virtual ~WallGameObject();
};