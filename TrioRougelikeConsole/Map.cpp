#include "Map.h"
#include <list>
#include "FloorGameObject.h"
#include <iostream>
#include <Windows.h>
#include <time.h>
#include "ItemGameObject.h"

using namespace std;

void Map::clearDesign()
{
	mapDesign.clear();
	mapDesignObjects.clear();

	for (int i = 0; i < width; i++)
	{
		vector<Room*> tmp;
		for (int j = 0; j < height; j++)
		{
			tmp.push_back(NULL);
		}
		mapDesign.push_back(tmp);
	}
}

Map::Map(int _width, int _height, const FloorGameObject& _floor) : width(_width), height(_height), floor(new FloorGameObject(_floor)), player(NULL)
{
	for (int i = 0; i < _width; i++)
	{
		vector<Room*> tmp;
		for (int j = 0; j < _height; j++)
		{
			tmp.push_back(NULL);
		}
		mapDesign.push_back(tmp);
	}
}
GameObject* Map::getFloor() const
{
	return floor;
}
void Map::setFloor(FloorGameObject& _object)
{
	floor = new FloorGameObject(_object);
}
int Map::getWidth() const
{
	return width;
}

int Map::getHeight() const
{
	return height;
}

void Map::setRoomInMap(int _width, int _height, Room& _object)
{
	*mapDesign[_width][_height] = _object;
}
Room* Map::getRoomFromMap(int _width, int _height) const
{
	return mapDesign[_width][_height];
}
void Map::addRoom(Room& _object)
{
	rooms.push_back(new Room(_object));
}
int Map::generateMap()
{
	cout << "[MAP] Generating Map" << endl;
	clearDesign();

	int randRoom;
	int roz = width * height;
	int* chosArr = new int[roz];
	int end = 0;
	srand(time(NULL));
	int zakres = rooms.size();
	bool flag1 = false;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			while (true)
			{
				randRoom = rand() % zakres;
				for (int x = 0; x < end; x++)
				{
					if (chosArr[x] == randRoom)
					{
						flag1 = true;
						break;
					}
					flag1 = false;
				}
				if (flag1 == false)
				{
					break;
				}
			}
			chosArr[end] = randRoom;
			end++;
			mapDesign[i][j] = rooms[randRoom];
		}
	}
	if (generateMapConnections() == -1)
	{
		return -1;
	}
	mergeRoomsIntoMap();
	delete chosArr;
}
struct A {
public:
	A() {}
	A(int x, int y)
	{
		array[0] = x;
		array[1] = y;
	}
	int array[2];
};


