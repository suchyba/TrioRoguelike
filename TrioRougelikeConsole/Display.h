#pragma once
#include "PlayerGameObject.h"
#include "Map.h"

/// <summary>
/// Abstrakcyjna klasa udost�pniaj�ca metody do wy�wietlania zawarto�ci
/// </summary>
class Display
{
protected:

public:
	/// <summary>
	/// Funkcja odpowiedzialna za rysowanie menu
	/// </summary>
	virtual int drawMenu() = 0;
	/// <summary>
	/// Funkcja odpowiedzialna za Wypisanie autor�w
	/// </summary>
	virtual void showAuthors() = 0;
	/// <summary>
	/// Funkcja odpowiedzialna za Instrukcji Gry
	/// </summary>
	virtual void showInstructions() = 0;
	/// <summary>
	/// Funkcja rysuj�ca interfejs graficzny podczas gry
	/// </summary>
	/// <returns>Klawisz, kt�ry zosta� naci�ni�ty</returns>
	virtual int drawInterface(Map* map, PlayerGameObject* player) = 0;
	/// <summary>
	/// Funkcja odpowiedzialna za ekran Game Over
	/// </summary>
	virtual void drawOver() = 0;
	/// <summary>
	/// Wirtualny destruktor
	/// </summary>
	virtual ~Display();
};