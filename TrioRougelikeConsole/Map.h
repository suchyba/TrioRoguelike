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
	/// Wygl¹d obiektu przechowywany zbudowany z Pokoi
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
	/// Wygl¹d obiektu zbudowany z GameObject
	/// </summary>
	//Room** mapDesign;
	vector<vector<vector<GameObject*>>> mapDesignObjects;
	/// <summary>
	/// WskaŸnik na obiekt gracza.
	/// </summary>
	PlayerGameObject* player;

	/// <summary>
	/// Lista obeitków dynamicznych na mapie (do przeniesienia).
	/// </summary>
	vector<DynamicGameObject*> dynamicList;


public:
	void clearDesign();
	/// <summary>
	/// Konstruktor tworz¹cy obiekt.
	/// </summary>
	/// <param name="_width">D³ugoœæ obiektu</param>
	/// <param name="_height">Wysokoœæ obiektu</param>
	Map(int _width, int _height, const FloorGameObject& _floor);

	/// <summary>
	/// Metoda tworzaca tablice GameObject z tablicy pokoi
	/// </summary>
	void mergeRoomsIntoMap();

	/// <summary>
	/// Metoda pozwalajaca zmieniac GameObject w tablicy mapDesignObjects.
	/// </summary>
	/// <param name="_object">Obiekt do podmiany</param>
	/// <param name="_width">D³ugoœæ obiektu</param>
	/// <param name="_height">Wysokoœæ obiektu</param>
	/// <param name="_depth">G³êbokoœæ obiektu</param>
	void setObjectInMap(GameObject* _object, int _width, int _height, int _depth);

	/// <summary>
	/// Metoda zwracaj¹ca obiekt z tablicy mapDesignObjects.
	/// </summary>
	/// <param name="_width">D³ugoœæ obiektu</param>
	/// <param name="_height">Wysokoœæ obiektu</param>
	/// <param name="_depth">G³êbokoœæ obiektu</param>
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
	/// Metoda pozwalajaca zmieniaæ wybrane komórki w tablicy mapDesign.
	/// </summary>
	/// <param name="_width">D³ugoœæ obiektu</param>
	/// <param name="_height">Wysokoœæ obiektu</param>
	/// <param name="_object">Obiekt w komórce[_width][_height] tablicy mapDesign</param>
	void setRoomInMap(int _width, int _height, Room& _object);

	/// <summary>
	/// Metoda zwracaj¹ca pokoj z tablicy mapDesign.
	/// </summary>
	/// <param name="_width">D³ugoœæ obiektu</param>
	/// <param name="_height">Wysokoœæ obiektu</param>
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
	
	/// <summary>
	/// Zmieniajaca pozycje grasza lub stworków
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

