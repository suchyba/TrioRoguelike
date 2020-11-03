#pragma once
#include "Room.h"
#include <vector>
#include "FloorGameObject.h"
#include "CreatureGameObject.h"
#include "PlayerGameObject.h"
class Map
{
protected:
	/// <summary>
	/// Wymiary obiektu.
	/// </summary>
	int width;
	int height;
	/// <summary>
	/// Wygl�d obiektu przechowywany zbudowany z Pokoi
	/// </summary>
	//Room** mapDesign;
	vector<vector<Room*> > mapDesign;
	/// <summary>
	/// Tablica wszystkich pokoji.
	/// </summary>
	vector<Room*> rooms;

	/// <summary>
	/// Obiekt floor wykorzystywany do laczenia pokoji.
	/// </summary>
	FloorGameObject* floor;

	/// <summary>
	/// Wygl�d obiektu zbudowany z GameObject
	/// </summary>
	//Room** mapDesign;
	vector<vector<vector<GameObject*>>> mapDesignObjects;
	/// <summary>
	/// Wska�nik na obiekt gracza.
	/// </summary>
	PlayerGameObject* player;

	/// <summary>
	/// Lista obeitk�w dynamicznych na mapie (do przeniesienia).
	/// </summary>
	vector<DynamicGameObject*> dynamicList;


public:
	void clearDesign();
	/// <summary>
	/// Konstruktor tworz�cy obiekt.
	/// </summary>
	/// <param name="_width">D�ugo�� obiektu</param>
	/// <param name="_height">Wysoko�� obiektu</param>
	Map(int _width, int _height, const FloorGameObject& _floor);

	/// <summary>
	/// Metoda tworzaca tablice GameObject z tablicy pokoi
	/// </summary>
	void mergeRoomsIntoMap();

	/// <summary>
	/// Metoda pozwalajaca zmieniac GameObject w tablicy mapDesignObjects.
	/// </summary>
	/// <param name="_object">Obiekt do podmiany</param>
	/// <param name="_width">D�ugo�� obiektu</param>
	/// <param name="_height">Wysoko�� obiektu</param>
	/// <param name="_depth">G��boko�� obiektu</param>
	void setObjectInMap(GameObject* _object, int _width, int _height, int _depth);

	/// <summary>
	/// Metoda zwracaj�ca obiekt z tablicy mapDesignObjects.
	/// </summary>
	/// <param name="_width">D�ugo�� obiektu</param>
	/// <param name="_height">Wysoko�� obiektu</param>
	/// <param name="_depth">G��boko�� obiektu</param>
	GameObject* getObjectInMap(int _width, int _height, int _depth) const;

	/// <summary>
	/// Metoda zwracajaca pole floor.
	/// </summary>
	/// <returns>floor</returns>
	FloorGameObject* getFloor() const;

	/// <summary>
	/// Metoda zmieniajaca pole floor.
	/// </summary>
	/// <returns>floor</returns>
	void setFloor(FloorGameObject& _object);

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
	/// Metoda pozwalajaca zmienia� wybrane kom�rki w tablicy mapDesign.
	/// </summary>
	/// <param name="_width">D�ugo�� obiektu</param>
	/// <param name="_height">Wysoko�� obiektu</param>
	/// <param name="_object">Obiekt w kom�rce[_width][_height] tablicy mapDesign</param>
	void setRoomInMap(int _width, int _height, Room& _object);

	/// <summary>
	/// Metoda zwracaj�ca pokoj z tablicy mapDesign.
	/// </summary>
	/// <param name="_width">D�ugo�� obiektu</param>
	/// <param name="_height">Wysoko�� obiektu</param>
	Room* getRoomFromMap(int _width, int _height) const;
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
	
	/// <summary>
	/// Zmieniajaca pozycje grasza lub stwork�w
	/// </summary>
	void move(CreatureGameObject& _object, int x, int y);

	PlayerGameObject* getPlayer() const;
	void setPlayer(PlayerGameObject* p);

	void refreshDynamic();

	void removeFromMap(GameObject& object);

	~Map()
	{
		for (int i = 0; i < mapDesign.size(); i++)
		{
			for (int j = 0; j < mapDesign[i].size(); j++)
			{
				delete mapDesign[i][j];
			}
		}
		for (int i = 0; i < rooms.size(); i++)
		{
			delete rooms[i];
		}
		delete floor;
	}
};

