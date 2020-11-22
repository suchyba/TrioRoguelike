#pragma once
#include <allegro5/allegro.h>

/// <summary>
/// Klasa dla obiekt�w graficznej reprezentacji obiekt�w gry.
/// </summary>
class GraphicalSymbol
{
private:
	/// <summary>
	/// Reprezentacja w grze za pomoc� symbolu ASCI
	/// </summary>
	char charSymbol;
	/// <summary>
	/// Kolor samego symbolu.
	/// </summary>
	int foregroundColor;
	/// <summary>
	/// Kolor t�a na kt�rym znajduje si� symbol (-1 oznacza pobranie koloru t�a, przedmiotu na kt�rym si� znajduje).
	/// </summary>
	int backgroundColor;
	/// <summary>
	/// Sprite prezentowany w interfejsie graficznym
	/// </summary>
	ALLEGRO_BITMAP* sprite;
public:
	/// <summary>
	/// Konstruktor
	/// </summary>
	/// <param name="charSymbol">Reprezentacja za pomoc� znaku z tablicy ASCI</param>
	/// <param name="foreground">Kolor samego znaku.</param>
	/// <param name="background">Kolor t�a, na kt�rym znajduje si� przedmiot (-1 oznacza przezroczyste t�o)</param>
	GraphicalSymbol(char charSymbol, int foreground, int background);
	/// <summary>
	/// Konstruktor tworzacy reprezentacj� w interfejsie graficznym
	/// </summary>
	/// <param name="image"></param>
	GraphicalSymbol(ALLEGRO_BITMAP* image);
	/// <summary>
	/// Metoda dost�powa do pola charSymbol
	/// </summary>
	/// <returns>charSymbol</returns>
	char getCharSymbol() const;
	/// <summary>
	/// Metoda zwracaj�ca kolor w formie przyjmowanej przez konsol�.
	/// </summary>
	/// <returns>Warto�� koloru w formie kolor�w konsolowych.</returns>
	int getColor() const;
	/// <summary>
	/// Metoda pozwalaj�ca zmieni� warto�ci kolor�w.
	/// </summary>
	/// <param name="foreground">Nowa warto�� dla pola foregroundColor</param>
	/// <param name="background">Nowa warto�� dla pola backgroundColor</param>
	void setColors(int foreground, int background);
	/// <summary>
	/// Metoda dost�powa do pola sprite
	/// </summary>
	/// <returns>Wska�nik na sprite</returns>
	const ALLEGRO_BITMAP* getSprite() const;
};