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
	/// Wygl¹d obiektu.
	/// </summary>
	Room** mapDesign;
	/// <summary>
	/// Tablica wszystkich pokoji.
	/// </summary>
	Room* rooms;
	int size = 0;

public:
	/// <summary>
	/// Konstruktor tworz¹cy obiekt.
	/// </summary>
	/// <param name="_width">D³ugoœæ obiektu</param>
	/// <param name="_height">Wysokoœæ obiektu</param>
	Map(int _width, int _height);

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
	/// Metoda umo¿liaj¹ca wyœwietlenie wygl¹du obiektu Map.
	/// </summary>
	void showMap();

	/// <summary>
	/// Metoda pozwalajaca zmieniaæ wybrane komórki w tablicy mapDesign.
	/// </summary>
	/// <param name="_width">D³ugoœæ obiektu</param>
	/// <param name="_height">Wysokoœæ obiektu</param>
	/// <param name="_object">Obiekt w komórce[_width][_height] tablicy mapDesign</param>
	void setRoomInMap(int _width, int _height, Room _object);

	/// <summary>
	/// Metoda pozwalajaca zobaczyæ wygl¹d pokoju z tablicy mapDesign.
	/// </summary>
	/// <param name="_width">D³ugoœæ obiektu</param>
	/// <param name="_height">Wysokoœæ obiektu</param>
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
	/// Generuje po³¹czenia pomiêdzy pokojami w mape
	/// </summary>
	int generateMapConnections();
	/// <summary>
	/// Mapuje po³¹czenia powsta³e w room na room1 i room2
	/// </summary>
	/// <param name="room">Zmapowane pokoje room1 i room2 w jeden</param>
	/// <param name="room1">Pokój do po³¹czenia korytarzem</param>
	/// <param name="room2">Pokój do po³¹czenia korytarzem</param>
	/// <param name="possitionX">Wysokoœæ na której znajduje siê element od którego zacznie siê tworzenie korytarza</param>
	/// <param name="possitionY">Szerokoœæ na której znajduje siê element od którego zacznie siê tworzenie korytarza</param>
	int createPath(Room& room, Room& room1, Room& room2, int possitionX, int possitionY);
	/// <summary>
	/// £¹czy dwa pokoje korytarzem
	/// </summary>
	int connect(Room& room1, Room& room2,int direction);
};