int Map::generateMapConnections()
{
	cout << "[MAP] Generating map connections." << endl;
	int randWidthStart = rand() % (width);
	int randheightStart = rand() % (height);
	int randWidthEnd = rand() % (width);
	int randheightEnd = rand() % (height);
	while ((randWidthStart == randWidthEnd) && (randheightStart == randheightEnd))
	{
		randWidthEnd = rand() % (width);
		randheightEnd = rand() % (height);
	}
	bool** visited = new bool* [width];
	for (int i = 0; i < width; i++)
	{
		visited[i] = new bool[height];
		for (int j = 0; j < height; ++j)
			visited[i][j] = false;
	}

	A* list = new A[100];
	int end = 0;
	list[end] = A(randWidthStart, randheightStart);
	end++;
	int randDirection;
	int iterator = 0;

	visited[randWidthStart][randheightStart] = true;

	++iterator;

	while (iterator != width * height)
	{
		if (randheightStart - 1 >= 0 && visited[randWidthStart][randheightStart - 1] == false)
		{
			randheightStart = randheightStart - 1;
			visited[randWidthStart][randheightStart] = true;
			list[end] = A(randWidthStart, randheightStart);
			end++;
			iterator += 1;
			if (connect(*mapDesign[randWidthStart][randheightStart], *mapDesign[randWidthStart][randheightStart + 1], 0) == -1)
			{
				return -1;
			}
		}
		else if (randWidthStart - 1 >= 0 && visited[randWidthStart - 1][randheightStart] == false)
		{
			randWidthStart = randWidthStart - 1;
			visited[randWidthStart][randheightStart] = true;
			list[end] = A(randWidthStart, randheightStart);
			end++;
			iterator += 1;
			if (connect(*mapDesign[randWidthStart][randheightStart], *mapDesign[randWidthStart + 1][randheightStart], 1) == -1)
			{

				return -1;
			}
		}
		else if (randheightStart + 1 < height && visited[randWidthStart][randheightStart + 1] == false)
		{
			randheightStart = randheightStart + 1;
			visited[randWidthStart][randheightStart] = true;
			list[end] = A(randWidthStart, randheightStart);
			end++;
			iterator += 1;

			if (connect(*mapDesign[randWidthStart][randheightStart - 1], *mapDesign[randWidthStart][randheightStart], 2) == -1)
			{

				return -1;
			}
		}
		else if (randWidthStart + 1 < width && visited[randWidthStart + 1][randheightStart] == false)
		{
			randWidthStart = randWidthStart + 1;
			visited[randWidthStart][randheightStart] = true;
			list[end] = A(randWidthStart, randheightStart);
			end++;
			iterator += 1;

			if (connect(*mapDesign[randWidthStart - 1][randheightStart], *mapDesign[randWidthStart][randheightStart], 3) == -1)
			{
				return -1;
			}
		}
		else
		{
			end--;

			randWidthStart = list[end].array[0];
			randheightStart = list[end].array[1];
		}
	}
	for (int i = 0; i < width; i++)
	{
		delete visited[i];
	}
	delete visited;
	delete list;
}

