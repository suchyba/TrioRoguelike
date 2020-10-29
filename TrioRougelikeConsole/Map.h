#pragma once
#include "Room.h"
#include <vector>
class Map
{
protected:
	/// <summary>
	/// Wymiary obiektu.
	/// </summary>
	int width;
	int height;
	/// <summary>
	/// Wygl�d obiektu.
	/// </summary>
	Room** mapDesign;
	/// <summary>
	/// Tablica wszystkich pokoji.
	/// </summary>
	Room* rooms;
	int size = 0;

public:
	/// <summary>
	/// Konstruktor tworz�cy obiekt.
	/// </summary>
	/// <param name="_width">D�ugo�� obiektu</param>
	/// <param name="_height">Wysoko�� obiektu</param>
	Map(int _width, int _height);

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
	/// Metoda umo�liaj�ca wy�wietlenie wygl�du obiektu Map.
	/// </summary>
	void showMap();

	/// <summary>
	/// Metoda pozwalajaca zmienia� wybrane kom�rki w tablicy mapDesign.
	/// </summary>
	/// <param name="_width">D�ugo�� obiektu</param>
	/// <param name="_height">Wysoko�� obiektu</param>
	/// <param name="_object">Obiekt w kom�rce[_width][_height] tablicy mapDesign</param>
	void setRoomInMap(int _width, int _height, Room _object);

	/// <summary>
	/// Metoda pozwalajaca zobaczy� wygl�d pokoju z tablicy mapDesign.
	/// </summary>
	/// <param name="_width">D�ugo�� obiektu</param>
	/// <param name="_height">Wysoko�� obiektu</param>
	void getRoomFromMap(int _width, int _height);
	/// <summary>
	/// Metoda dodajaca pokoje do tablicy pokoi
	/// </summary>
	void addRoom(Room& _object);

	/// <summary>
	/// Generuje mape
	/// </summary>
	int generateMap();

	/// <summary>
	/// Generuje po��czenia pomi�dzy pokojami w mape
	/// </summary>
	int generateMapConnections();
	/// <summary>
	/// Mapuje po��czenia powsta�e w room na room1 i room2
	/// </summary>
	/// <param name="room">Zmapowane pokoje room1 i room2 w jeden</param>
	/// <param name="room1">Pok�j do po��czenia korytarzem</param>
	/// <param name="room2">Pok�j do po��czenia korytarzem</param>
	/// <param name="possitionX">Wysoko�� na kt�rej znajduje si� element od kt�rego zacznie si� tworzenie korytarza</param>
	/// <param name="possitionY">Szeroko�� na kt�rej znajduje si� element od kt�rego zacznie si� tworzenie korytarza</param>
	int createPath(Room& room, Room& room1, Room& room2, int possitionX, int possitionY);
	/// <summary>
	/// ��czy dwa pokoje korytarzem
	/// </summary>
	int connect(Room& room1, Room& room2,int direction);
};

