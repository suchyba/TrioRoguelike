#include "GraphicalSymbol.h"
#include <string>
#include "FloorGameObject.h"

FloorGameObject::FloorGameObject(string Name, GraphicalSymbol Symbol) : GameObject(Name, Symbol)
{
}

GameObject* FloorGameObject::clone() const
{
	return new FloorGameObject(*this);
}

FloorGameObject::~FloorGameObject()
{

}