int Map::createPath(Room& room, Room& room1, Room& room2, int possitionX, int possitionY)
{
	cout << "[MAP] Creating path" << endl;
	int randWidthStart = possitionX;
	int randheightStart = possitionY;

	bool** visited = new bool* [room.getWidth()];
	for (int i = 0; i < room.getWidth(); i++)
		visited[i] = new bool[room.getHeight()];

	for (int i = 0; i < room.getWidth(); i++)
		for (int j = 0; j < room.getHeight(); j++)
			visited[i][j] = false;

	A* list = new A[room.getWidth() * room.getHeight()];
	int end = 0;
	list[end] = A(randWidthStart, randheightStart);
	end++;
	visited[randWidthStart][randheightStart] = true;

	if (room.getHeight() > 11)
	{
		while (true)
		{
			if (randheightStart + 1 < room.getHeight() && visited[randWidthStart][randheightStart + 1] == false)
			{

				randheightStart += 1;
				visited[randWidthStart][randheightStart] = true;
				list[end] = A(randWidthStart, randheightStart);
				end++;
				room.setElementInRoom(randWidthStart, randheightStart, 0, *(getFloor()->clone()));
			}
			else if (randWidthStart + 1 < room.getWidth() && visited[randWidthStart + 1][randheightStart] == false)
			{

				randWidthStart += 1;
				visited[randWidthStart][randheightStart] = true;
				list[end] = A(randWidthStart, randheightStart);
				end++;
				room.setElementInRoom(randWidthStart, randheightStart, 0, *(getFloor()->clone()));
			}
			else if (randWidthStart - 1 >= 0 && visited[randWidthStart - 1][randheightStart] == false)
			{
				randWidthStart -= 1;
				visited[randWidthStart][randheightStart] = true;
				list[end] = A(randWidthStart, randheightStart);
				end++;
				room.setElementInRoom(randWidthStart, randheightStart, 0, *(getFloor()->clone()));
			}

			else
			{


				if (end == 0)
					return -1;
				else
				{
					end--;
					randWidthStart = list[end].array[0];
					randheightStart = list[end].array[1];
				}
			}
			if (randheightStart > room.getHeight() / 2 && room.getHeight() > 11)
			{
				if (randheightStart + 1 < room.getHeight())
				{
					if (room.getRoomElement(randWidthStart, randheightStart + 1, 0)->getName() == "FLOOR")
						break;
				}
				if (randWidthStart + 1 < room.getWidth())
				{
					if (room.getRoomElement(randWidthStart + 1, randheightStart, 0)->getName() == "FLOOR")
						break;
				}

				if (randWidthStart - 1 >= 0)
				{
					if (room.getRoomElement(randWidthStart - 1, randheightStart, 0)->getName() == "FLOOR")
						break;
				}
			}
		}
	}
	else
	{
		while (true)
		{
			visited[randWidthStart][randheightStart] = true;

			if (randWidthStart + 1 < room.getWidth() && visited[randWidthStart + 1][randheightStart] == false)
			{

				randWidthStart += 1;
				visited[randWidthStart][randheightStart] = true;
				list[end] = A(randWidthStart, randheightStart);
				end++;
				room.setElementInRoom(randWidthStart, randheightStart, 0, *(getFloor()->clone()));

			}
			else if (randheightStart + 1 < room.getHeight() && visited[randWidthStart][randheightStart + 1] == false)
			{

				randheightStart += 1;
				visited[randWidthStart][randheightStart] = true;
				list[end] = A(randWidthStart, randheightStart);
				end++;
				room.setElementInRoom(randWidthStart, randheightStart, 0, *(getFloor()->clone()));
			}
			else if (randheightStart - 1 <= 0 && visited[randWidthStart][randheightStart - 1] == false)
			{

				randheightStart -= 1;
				visited[randWidthStart][randheightStart] = true;
				list[end] = A(randWidthStart, randheightStart);
				end++;
				room.setElementInRoom(randWidthStart, randheightStart, 0, *(getFloor()->clone()));
			}
			else
			{
				if (end == 0)
					return -1;
				else
				{

					end--;
					randWidthStart = list[end].array[0];
					randheightStart = list[end].array[1];
				}
			}
			if (randWidthStart > room.getWidth() / 2 && room.getWidth() > 11)
			{
				if (randheightStart - 1 >= 0)
				{
					if (room.getRoomElement(randWidthStart, randheightStart - 1, 0)->getName() == "FLOOR")
						break;
				}
				if (randWidthStart + 1 < room.getWidth())
				{
					if (room.getRoomElement(randWidthStart + 1, randheightStart, 0)->getName() == "FLOOR")
						break;
				}
				if (randheightStart + 1 < room.getHeight())
				{
					if (room.getRoomElement(randWidthStart, randheightStart + 1, 0)->getName() == "FLOOR")
						break;
				}
			}
		}
	}
	if (room.getHeight() > room.getWidth())
	{

		for (int i = 0; i < room.getWidth(); i++)
		{
			for (int j = 0; j < room.getHeight(); j++)
			{
				if (j >= 10)
				{
					GameObject* g = room.getRoomElement(i, j, 0);
					if (g != NULL)
						g = g->clone();
					room2.setElementInRoom(i, j - 10, 0, *g);
				}
				else
				{
					GameObject* g = room.getRoomElement(i, j, 0);
					if (g != NULL)
						g = g->clone();
					room1.setElementInRoom(i, j, 0, *g);
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < room.getWidth(); i++)
		{
			for (int j = 0; j < room.getHeight(); j++)
			{
				if (i >= 10)
				{
					GameObject* g = room.getRoomElement(i, j, 0);
					if (g != NULL)
						g = g->clone();
					room2.setElementInRoom(i - 10, j, 0, *g);
				}
				else
				{
					GameObject* g = room.getRoomElement(i, j, 0);
					if (g != NULL)
						g = g->clone();
					room1.setElementInRoom(i, j, 0, *g);
				}
			}
		}
	}
	for (int i = 0; i < room.getWidth(); i++)
	{
		delete visited[i];
	}
	delete visited;
	delete list;
}
int Map::connect(Room& room1, Room& room2, int direction)
{
	//cout << "[MAP] Connecting rooms" << endl;
	int possitionX = -1;
	int possitionY = -1;

	if (direction == 0 || direction == 2)
	{
		bool flag = false;
		for (size_t j = room1.getHeight() - 1; j >= 0; j--)
		{
			for (size_t i = 0; i < room1.getWidth(); i++)
			{

				if (room1.getRoomElement(i, j, 0)->getName() == "FLOOR")
				{
					possitionX = i;
					possitionY = j;
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
		Room room(10, 20, 4);
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				GameObject* g = room1.getRoomElement(i, j, 0);
				if (g != NULL)
					g = g->clone();
				room.setElementInRoom(i, j, 0, *g);
			}
		}
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				GameObject* g = room2.getRoomElement(i, j, 0);
				if (g != NULL)
					g = g->clone();
				room.setElementInRoom(i, j + 10, 0, *g);
			}
		}
		if (createPath(room, room1, room2, possitionX, possitionY) == -1)
			return -1;
	}
	else if (direction == 1 || direction == 3)
	{
		bool flag = false;
		for (int i = room1.getWidth() - 1; i >= 0; i--)
		{
			for (int j = 0; j < room1.getHeight(); j++)
			{

				if (room1.getRoomElement(i, j, 0)->getName() == "FLOOR")
				{
					possitionX = i;
					possitionY = j;
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
		Room room(20, 10, 4);
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				GameObject* g = room1.getRoomElement(i, j, 0);
				if (g != NULL)
					g = g->clone();
				room.setElementInRoom(i, j, 0, *g);
			}
		}
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				GameObject* g = room2.getRoomElement(i, j, 0);
				if (g != NULL)
					g = g->clone();
				room.setElementInRoom(i + 10, j, 0, *g);
			}
		}
		if (createPath(room, room1, room2, possitionX, possitionY) == -1)
			return -1;
	}
}

