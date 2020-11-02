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
	/// Wygl�d obiektu.
	/// </summary>
	//GameObject*** roomDesign;
	vector < vector<vector<GameObject*> >>roomDesign;

public:

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
	/// Metoda pozwalajaca zmienia� wybrane kom�rki w tablicy roomDesign.
	/// </summary>
	/// <param name="_width">D�ugo�� obiektu</param>
	/// <param name="_height">Wysoko�� obiektu</param>
	/// <param name="_width">G��boko�� obiektu</param>
	/// <param name="_object">Obiekt w kom�rce[_width][_height][_depth] tablicy roomDesign</param>
	void setElementInRoom(int _width, int _height, int _depth, GameObject& _object);

	/// <summary>
	/// Metoda zwracajaca obiekt roomDesign.
	/// </summary>
	/// <param name="_width">D�ugo�� obiektu</param>
	/// <param name="_height">Wysoko�� obiektu</param>
	/// <param name="_depth">G��boko�� obiektu</param>
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

