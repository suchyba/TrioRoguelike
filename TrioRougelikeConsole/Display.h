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
	/// Funkcja odpowiedzialna za statystyki gracza
	/// </summary>
	virtual void drawStats(PlayerGameObject* player) = 0;
	/// <summary>
	/// Funkcja odpowiedzialna za rysowanie mapy
	/// </summary>
	virtual void drawMap(Map* map) = 0;
	/// <summary>
	/// Funkcja odpowiedzialna za ekran Game Over
	/// </summary>
	virtual void drawOver() = 0;
};