void Map::mergeRoomsIntoMap()
{
	cout << "[MAP] Marging into array" << endl;
	vector < vector<GameObject* >>  tmp;
	for (int i = 0; i < mapDesign.size() * 10; i++)
	{
		vector<vector<GameObject*>> tmp2;
		for (int j = 0; j < mapDesign[0].size() * 10; j++)
		{
			vector<GameObject*> tmp;
			for (int k = 0; k < mapDesign[0][0]->getDepth(); k++)
			{
				tmp.push_back(NULL);
			}
			tmp2.push_back(tmp);
		}
		mapDesignObjects.push_back(tmp2);
	}
	for (int i = 0; i < mapDesign.size(); i++)
	{
		for (int j = 0; j < mapDesign[0].size(); j++)
		{
			for (int x = 0; x < 10; x++)
			{
				for (int y = 0; y < 10; y++)
				{
					for (int z = 0; z < mapDesign[0][0]->getDepth(); z++)
					{
						GameObject* g = mapDesign[i][j]->getRoomElement(x, y, z);
						if (g != NULL)
						{
							g = g->clone();
							DynamicGameObject* d = dynamic_cast<DynamicGameObject*>(g);
							if (d != NULL)
								dynamicList.push_back(d);
						}

						mapDesignObjects[x + (10 * i)][y + (10 * j)][z] = g;
					}
				}
			}
		}
	}
}
bool Map::setObjectInMap(GameObject* _object, int _width, int _height, int _depth)
{
	if (_width >= mapDesignObjects.size() || _width < 0 || _height >= mapDesignObjects[_width].size() || _height < 0 || _depth < 0 || _depth >= mapDesignObjects[_width][_height].size()
		|| (mapDesignObjects[_width][_height][_depth] != NULL && _object != NULL))
		return false;

	if (_object == NULL)
	{
		DynamicGameObject* d = dynamic_cast<DynamicGameObject*>(mapDesignObjects[_width][_height][_depth]);
		if (d)
		{
			for (int i = 0; i < dynamicList.size(); ++i)
			{
				if (dynamicList[i] == d)
					dynamicList.erase(dynamicList.begin() + i);
			}
		}
	}

	mapDesignObjects[_width][_height][_depth] = _object;
	return true;
}
GameObject* Map::getObjectInMap(int _width, int _height, int _depth) const
{
	if (_width >= mapDesignObjects.size() || _width < 0 || _height >= mapDesignObjects[_width].size() || _height < 0 || _depth < 0 || _depth >= mapDesignObjects[_width][_height].size())
		return NULL;

	return mapDesignObjects[_width][_height][_depth];
}

