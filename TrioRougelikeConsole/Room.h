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
	/// Wygl�d obiektu.
	/// </summary>
	GameObject*** roomDesign;

public:
	/// <summary>
	/// Konstruktor domy�lny tworz�cy obiekt.
	/// </summary>
	Room();

	/// <summary>
	/// Copy konstruktor domy�lny tworz�cy obiekt.
	/// </summary>
	Room(const Room& other);

	/// <summary>
	/// Konstruktor tworz�cy obiekt.
	/// </summary>
	/// <param name="_width">D�ugo�� obiektu</param>
	/// <param name="_height">Wysoko�� obiektu</param>
	/// <param name="_depth">G��boko�� obiektu</param>
	Room(int _width, int _height, int _depth);

	/// <summary>
	/// Metoda dost�powa do pola width.
	/// </summary>
	/// <returns>width</returns>
	int getWidth() const;
	/// <summary>
	/// Metoda dost�powa do pola height.
	/// </summary>
	/// <returns>height</returns>
	int getHeight() const;
	/// <summary>
	/// Metoda dost�powa do pola depth.
	/// </summary>
	/// <returns>depth</returns>
	int getDepth() const;
	/// <summary>
	/// Metoda umo�liaj�ca wy�wietlenie wygl�du obiektu Room.
	/// </summary>
	void showRoom();

	/// <summary>
	/// Metoda pozwalajaca zmienia� wybrane kom�rki w tablicy roomDesign.
	/// </summary>
	/// <param name="_width">D�ugo�� obiektu</param>
	/// <param name="_height">Wysoko�� obiektu</param>
	/// <param name="_depth">G��boko�� obiektu</param>
	/// <param name="_object">Obiekt w kom�rce[_width][_height][_depth] tablicy roomDesign</param>
	void setElementInRoom(int _width, int _height, int _depth, GameObject _object);

	/// <summary>
	/// Metoda pozwalajaca zmienia� wybrane kom�rki w tablicy roomDesign.
	/// </summary>
	/// <param name="_width">D�ugo�� obiektu</param>
	/// <param name="_height">Wysoko�� obiektu</param>
	/// <param name="_width">G��boko�� obiektu</param>
	/// <param name="_object">Obiekt w kom�rce[_width][_height][_depth] tablicy roomDesign</param>
	void setElementInRoom2(int _width, int _height, int _depth, GameObject& _object);

	/// <summary>
	/// Metoda pozwalajaca zobaczy� nazwe wybranego element w tablicy roomDesign.
	/// </summary>
	/// <param name="_width">D�ugo�� obiektu</param>
	/// <param name="_height">Wysoko�� obiektu</param>
	/// <param name="_depth">G��boko�� obiektu</param>
	string getRoomElement(int _width, int _height, int _depth);

	/// <summary>
	/// Metoda zwracajaca obiekt roomDesign.
	/// </summary>
	/// <param name="_width">D�ugo�� obiektu</param>
	/// <param name="_height">Wysoko�� obiektu</param>
	/// <param name="_depth">G��boko�� obiektu</param>
	GameObject getRoomElement2(int _width, int _height, int _depth);

	/// <summary>
	/// Metoda pozwalajaca zobaczy� reprezentacje wybranego element w tablicy roomDesign.
	/// </summary>
	/// <param name="_width">D�ugo�� obiektu</param>
	/// <param name="_height">Wysoko�� obiektu</param>
	/// <param name="_width">G��boko�� obiektu</param>
	GraphicalSymbol getRoomElementRepresentation(int _width, int _height, int _depth);
};

