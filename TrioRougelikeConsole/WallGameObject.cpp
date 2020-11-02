#include "WallGameObject.h"

void WallGameObject::onCollide(GameObject& sender)
{
	cout << "[" << name << "] " << sender.getName() << " collided " << endl;
}

WallGameObject::WallGameObject(string Name, GraphicalSymbol Symbol) : GameObject(Name, Symbol)
{

}

GameObject* WallGameObject::clone() const
{
	return new WallGameObject(*this);
}

WallGameObject::~WallGameObject()
{
}
