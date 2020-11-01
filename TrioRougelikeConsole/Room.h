#pragma once
#include <string>
#include "GameObject.h"
#include <vector>

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
	//GameObject*** roomDesign;
	vector < vector<vector<GameObject*> >>roomDesign;

public:

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
	/// Metoda pozwalajaca zmieniaæ wybrane komórki w tablicy roomDesign.
	/// </summary>
	/// <param name="_width">D³ugoœæ obiektu</param>
	/// <param name="_height">Wysokoœæ obiektu</param>
	/// <param name="_width">G³êbokoœæ obiektu</param>
	/// <param name="_object">Obiekt w komórce[_width][_height][_depth] tablicy roomDesign</param>
	void setElementInRoom(int _width, int _height, int _depth, GameObject& _object);

	/// <summary>
	/// Metoda zwracajaca obiekt roomDesign.
	/// </summary>
	/// <param name="_width">D³ugoœæ obiektu</param>
	/// <param name="_height">Wysokoœæ obiektu</param>
	/// <param name="_depth">G³êbokoœæ obiektu</param>
	GameObject* getRoomElement(int _width, int _height, int _depth);

	~Room()
	{
		for (int i = 0; i < roomDesign.size(); i++)
		{
			for (int j = 0; j < roomDesign[i].size(); j++)
			{
				for (int k = 0; k < roomDesign[i][j].size(); k++)
				{
					delete roomDesign[i][j][k];
				}
			}
		}
	}
};

