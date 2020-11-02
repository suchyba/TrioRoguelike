#include <iostream>
#include <Windows.h>
#include "GameObject.h"
#include "CreatureGameObject.h"
#include "PlayerGameObject.h"
#include "WallGameObject.h"
#include "Colliding.h"
#include "ItemGameObject.h"
#include "EffectGameObject.h"
#include "Game.h"

using namespace std;

void draw(const GameObject*);


int main()
{
	Game::start();

	return 0;
}

void draw(const GameObject* g)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, g->getRepresentation().getColor());
	cout << g->getRepresentation().getCharSymbol() << endl;
	SetConsoleTextAttribute(hConsole, 7);
}