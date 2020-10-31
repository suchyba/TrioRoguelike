#include "DynamicGameObject.h"

DynamicGameObject::DynamicGameObject(string Name, GraphicalSymbol Symbol) : InteractionableGameObject(Name, Symbol)
{

}

bool DynamicGameObject::onRefresh(GameObject& object)
{
    return false;
}

DynamicGameObject::~DynamicGameObject()
{
}
