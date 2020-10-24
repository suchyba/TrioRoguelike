#include "WallGameObject.h"

void WallGameObject::onCollide(GameObject& sender)
{
	cout << "[" << name << "] " << sender.getName() << " collided " << endl;
}

WallGameObject::WallGameObject(string Name, GraphicalSymbol Symbol) : GameObject(Name, Symbol)
{

}
