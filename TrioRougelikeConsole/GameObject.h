#pragma once
#include <iostream>
#include "GraphicalSymbol.h"

using namespace std;

/// <summary>
/// Podstawowa klasa obeiktu w grze.
/// </summary>
class GameObject
{
protected:
	/// <summary>
	/// Nazwa obiektu.
	/// </summary>
	string name;
	/// <summary>
	/// Reprezentacja graficzna obiektu.
	/// </summary>
	GraphicalSymbol representation;
public:
	/// <summary>
	/// Konstruktor tworz¹cy obiekt.
	/// </summary>
	/// <param name="Name">Nazwa obiektu</param>
	/// <param name="Symbol">Reprezentacja graficzna obiektu</param>
	GameObject(string Name, GraphicalSymbol Symbol);
	/// <summary>
	/// Konstruktor domyœlny u¿ywany do tworzenia pustych obiektów.
	/// </summary>
	GameObject();

	/// <summary>
	/// Metoda dostêpowa do pola name.
	/// </summary>
	/// <returns>name</returns>
	string getName() const;
	/// <summary>
	/// Metoda dostêpowa do pola representation.
	/// </summary>
	/// <returns>representation</returns>
	GraphicalSymbol getRepresentation() const;

	/// <summary>
	/// Metoda dostêpowa do pola representation.
	/// </summary>
	/// <param name="rep">Nowa reprezentacja graficzna obiektu</param>
	void setGraphicalRepresentation(const GraphicalSymbol& rep);
};
