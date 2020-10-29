#include "Room.h"
using namespace std;
Room::Room() {}
Room::Room(const Room& other) {}
Room::Room(int _width, int _height, int _depth) : width(_width), height(_height), depth(_depth)
{
    roomDesign = new GameObject * *[_width];

    for (int i = 0; i < _width; i++)
    {
        roomDesign[i] = new GameObject * [_height];
        for (int j = 0; j < _height; j++)
        {
            roomDesign[i][j] = new GameObject[_depth];
        }
    }
}
int Room::getWidth() const
{
    return width;
}

int Room::getHeight() const
{
    return height;
}

int Room::getDepth() const
{
    return depth;
}

void Room::setElementInRoom(int _width, int _height, int _depth, GameObject _object)
{
    roomDesign[_width][_height][_depth] = _object;
}

void Room::setElementInRoom2(int _width, int _height, int _depth, GameObject& _object)
{
    roomDesign[_width][_height][_depth] = _object;
}


GameObject Room::getRoomElement2(int _width, int _height, int _depth)
{
    return roomDesign[_width][_height][_depth];
}

string Room::getRoomElement(int _width, int _height, int _depth)
{
    return roomDesign[_width][_height][_depth].getName();
}

GraphicalSymbol Room::getRoomElementRepresentation(int _width, int _height, int _depth)
{
    return roomDesign[_width][_height][_depth].getRepresentation();
}
void Room::showRoom()
{

    bool flag = false;
    for (short i = 0; i < height; i++)
    {
        for (short j = 0; j < width; j++)
        {
            cout << roomDesign[i][j][0].getRepresentation().getCharSymbol();
        }
        cout << endl;
    }
}