void Map::move(CreatureGameObject& _object, int x, int y)
{
	if (x == 0 && y == 0)
		return;


	for (int i = 0; i < mapDesignObjects.size(); i++)
	{
		for (int j = 0; j < mapDesignObjects[i].size(); j++)
		{
			if (mapDesignObjects[i][j][2] == &_object)
			{
				if (i + x > mapDesignObjects.size() || i + x < 0 || j + y > mapDesignObjects[i].size() || j + y < 0)
					return;
				//cout << "[MAP] Moving " << _object.getName() << "(" << x << ", " << y << ")[" << i + x << ", " << j + y << "]" << endl;

				auto p = dynamic_cast<PlayerGameObject*>(&_object);
				for (int z = 0; z < 3; ++z)
				{
					if (p)
					{
						auto inrObj = dynamic_cast<InteractionableGameObject*>(mapDesignObjects[i + x][j + y][z]);
						if (inrObj != NULL)
						{
							inrObj->onInteraction();
						}
						auto item = dynamic_cast<ItemGameObject*>(mapDesignObjects[i + x][j + y][z]);
						if (item)
						{
							int slot = p->getFirstEmptySlot();
							if (slot == -1)
								slot = 0;
							p->equipItem((ItemGameObject*)item->clone(), slot);
							mapDesignObjects[i + x][j + y][z] = NULL;
						}
					}
					auto colObj = dynamic_cast<Colliding*>(mapDesignObjects[i + x][j + y][z]);
					if (colObj != NULL)
					{
						colObj->onCollide(_object);
						return;
					}
				}
				mapDesignObjects[i + x][j + y][2] = mapDesignObjects[i][j][2];
				mapDesignObjects[i][j][2] = NULL;
				return;
			}
		}
	}
}

PlayerGameObject* Map::getPlayer() const
{
	return player;
}

void Map::setPlayer(PlayerGameObject* p)
{
	player = p;
}

void Map::refreshDynamic()
{
	for (auto d : dynamicList)
	d->onRefresh();
}

void Map::removeFromMap(GameObject& object)
{
	for (int i = 0; i < mapDesignObjects.size(); ++i)
	{
		for (int j = 0; j < mapDesignObjects[i].size(); ++j)
		{
			for (int k = 0; k < mapDesignObjects[i][j].size(); ++k)
			{
				if (mapDesignObjects[i][j][k] == &object)
				{
					DynamicGameObject* d = dynamic_cast<DynamicGameObject*>(mapDesignObjects[i][j][k]);
					if (d)
					{
						for (int i = 0; i < dynamicList.size(); ++i)
						{
							if (dynamicList[i] == d)
								dynamicList.erase(dynamicList.begin() + i);
						}
					}
					delete mapDesignObjects[i][j][k];
					mapDesignObjects[i][j][k] = NULL;
				}
			}
		}
	}
}

void Map::randomizePlayerPos()
{
	srand(time(NULL));
	int y = rand() % (height + 1);
	int x = rand() % (width + 1);
	while (true)
	{
		x = rand() % (width + 1);
		y = rand() % (height + 1);

		if (mapDesignObjects[x][y][0] && mapDesignObjects[x][y][0]->getName() == "FLOOR")
		{
			DynamicGameObject* d = dynamic_cast<DynamicGameObject*>(mapDesignObjects[x][y][2]);
			if (d)
			{
				for (int i = 0; i < dynamicList.size(); ++i)
				{
					if (dynamicList[i] == d)
						dynamicList.erase(dynamicList.begin() + i);
				}
			}

			mapDesignObjects[x][y][2] = player;
			break;
		}
	}
}

vector<vector<vector<GameObject*>>>* Map::getMapDesignObject()
{
	return &mapDesignObjects;
}
