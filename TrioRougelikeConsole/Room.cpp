#include "Room.h"
using namespace std;
Room::Room(int _width, int _height, int _depth) : width(_width), height(_height), depth(_depth)
{
    for (int i = 0; i < _width; i++)
    {
        vector<vector<GameObject*>>  tmp;
        for (int j = 0; j < _height; j++)
        {
            vector<GameObject*> tmp2;
            for (int k = 0; k < _depth; k++)
            {
                tmp2.push_back(NULL);
            }
            tmp.push_back(tmp2);
        }
        roomDesign.push_back(tmp);
    }
}
Room::Room(vector<vector<vector<GameObject*>>> room) : width(room.size()), height(room[0].size()), depth(room[0][0].size())
{ 
    for (int i = 0; i < room.size(); ++i)
    {
        vector<vector<GameObject*>>  tmp;
        for (int j = 0; j < room[i].size(); ++j)
        {
            vector<GameObject*> tmp2;
            for (int k = 0; k < room[i][j].size(); ++k)
            {
                GameObject* g = room[i][j][k];
                if (g != NULL)
                    g = g->clone();
                tmp2.push_back(g);
            }
            tmp.push_back(tmp2);
        }
        roomDesign.push_back(tmp);
    }
}
Room::Room(const Room& room) : width(room.width), height(room.height), depth(room.depth)
{
    for (int i = 0; i < room.roomDesign.size(); ++i)
    {
        vector<vector<GameObject*>>  tmp;
        for (int j = 0; j < room.roomDesign[i].size(); ++j)
        {
            vector<GameObject*> tmp2;
            for (int k = 0; k < room.roomDesign[i][j].size(); ++k)
            {
                GameObject* g = room.roomDesign[i][j][k];
                if (g != NULL)
                    g = g->clone();
                tmp2.push_back(g);
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
    if (_width < 0 || _width >= roomDesign.size() || _height < 0 || _height >= roomDesign[_width].size() || _depth < 0 || _depth >= roomDesign[_width][_height].size())
        return;
    roomDesign[_width][_height][_depth] = _object.clone();
}

GameObject* Room::getRoomElement(int _width, int _height, int _depth)
{
    if (_width < 0 || _width >= roomDesign.size() || _height < 0 || _height >= roomDesign[_width].size() || _depth < 0 || _depth >= roomDesign[_width][_height].size())
        return NULL;

    return roomDesign[_width][_height][_depth];
}