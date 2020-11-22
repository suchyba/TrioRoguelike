#pragma once
#include <allegro5/allegro.h>

/// <summary>
/// Klasa dla obiektów graficznej reprezentacji obiektów gry.
/// </summary>
class GraphicalSymbol
{
private:
	/// <summary>
	/// Reprezentacja w grze za pomoc¹ symbolu ASCI
	/// </summary>
	char charSymbol;
	/// <summary>
	/// Kolor samego symbolu.
	/// </summary>
	int foregroundColor;
	/// <summary>
	/// Kolor t³a na którym znajduje siê symbol (-1 oznacza pobranie koloru t³a, przedmiotu na którym siê znajduje).
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
	/// <param name="charSymbol">Reprezentacja za pomoc¹ znaku z tablicy ASCI</param>
	/// <param name="foreground">Kolor samego znaku.</param>
	/// <param name="background">Kolor t³a, na którym znajduje siê przedmiot (-1 oznacza przezroczyste t³o)</param>
	GraphicalSymbol(char charSymbol, int foreground, int background);
	/// <summary>
	/// Konstruktor tworzacy reprezentacjê w interfejsie graficznym
	/// </summary>
	/// <param name="image"></param>
	GraphicalSymbol(ALLEGRO_BITMAP* image);
	/// <summary>
	/// Metoda dostêpowa do pola charSymbol
	/// </summary>
	/// <returns>charSymbol</returns>
	char getCharSymbol() const;
	/// <summary>
	/// Metoda zwracaj¹ca kolor w formie przyjmowanej przez konsolê.
	/// </summary>
	/// <returns>Wartoœæ koloru w formie kolorów konsolowych.</returns>
	int getColor() const;
	/// <summary>
	/// Metoda pozwalaj¹ca zmieniæ wartoœci kolorów.
	/// </summary>
	/// <param name="foreground">Nowa wartoœæ dla pola foregroundColor</param>
	/// <param name="background">Nowa wartoœæ dla pola backgroundColor</param>
	void setColors(int foreground, int background);
	/// <summary>
	/// Metoda dostêpowa do pola sprite
	/// </summary>
	/// <returns>WskaŸnik na sprite</returns>
	const ALLEGRO_BITMAP* getSprite() const;
};