#include "Room.h"
using namespace std;
Room::Room(int _width, int _height, int _depth) : width(_width), height(_height), depth(_depth)
{
    for (int i = 0; i < _width; i++)
    {
        vector < vector<GameObject* >>  tmp;
        for (int j = 0; j < _height; j++)
        {
            vector<GameObject*> tmp2;
            for (int k = 0; k < _depth; k++)
            {
                tmp2.push_back(nullptr);
            }
            tmp.push_back(tmp2);
        }
        roomDesign.push_back(tmp);
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


void Room::setElementInRoom(int _width, int _height, int _depth, GameObject& _object)
{
    roomDesign[_width][_height][_depth] = &_object;
}

GameObject* Room::getRoomElement(int _width, int _height, int _depth)
{
    return roomDesign[_width][_height][_depth];
}