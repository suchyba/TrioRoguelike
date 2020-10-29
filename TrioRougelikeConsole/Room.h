#pragma once
#include <string>
#include "GameObject.h"
class Room
{
protected:
	/// <summary>
	/// Wymiary obiektu.
	/// </summary>
	int width;
	int height;
	int depth;
	/// <summary>
	/// Wygl¹d obiektu.
	/// </summary>
	GameObject*** roomDesign;

public:
	/// <summary>
	/// Konstruktor domyœlny tworz¹cy obiekt.
	/// </summary>
	Room();

	/// <summary>
	/// Copy konstruktor domyœlny tworz¹cy obiekt.
	/// </summary>
	Room(const Room& other);

	/// <summary>
	/// Konstruktor tworz¹cy obiekt.
	/// </summary>
	/// <param name="_width">D³ugoœæ obiektu</param>
	/// <param name="_height">Wysokoœæ obiektu</param>
	/// <param name="_depth">G³êbokoœæ obiektu</param>
	Room(int _width, int _height, int _depth);

	/// <summary>
	/// Metoda dostêpowa do pola width.
	/// </summary>
	/// <returns>width</returns>
	int getWidth() const;
	/// <summary>
	/// Metoda dostêpowa do pola height.
	/// </summary>
	/// <returns>height</returns>
	int getHeight() const;
	/// <summary>
	/// Metoda dostêpowa do pola depth.
	/// </summary>
	/// <returns>depth</returns>
	int getDepth() const;
	/// <summary>
	/// Metoda umo¿liaj¹ca wyœwietlenie wygl¹du obiektu Room.
	/// </summary>
	void showRoom();

	/// <summary>
	/// Metoda pozwalajaca zmieniaæ wybrane komórki w tablicy roomDesign.
	/// </summary>
	/// <param name="_width">D³ugoœæ obiektu</param>
	/// <param name="_height">Wysokoœæ obiektu</param>
	/// <param name="_depth">G³êbokoœæ obiektu</param>
	/// <param name="_object">Obiekt w komórce[_width][_height][_depth] tablicy roomDesign</param>
	void setElementInRoom(int _width, int _height, int _depth, GameObject _object);

	/// <summary>
	/// Metoda pozwalajaca zmieniaæ wybrane komórki w tablicy roomDesign.
	/// </summary>
	/// <param name="_width">D³ugoœæ obiektu</param>
	/// <param name="_height">Wysokoœæ obiektu</param>
	/// <param name="_width">G³êbokoœæ obiektu</param>
	/// <param name="_object">Obiekt w komórce[_width][_height][_depth] tablicy roomDesign</param>
	void setElementInRoom2(int _width, int _height, int _depth, GameObject& _object);

	/// <summary>
	/// Metoda pozwalajaca zobaczyæ nazwe wybranego element w tablicy roomDesign.
	/// </summary>
	/// <param name="_width">D³ugoœæ obiektu</param>
	/// <param name="_height">Wysokoœæ obiektu</param>
	/// <param name="_depth">G³êbokoœæ obiektu</param>
	string getRoomElement(int _width, int _height, int _depth);

	/// <summary>
	/// Metoda zwracajaca obiekt roomDesign.
	/// </summary>
	/// <param name="_width">D³ugoœæ obiektu</param>
	/// <param name="_height">Wysokoœæ obiektu</param>
	/// <param name="_depth">G³êbokoœæ obiektu</param>
	GameObject getRoomElement2(int _width, int _height, int _depth);

	/// <summary>
	/// Metoda pozwalajaca zobaczyæ reprezentacje wybranego element w tablicy roomDesign.
	/// </summary>
	/// <param name="_width">D³ugoœæ obiektu</param>
	/// <param name="_height">Wysokoœæ obiektu</param>
	/// <param name="_width">G³êbokoœæ obiektu</param>
	GraphicalSymbol getRoomElementRepresentation(int _width, int _height, int _depth);
};

