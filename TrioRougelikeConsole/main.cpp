#include <iostream>
#include <Windows.h>
#include "GameObject.h"
#include "CreatureGameObject.h"
#include "PlayerGameObject.h"
#include "WallGameObject.h"
#include "Colliding.h"
#include "ItemGameObject.h"
#include "EffectGameObject.h"

using namespace std;

void draw(const GameObject*);


int main()
{
	GameObject* test = new PlayerGameObject(10, 1, 0, 1, 10, 5, 2, 5, "Gracz", GraphicalSymbol('@', 2, 3));
	GameObject* testC = new CreatureGameObject(3, 10, 5, 0, "Ghul", GraphicalSymbol('&', 4, 0));
	GameObject* sciana = new WallGameObject("sciana", GraphicalSymbol('#', 5, 3));
	GameObject* sciana2 = new GameObject("sciana", GraphicalSymbol('$', 5, 3));

	EffectGameObject* effect = new EffectGameObject("Bum", GraphicalSymbol('*', 0, 0));
	GameObject* item = new ItemGameObject("Miecz", 20, 10, effect, GraphicalSymbol('t', 8, 0));

	draw(test);
	draw(testC);
	draw(sciana);
	draw(sciana2);
	draw(item);

	Colliding* c = dynamic_cast<Colliding*>(sciana);
	if (c != NULL)
		c->onCollide(*test);

	Colliding* c2 = dynamic_cast<Colliding*>(sciana2);
	if (c2 != NULL)
		c2->onCollide(*test);
	else
		cout << "No collision." << endl;

	PlayerGameObject* player = dynamic_cast<PlayerGameObject*>(test);
	if (player)
	{
		player->equipItem(*dynamic_cast<ItemGameObject*>(item), 0);
		Colliding* c3 = dynamic_cast<Colliding*>(testC);
		if (c3)
		{
			CreatureGameObject* creature = dynamic_cast<CreatureGameObject*>(testC);
			if (creature)
			{
				player->onAttack(*creature);
			}
		}
	}




	return 0;
}

void draw(const GameObject* g)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, g->getRepresentation().getColor());
	cout << g->getRepresentation().getCharSymbol() << endl;
	SetConsoleTextAttribute(hConsole, 7);
}